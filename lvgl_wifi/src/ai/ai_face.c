/*
 * @Author: Eric shixianshuo@qq.com
 * @Date: 2023-07-25 16:41:36
 * @LastEditors: Eric shixianshuo@qq.com
 * @LastEditTime: 2023-07-27 04:50:59
 * @FilePath: \bouffalo_sdk_vmg0\examples\A_work\lvgl\src\ai\ai_face.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "board.h"

#include "bflb_irq.h"
#include "bflb_uart.h"

// 选择模型
#define MODEL_FACE_DETECTION    7

#define CONFIG_MODEL MODEL_FACE_DETECTION   

#define main ai_face_mainai_face_result
#if (CONFIG_MODEL == MODEL_FACE_DETECTION)
#include "maixhub_face_detection/main.c"
#endif
#undef main

// 定义AI识别的图像大小
#define PIC_AI_X        (110)
#define PIC_AI_Y        (110)
#define PIC_AI_C        (3)


// 定义识别结果
extern char ai_face_result[32];

// scale_rgb565_to_rgb888
void scale_rgb565_to_rgb888(uint8_t* rgb565_data, uint8_t* rgb888_data, int width, int height, int scale_width, int scale_height) {
    int i, j;
    int index565 = 0;
    int index888 = 0;
    float x_ratio = (float)width / scale_width;
    float y_ratio = (float)height / scale_height;

    for (i = 0; i < scale_height; i++) {
        for (j = 0; j < scale_width; j++) {
            int px = (int)(j * x_ratio);
            int py = (int)(i * y_ratio);
            uint16_t color565 = (rgb565_data[(py * width + px) * 2] << 8) | rgb565_data[(py * width + px) * 2 + 1];

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



int ai_face(uint8_t* rgb565_data, int in_width, int in_height)
{
    uint8_t pic_ai[PIC_AI_X * PIC_AI_Y * PIC_AI_C];
    
    scale_rgb565_to_rgb888(rgb565_data, pic_ai, in_width, in_height, PIC_AI_X, PIC_AI_Y);

    ai_face_main(pic_ai); //跑不动啊呜呜呜
}
