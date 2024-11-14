#include "bflb_mtimer.h"
#include "board.h"
#include "lcd_conf_user.h"
#include "lcd.h"

#include "bflb_irq.h"
#include "bflb_uart.h"
#include "bflb_i2c.h"
#include "bflb_cam.h"
#include "image_sensor.h"

#include "bl616_glb.h"
#include "bflb_dma.h"



#define CROP_WQVGA_X        (240)
#define CROP_WQVGA_Y        (240)//(320)//
#define CAM_BUFF_NUM        (4)

///---------------------------------------------------------------------------------------------------------------------------------------------AI
#include "bflb_mtimer.h"

//选择模型
#define MODEL_FACE_DETECTION    7

#define CONFIG_MODEL MODEL_FACE_DETECTION   

#define main ai_face_main
#if (CONFIG_MODEL == MODEL_FACE_DETECTION)
#include "maixhub_face_detection/main.c"
#endif
#undef main

//定义AI识别的图像大小
#define PIC_AI_X        (110)
#define PIC_AI_Y        (110)
#define PIC_AI_C        (3)
uint8_t pic_ai[PIC_AI_X * PIC_AI_Y * PIC_AI_C];
extern char ai_face_result[32];//识别结果

// yuyv422 转 rgb565
static int __s_r_1370705v[256] = { 0 }; 
static int __s_b_1732446u[256] = { 0 }; 
static int __s_g_337633u[256] = { 0 }; 
static int __s_g_698001v[256] = { 0 }; 

void inityuyv2rgb_table(void)
{ 
    for (int i = 0; i < 256; i++)
    { 
        __s_r_1370705v[i] = (1.370705 * (i - 128)); 
        __s_b_1732446u[i] = (1.732446 * (i - 128)); 
        __s_g_337633u[i] = (0.337633 * (i - 128)); 
        __s_g_698001v[i] = (0.698001 * (i - 128)); 
    } 
} 

void yuyv2rgb565(void *input, void *output, uint32_t len) 
{ // 
    inityuyv2rgb_table(); 
    int y0, u, y1, v; 
    uint8_t r, g, b; 
    int val; 
    for (uint32_t i = 0; i < len / 4; i++) 
    { 
        y0 = (int)(((uint8_t *)input)[i * 4 + 0]); 
        u = (int)(((uint8_t *)input)[i * 4 + 1]); 
        y1 = (int)(((uint8_t *)input)[i * 4 + 2]); 
        v = (int)(((uint8_t *)input)[i * 4 + 3]); 
        val = y0 + __s_r_1370705v[v]; 
        r = (val < 0) ? 0 : ((val > 255) ? 255 : (uint8_t)val); 
        val = y0 - __s_g_337633u[u] - __s_g_698001v[v]; 
        g = (val < 0) ? 0 : ((val > 255) ? 255 : (uint8_t)val); 
        val = y0 + __s_b_1732446u[u]; 
        b = (val < 0) ? 0 : ((val > 255) ? 255 : (uint8_t)val); 
        ((uint16_t *)output)[i * 2] = (uint16_t)(b >> 3) | ((uint16_t)(g >> 2) << 5) | ((uint16_t)(r >> 3) << 11); 
        val = y1 + __s_r_1370705v[v]; 
        r = (val < 0) ? 0 : ((val > 255) ? 255 : (uint8_t)val); 
        val = y1 - __s_g_337633u[u] - __s_g_698001v[v]; 
        g = (val < 0) ? 0 : ((val > 255) ? 255 : (uint8_t)val); 
        val = y1 + __s_b_1732446u[u]; 
        b = (val < 0) ? 0 : ((val > 255) ? 255 : (uint8_t)val); 
        ((uint16_t *)output)[i * 2 + 1] = (uint16_t)(b >> 3) | ((uint16_t)(g >> 2) << 5) | ((uint16_t)(r >> 3) << 11); 
    } 
}

// rgb565 转 rgb888
void scale_rgb565_to_rgb888(uint8_t* rgb565_data, uint8_t* rgb888_data, int width, int height, int scale_width, int scale_height, bool endian) {// 大端0 小端1
    int i, j;
    int index565 = 0;
    int index888 = 0;
    float x_ratio = (float)width / scale_width;
    float y_ratio = (float)height / scale_height;

    for (i = 0; i < scale_height; i++) {
        for (j = 0; j < scale_width; j++) {
            int px = (int)(j * x_ratio);
            int py = (int)(i * y_ratio);
            
            uint16_t color565;
            if(endian)//LSB
                color565 = (rgb565_data[(py * width + px) * 2] << 8) | rgb565_data[(py * width + px) * 2 + 1];
            else//MSB
                color565 = (rgb565_data[(py * width + px) * 2 + 1] << 8) | rgb565_data[(py * width + px) * 2];
            

            uint8_t r8 = (color565 & 0xF800) >> 11;
            uint8_t g8 = (color565 & 0x07E0) >> 5;
            uint8_t b8 = color565 & 0x001F;

            rgb888_data[index888] = (r8 << 3) | (r8 >> 2);
            rgb888_data[index888 + 1] = (g8 << 2) | (g8 >> 4);
            rgb888_data[index888 + 2] = (b8 << 3) | (b8 >> 2);

            index888 += 3;
        }
    }
}
///---------------------------------------------------------------------------------------------------------------------------------------------end ai



///---------------------------------------------------------------------------------------------------------------------------------------------freertos
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"


///---------------------------------------------------------------------------------------------------------------------------------------------end freertos

// cam
uint8_t *pic;
static uint8_t picture[CROP_WQVGA_X * CROP_WQVGA_Y * CAM_BUFF_NUM] ATTR_NOINIT_PSRAM_SECTION __attribute__((aligned(64)));
static uint8_t picreg [CROP_WQVGA_X * CROP_WQVGA_Y * CAM_BUFF_NUM] ATTR_NOINIT_PSRAM_SECTION __attribute__((aligned(64)));

static struct bflb_device_s *i2c0;
static struct bflb_device_s *cam0;    
struct bflb_cam_config_s cam_config;
struct image_sensor_config_s *sensor_config;
uint32_t i, j, pic_size;


void cam_g0_init(void)
{
    lcd_init();
    lcd_clear(0x0000);

    // Cam test

    board_dvp_gpio_init();
    board_i2c0_gpio_init();

    i2c0 = bflb_device_get_by_name("i2c0");
    cam0 = bflb_device_get_by_name("cam0");

    if (image_sensor_scan(i2c0, &sensor_config)) {
        printf("\r\nSensor name: %s\r\n", sensor_config->name);
    } else {
        printf("\r\nError! Can't identify sensor!\r\n");
        while (1) {
        }
    }

    /* Crop resolution_x, should be set before init */
    bflb_cam_crop_hsync(cam0, 112, 112 + CROP_WQVGA_X);
    /* Crop resolution_y, should be set before init */
    bflb_cam_crop_vsync(cam0, 120, 120 + CROP_WQVGA_Y);

    memcpy(&cam_config, sensor_config, IMAGE_SENSOR_INFO_COPY_SIZE);
    cam_config.with_mjpeg = false;
    cam_config.input_source = CAM_INPUT_SOURCE_DVP;
    cam_config.output_format = CAM_OUTPUT_FORMAT_AUTO;
    cam_config.output_bufaddr = (uint32_t)picture;
    cam_config.output_bufsize = CROP_WQVGA_X * CROP_WQVGA_Y * (CAM_BUFF_NUM / 2);

    bflb_cam_init(cam0, &cam_config);
    bflb_cam_start(cam0);

	lcd_set_dir(2,1);//显示旋转180度。
}

bool cam_g0_flag = 1;
bool ai_face_flag = 1;

uint32_t mqtt_init_flag;

void cam_g0_ai_face(void* param)
{
    j = 0;
    while (1) {
        // CAM test
        if (bflb_cam_get_frame_count(cam0) > 0) {
            j ++;
            
            // bflb_cam_stop(cam0);
            pic_size = bflb_cam_get_frame_info(cam0, &pic);
            bflb_cam_pop_one_frame(cam0);

            //printf("pop picture %d: 0x%08x, len: %d\r\n", j, (uint32_t)pic, pic_size);
            
            yuyv2rgb565(pic, picreg, pic_size);

            if(j > 2)
            {
                j = 0;
                i++;
                
                lcd_draw_picture_nonblocking(0,0,CROP_WQVGA_X,CROP_WQVGA_Y, picreg);

            }

            if(!ai_face_flag)
            {
                continue;
            }

            if(i > 10)
            {
                i = 0;

                if(mqtt_init_flag++ == 5)
                {
                    shell_exec_command("mqtt_pub");
                }

                scale_rgb565_to_rgb888(picreg, pic_ai, CROP_WQVGA_X, CROP_WQVGA_Y, PIC_AI_X, PIC_AI_Y, 0);
                
                ai_face_main(pic_ai);


                lcd_draw_str_ascii16(50, 250, 0xFA60, 0x0000, ai_face_result, strlen(ai_face_result));
                


            }
            
        }

        // 主动让出处理器给其他任务
        vTaskDelay(pdMS_TO_TICKS(20)); // 延时 10 毫秒
    }

    vTaskDelete(NULL);

}

static TaskHandle_t cam_face_ai_task_handle;
void ai_face_init_with_task(void)
{
    cam_g0_init();
    xTaskCreate(cam_g0_ai_face, (char *)"face_ai", 2000, NULL, 5, &cam_face_ai_task_handle);

}




#ifdef CONFIG_SHELL
#include <shell.h>

int cmd_cam_g0_off(int argc, char **argv)
{
    cam_g0_flag = 0;
    vTaskSuspend(cam_face_ai_task_handle);

    return 0;
}
int cmd_cam_g0_on(int argc, char **argv)
{
    cam_g0_flag = 1;
    vTaskResume(cam_face_ai_task_handle);
    return 0;
}

SHELL_CMD_EXPORT_ALIAS(cmd_cam_g0_off, cam_g0_off, cam_g0_off);
SHELL_CMD_EXPORT_ALIAS(cmd_cam_g0_on, cam_g0_on, cam_g0_on);

int cmd_ai_face_off(int argc, char **argv)
{
    ai_face_flag = 0;

    return 0;
}
int cmd_ai_face_on(int argc, char **argv)
{
    ai_face_flag = 1;

    return 0;
}

SHELL_CMD_EXPORT_ALIAS(cmd_ai_face_off, ai_face_off, ai_face_off);
SHELL_CMD_EXPORT_ALIAS(cmd_ai_face_on, ai_face_on, ai_face_on);
#endif


///---------------------------------------------------------------------------------------------------------------------------------------------mjpeg
// #include "bflb_mjpeg.h"
// #include "jpeg_head.h"


// #define MJPEG_QUALITY       50

// static struct bflb_device_s *mjpeg;
// struct bflb_mjpeg_config_s mjpeg_config;

// uint8_t* pic_mjpeg;

// uint32_t jpeg_len;


// uint8_t jpg_head_buf[800] = { 0 };
// uint32_t jpg_head_len;

// void mjpeg_init(void)
// {
//     mjpeg = bflb_device_get_by_name("mjpeg");


//     mjpeg_config.format = MJPEG_FORMAT_YUV422_YUYV;
//     mjpeg_config.quality = MJPEG_QUALITY;
//     mjpeg_config.rows = PIC_AI_Y;
//     mjpeg_config.resolution_x = PIC_AI_X;
//     mjpeg_config.resolution_y = PIC_AI_Y;
//     mjpeg_config.input_bufaddr0 = pic_ai;
//     mjpeg_config.input_bufaddr1 = 0;
//     mjpeg_config.output_bufaddr = pic_mjpeg;
//     mjpeg_config.output_bufsize = PIC_AI_X * 3 * PIC_AI_Y;
//     mjpeg_config.input_yy_table = NULL; /* use default table */
//     mjpeg_config.input_uv_table = NULL; /* use default table */

//     bflb_mjpeg_init(mjpeg, &mjpeg_config);

//     jpg_head_len = JpegHeadCreate(YUV_MODE_422, MJPEG_QUALITY, cam_config.resolution_x, cam_config.resolution_y, jpg_head_buf);

//     bflb_mjpeg_fill_jpeg_header_tail(mjpeg, jpg_head_buf, jpg_head_len);

//     bflb_mjpeg_tcint_mask(mjpeg, false);

//     bflb_mjpeg_start(mjpeg);
// }


// void bflb_mjpeg_dump_hex(uint8_t *data, uint32_t len)
// {
//     uint32_t i = 0;

//     for (i = 0; i < len; i++) {
//         if (i % 16 == 0) {
//             printf("\r\n");
//         }

//         printf("%02x ", data[i]);

//         bflb_mtimer_delay_ms(1);
//     }

//     printf("\r\n");
// }




// #ifdef CONFIG_SHELL
// #include <shell.h>

// int cmd_mjpeg_pic(int argc, char **argv)
// {
//     mjpeg_init();
//     jpeg_len = bflb_mjpeg_get_frame_info(mjpeg, pic_mjpeg);
//     bflb_mjpeg_dump_hex(pic_mjpeg, jpeg_len);

//     return 0;
// }

// SHELL_CMD_EXPORT_ALIAS(cmd_mjpeg_pic, mjpeg_pic, mjpeg pic);
// #endif


void bflb_rgb565_dump_hex(uint8_t *data, uint32_t len)
{
    uint32_t i = 0;

    for (i = 0; i < len; i++) {
        if (i % 16 == 0) {
            printf("\r\n");
        }

        printf("%02x ", data[i]);

        bflb_mtimer_delay_ms(1);
    }

    printf("\r\n");
}

#ifdef CONFIG_SHELL
#include <shell.h>

int cmd_rgb565_pic(int argc, char **argv)
{
    vTaskSuspend(cam_face_ai_task_handle);
    bflb_rgb565_dump_hex(pic, pic_size);
    vTaskResume(cam_face_ai_task_handle);
    return 0;
}

SHELL_CMD_EXPORT_ALIAS(cmd_rgb565_pic, rgb565_pic, rgb565 pic);
#endif
