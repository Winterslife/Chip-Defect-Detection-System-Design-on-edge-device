/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-07-15 12:21:36
 * @LastEditors: Eric shixianshuo@qq.com
 * @LastEditTime: 2023-07-18 15:30:29
 * @FilePath: \bouffalo_sdk_vmg0\examples\A_work\mjpeg\mjpeg_cam_normal\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "bflb_mtimer.h"
#include "bflb_i2c.h"
#include "bflb_cam.h"
#include "bflb_mjpeg.h"
#include "image_sensor.h"
#include "board.h"
#include "jpeg_head.h"

#define BLOCK_NUM           2
#define ROW_NUM             (8 * BLOCK_NUM)
#define CAM_FRAME_COUNT_USE 50

static struct bflb_device_s *i2c0;
static struct bflb_device_s *cam0;

static struct bflb_device_s *mjpeg;

volatile uint32_t pic_count = 0;
volatile uint32_t pic_addr[CAM_FRAME_COUNT_USE] = { 0 };
volatile uint32_t pic_len[CAM_FRAME_COUNT_USE] = { 0 };

void mjpeg_isr(int irq, void *arg)
{
    uint8_t *pic;
    uint32_t jpeg_len;

    uint32_t intstatus = bflb_mjpeg_get_intstatus(mjpeg);
    if (intstatus & MJPEG_INTSTS_ONE_FRAME) {
        bflb_mjpeg_int_clear(mjpeg, MJPEG_INTCLR_ONE_FRAME);
        jpeg_len = bflb_mjpeg_get_frame_info(mjpeg, &pic);
        pic_addr[pic_count] = (uint32_t)pic;
        pic_len[pic_count] = jpeg_len;
        pic_count++;
        bflb_mjpeg_pop_one_frame(mjpeg);
        if (pic_count == CAM_FRAME_COUNT_USE) {
            bflb_cam_stop(cam0);
            bflb_mjpeg_stop(mjpeg);
        }
    }
}

uint8_t jpg_head_buf[800] = { 0 };
uint32_t jpg_head_len;

uint8_t MJPEG_QUALITY = 50;

#define SIZE_BUFFER (4 * 1024 * 1024)

void bflb_mjpeg_dump_hex(uint8_t *data, uint32_t len)
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

uint8_t scale_rgb565_to_ycbycr(uint8_t* rgb565_data, uint8_t* ycbycr_data, int width, int height, int scale_width, int scale_height) {
    int i, j;
    int index565 = 0;
    int indexycbycr = 0;
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

            // RGB 转换为 YCbCr（ITU-R BT.601 标准）
            uint8_t y = (uint8_t)(0.299f * r8 + 0.587f * g8 + 0.114f * b8);
            uint8_t cb = (uint8_t)(-0.169f * r8 - 0.331f * g8 + 0.5f * b8 + 128);
            uint8_t cr = (uint8_t)(0.5f * r8 - 0.419f * g8 - 0.081f * b8 + 128);

            // 将 YCbCr 数据写入目标数组
            ycbycr_data[indexycbycr] = y;
            ycbycr_data[indexycbycr + 1] = cb;
            ycbycr_data[indexycbycr + 2] = y;
            ycbycr_data[indexycbycr + 3] = cr;

            indexycbycr += 4;
        }
    }

    // 返回新的YCbCr格式数据的字节长度
    return indexycbycr;
}

int mjpeg_init(void)
{
    struct bflb_cam_config_s cam_config;
    struct image_sensor_config_s *sensor_config;

    board_init();
    board_dvp_gpio_init();

    board_i2c0_gpio_init();//添加——from-camera

    i2c0 = bflb_device_get_by_name("i2c0");
    cam0 = bflb_device_get_by_name("cam0");

    if (image_sensor_scan(i2c0, &sensor_config)) {
        printf("\r\nSensor name: %s\r\n", sensor_config->name);
    } else {
        printf("\r\nError! Can't identify sensor!\r\n");
        while (1) {
        }
    }

    memcpy(&cam_config, sensor_config, IMAGE_SENSOR_INFO_COPY_SIZE);
    cam_config.with_mjpeg = true;
    cam_config.input_source = CAM_INPUT_SOURCE_DVP;
    cam_config.output_format = CAM_OUTPUT_FORMAT_AUTO;
    cam_config.output_bufaddr = BFLB_PSRAM_BASE;
    cam_config.output_bufsize = cam_config.resolution_x * 2 * ROW_NUM;

    bflb_cam_init(cam0, &cam_config);
    bflb_cam_start(cam0);

    mjpeg = bflb_device_get_by_name("mjpeg");

    struct bflb_mjpeg_config_s mjpeg_config;

    mjpeg_config.format = MJPEG_FORMAT_YUV422_YUYV;
    mjpeg_config.quality = MJPEG_QUALITY;
    mjpeg_config.rows = ROW_NUM;
    mjpeg_config.resolution_x = cam_config.resolution_x;
    mjpeg_config.resolution_y = cam_config.resolution_y;
    mjpeg_config.input_bufaddr0 = (uint32_t)BFLB_PSRAM_BASE;
    mjpeg_config.input_bufaddr1 = 0;
    mjpeg_config.output_bufaddr = (uint32_t)BFLB_PSRAM_BASE + cam_config.resolution_x * 2 * ROW_NUM;
    mjpeg_config.output_bufsize = SIZE_BUFFER - cam_config.resolution_x * 2 * ROW_NUM;
    mjpeg_config.input_yy_table = NULL; /* use default table */
    mjpeg_config.input_uv_table = NULL; /* use default table */

    bflb_mjpeg_init(mjpeg, &mjpeg_config);

    jpg_head_len = JpegHeadCreate(YUV_MODE_422, MJPEG_QUALITY, cam_config.resolution_x, cam_config.resolution_y, jpg_head_buf);
 
    bflb_mjpeg_fill_jpeg_header_tail(mjpeg, jpg_head_buf, jpg_head_len);

    bflb_mjpeg_tcint_mask(mjpeg, false);
    bflb_irq_attach(mjpeg->irq_num, mjpeg_isr, NULL);
    bflb_irq_enable(mjpeg->irq_num);

    bflb_mjpeg_start(mjpeg);

    while (pic_count < CAM_FRAME_COUNT_USE) {
        printf("pic count:%d\r\n", pic_count);
        bflb_mtimer_delay_ms(200);
    }


    bflb_irq_disable(mjpeg->irq_num);
    //for (uint8_t i = 0; i < CAM_FRAME_COUNT_USE; i++) {
    for (uint8_t i = 2; i < 3; i++) {
        printf("jpg addr:%08x ,jpg size:%d\r\n", pic_addr[i], pic_len[i]);
        //pic_len[i] = scale_rgb565_to_ycbycr(pic_addr[i-1], pic_addr[i], cam_config.resolution_x, cam_config.resolution_y, 110, 110);
        
        bflb_mjpeg_dump_hex((uint8_t *)pic_addr[i], pic_len[i]);
    }

    while (1) {
        bflb_mtimer_delay_ms(1000);
    }
}





//intention: 
//要修改 bsp -> common -> image_sensor -> gc0308.h
//129行打开注释Y Cb Y Cr， 注释130行RGB565