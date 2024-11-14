/* freertos */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

#include "shell.h"
/* lcd */
#include "bflb_mtimer.h"
#include "board.h"
#include "lcd_conf_user.h"
#include "lcd.h"

#define CROP_WQVGA_X        (110)//240
#define CROP_WQVGA_Y        (110)//(320)//
#define CAM_BUFF_NUM        (4)

/* tinymaix */
#include "bflb_mtimer.h"

//选择模型
#define MODEL_CHIP_DETECTION    8

#define CONFIG_MODEL MODEL_CHIP_DETECTION   

#define main ai_chip_main
#if (CONFIG_MODEL == MODEL_CHIP_DETECTION)
#include "maixhub_chip_detection/main.c"
#endif
#undef main

//定义AI识别的图像大小
#define PIC_AI_X        (110)
#define PIC_AI_Y        (110)
#define PIC_AI_C        (3)
uint8_t *pic_ai;


extern char ai_chip_result[32];//识别结果

///---------------------------------------------------------------------------------------------------------------------------------------------


void scale_rgb888_to_rgb565(uint8_t* rgb888_data, uint8_t* rgb565_data, int width, int height, int scale_width, int scale_height, bool endian) {
    int i, j;
    int index565 = 0;
    int index888 = 0;
    float x_ratio = (float)width / scale_width;
    float y_ratio = (float)height / scale_height;

    for (i = 0; i < scale_height; i++) {
        for (j = 0; j < scale_width; j++) {
            int px = (int)(j * x_ratio);
            int py = (int)(i * y_ratio);

            uint8_t r8 = (rgb888_data[(py * width + px) * 3] >> 3);
            uint8_t g8 = (rgb888_data[(py * width + px) * 3 + 1] >> 2);
            uint8_t b8 = (rgb888_data[(py * width + px) * 3 + 2] >> 3);

            uint16_t color565 = (r8 << 11) | (g8 << 5) | b8;

            if (endian) { // LSB
                rgb565_data[index565] = color565 & 0xFF;
                rgb565_data[index565 + 1] = (color565 >> 8) & 0xFF;
            } else { // MSB
                rgb565_data[index565] = (color565 >> 8) & 0xFF;
                rgb565_data[index565 + 1] = color565 & 0xFF;
            }

            index565 += 2;
        }
    }
}


void scale_rgb888(uint8_t* input, uint8_t* output, int width, int height, int scale_width, int scale_height) {
    int i, j;
    int pixel_size = 3; // RGB888为每个像素占用3个字节
    float x_ratio = (float)width / scale_width;
    float y_ratio = (float)height / scale_height;

    for (i = 0; i < scale_height; i++) {
        for (j = 0; j < scale_width; j++) {
            int px = (int)(j * x_ratio);
            int py = (int)(i * y_ratio);

            int input_index = (py * width + px) * pixel_size;
            int output_index = (i * scale_width + j) * pixel_size;

            output[output_index] = input[input_index]; // Red
            output[output_index + 1] = input[input_index + 1]; // Green
            output[output_index + 2] = input[input_index + 2]; // Blue
        }
    }
}

uint8_t picreg [CROP_WQVGA_X * CROP_WQVGA_Y * CAM_BUFF_NUM] ATTR_NOINIT_PSRAM_SECTION __attribute__((aligned(64)));


/* mqtt */
extern volatile uint32_t wifi_state;
bool mqtt_sub_1_flag;
extern struct mqtt_client client;
extern char recv_command[32];
extern bool recv_cmd_flag;
extern const char* pic_269;

/* ai chip detect */
#define dyw         1
#define biankuang   2
#define huashang    3

uint8_t ai_chip_flag = 0;

extern const unsigned char pic_dyw_57[110*110*3];
extern const unsigned char pic_biankuang_241[110*110*3];
extern const unsigned char pic_huashang_338[110*110*3];


void ai_chip_task(void* param)
{
    while(1)
    {
        // 主动让出处理器给其他任务
        vTaskDelay(pdMS_TO_TICKS(20)); // 延时 10 毫秒

        if(wifi_state & !mqtt_sub_1_flag)
        {
            lcd_draw_str_ascii16(50, 250, 0xFA60, 0x0000, "wait command", strlen("wait command"));

            mqtt_sub_1_flag = 1;
            
            /* mqtt init */
            mqtt_init_with_task();

            /* subscribe */
            char* topic = "[command]";
            mqtt_subscribe(&client, topic, 0);// mqtt_unsubscribe(&client, topic);
            printf("\r\nlistening for '%s' messages.\r\n", topic);
        }

        if(recv_cmd_flag)
        {
            if(strcmp(recv_command, "detect_000001.jpg") == 0)
                ai_chip_flag = dyw;
            else if(strcmp(recv_command, "detect_000002.jpg") == 0)
                ai_chip_flag = biankuang;
            else if(strcmp(recv_command, "detect_000003.jpg") == 0)
                ai_chip_flag = huashang;
            else if(strcmp(recv_command, "send_000001.jpg") == 0)
            {
                lcd_draw_str_ascii16(50, 250, 0xFA60, 0x0000, recv_command, strlen(recv_command));

                /* unsubscribe */
                mqtt_unsubscribe(&client, "[command]");
                
                send_pic_large(pic_269, "bl618");

                /* subscribe */
                char* topic = "[command]";
                mqtt_subscribe(&client, topic, 0);
                // mqtt_unsubscribe(&client, topic);
                printf("\r\nlistening for '%s' messages.\r\n", topic);
                
            }
            else if(strcmp(recv_command, "send_000002.jpg") == 0)
            {
                // lcd_draw_str_ascii16(50, 250, 0xFA60, 0x0000, recv_command, strlen(recv_command));

                // mqtt_unsubscribe(&client, "[command]");
                
                // send_pic_large(pic_269, "bl618");

                // /* subscribe */
                // char* topic = "[command]";
                // mqtt_subscribe(&client, topic, 0);
                // // mqtt_unsubscribe(&client, topic);
                // printf("\r\nlistening for '%s' messages.\r\n", topic);
                
            }

            recv_cmd_flag = 0;
        }

        if(!ai_chip_flag)
        {
            continue;
        }
        printf("ai_chip_flag: %d\r\n",ai_chip_flag);   

        uint16_t x1 = 65;
        uint16_t y1 = 45;
        uint16_t x2 = x1 + CROP_WQVGA_X - 1;
        uint16_t y2 = y1 + CROP_WQVGA_Y - 1;

        if(ai_chip_flag == dyw)
        {
            scale_rgb888_to_rgb565(pic_dyw_57, picreg, PIC_AI_X, PIC_AI_Y, CROP_WQVGA_X, CROP_WQVGA_Y, 1);  
            lcd_draw_picture_nonblocking(x1, y1, x2, y2, (lcd_color_t *)picreg);
            ai_chip_main(pic_dyw_57);
            lcd_draw_str_ascii16(50, 250, 0xFA60, 0x0000, ai_chip_result, strlen(ai_chip_result));
        }
        else if(ai_chip_flag == biankuang)
        {
            scale_rgb888_to_rgb565(pic_biankuang_241, picreg, PIC_AI_X, PIC_AI_Y, CROP_WQVGA_X, CROP_WQVGA_Y, 1);  
            lcd_draw_picture_nonblocking(x1, y1, x2, y2, (lcd_color_t *)picreg);
            ai_chip_main(pic_biankuang_241);
            lcd_draw_str_ascii16(50, 250, 0xFA60, 0x0000, ai_chip_result, strlen(ai_chip_result));
        }
        else if(ai_chip_flag == huashang)
        {
            scale_rgb888_to_rgb565(pic_huashang_338, picreg, PIC_AI_X, PIC_AI_Y, CROP_WQVGA_X, CROP_WQVGA_Y, 1);  
            lcd_draw_picture_nonblocking(x1, y1, x2, y2, (lcd_color_t *)picreg);
            ai_chip_main(pic_huashang_338);
            lcd_draw_str_ascii16(50, 250, 0xFA60, 0x0000, ai_chip_result, strlen(ai_chip_result));
        }

        ai_chip_flag = 0;
            

    }

    vTaskDelete(NULL);
}


static TaskHandle_t ai_chip_task_handle;
void ai_chip_init_with_task(void)
{
    lcd_init();
    lcd_clear(0x0000);
	lcd_set_dir(2,1);//显示旋转180度。

    //lcd_draw_str_ascii16(50, 280, 0xFA60, 0x0000, "CHIP DETECT", strlen("CHIP DETECT"));

    xTaskCreate(ai_chip_task, (char *)"ai_chip", 3000, NULL, 5, &ai_chip_task_handle);

}



#ifdef CONFIG_SHELL
#include <shell.h>

int detect_dyw(int argc, char **argv)
{
    ai_chip_flag = dyw;
    return 0;
}
SHELL_CMD_EXPORT_ALIAS(detect_dyw, detect_dyw, detect_dyw);

int detect_biankuang(int argc, char **argv)
{
    ai_chip_flag = biankuang;
    return 0;
}
SHELL_CMD_EXPORT_ALIAS(detect_biankuang, detect_biankuang, detect_biankuang);

int detect_huashang(int argc, char **argv)
{
    ai_chip_flag = huashang;
    return 0;
}
SHELL_CMD_EXPORT_ALIAS(detect_huashang, detect_huashang, detect_huashang);

#endif
