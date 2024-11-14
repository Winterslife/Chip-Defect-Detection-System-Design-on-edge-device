#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "mem.h"


#include "board.h"
#include "bflb_gpio.h"
#include "bflb_l1c.h"
#include "bflb_mtimer.h"

#include "lv_conf.h"
#include "lvgl.h"

#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "lcd.h"

//cam
#include "bflb_i2c.h"
#include "bflb_cam.h"
#include "image_sensor.h"

#include "bl616_glb.h"
#include "bflb_dma.h"
#include "bflb_i2s.h"

#include "src/ui/my_ui/ui.h"

/* cam任务函数 */
TaskHandle_t camera_init_task_handle = NULL;
TaskHandle_t camera_start_task_handle = NULL;

//set x and y
#define CROP_WQVGA_X        (240)
#define CROP_WQVGA_Y        (240)
#define CAM_BUFF_NUM        (4)


/*定义全局变量*/
lv_obj_t *avatar ;
uint32_t pic_size;
uint8_t *pic;
uint32_t i, j;

//pic全局变量
uint8_t picreg[CROP_WQVGA_X * CROP_WQVGA_Y * CAM_BUFF_NUM] ATTR_NOINIT_PSRAM_SECTION __attribute__((aligned(64)));

lv_img_dsc_t img_src_cam = {
        .header.always_zero = 0,
        .header.w = CROP_WQVGA_X,
        .header.h = CROP_WQVGA_Y,
        .data_size = CROP_WQVGA_X * CROP_WQVGA_Y * (CAM_BUFF_NUM / 2),
        .header.cf = LV_IMG_CF_TRUE_COLOR,
    };

//picture yuyv setting 
struct bflb_device_s *i2c0;
struct bflb_device_s *cam0;


//yuyv422 转 rgb565
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

void camera_init()
{
    static uint8_t picture[CROP_WQVGA_X * CROP_WQVGA_Y * CAM_BUFF_NUM] ATTR_NOINIT_PSRAM_SECTION __attribute__((aligned(64)));
    
    struct bflb_cam_config_s cam_config;
    struct image_sensor_config_s *sensor_config;
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

    /* Crop resolution_x, should be set before init 配置摄像头的水平截取范围。*/
    bflb_cam_crop_hsync(cam0, 112, 112 + CROP_WQVGA_X);
    /* Crop resolution_y, should be set before init 配置摄像头的垂直截取范围。*/
    bflb_cam_crop_vsync(cam0, 120, 120 + CROP_WQVGA_Y);

    memcpy(&cam_config, sensor_config, IMAGE_SENSOR_INFO_COPY_SIZE);//将之前获取到的图像传感器配置信息复制到摄像头配置结构体cam_config中
    cam_config.with_mjpeg = false;//设置摄像头输出为非MJPEG格式
    cam_config.input_source = CAM_INPUT_SOURCE_DVP;//设置摄像头输入源为DVP接口
    cam_config.output_format = CAM_OUTPUT_FORMAT_AUTO;//设置摄像头输出格式
    cam_config.output_bufaddr = (uint32_t)picture;//设置摄像头输出图像数据的缓冲区地址为picture数组的地址。
    cam_config.output_bufsize = CROP_WQVGA_X * CROP_WQVGA_Y * (CAM_BUFF_NUM / 2);//设置摄像头输出图像数据的缓冲区大小
    
    //start cam
    bflb_cam_init(cam0, &cam_config);
    bflb_cam_start(cam0);
    // bflb_cam_stop(cam0);
}

//摄像头显示初始化任务
void camera_init_task(void *pvParameters) {

    //创建和配置lv_img图像控件：
    lv_obj_t *scr ;
    scr = lv_scr_act();//获取当前活动的屏幕对象

    avatar = lv_img_create(scr);//创建了一个图像控件对象，并将其添加到当前活动的屏幕对象（scr）中
   
    lv_img_set_angle(avatar, 1800);//设置图像控件的角度（如果需要旋转图像，可以通过这个函数设置)
    
    lv_obj_align(avatar, LV_ALIGN_BOTTOM_MID, -1, -1);//将图像控件居中对齐

    lv_img_set_src(avatar, &img_src_cam);//图像来源摄像头

    j = 0;


    vTaskDelay(pdMS_TO_TICKS(1000)); // 假设摄像头初始化需要1秒
    vTaskDelete(camera_init_task_handle);// 删除自身任务，任务完成
}

/* 显示人脸检测的结果 */
bool disp_face_result_flag;
char disp_face_result[32] = "wait..";
// extern lv_obj_t * ui_LabelPeople;
//摄像头显示任务
void camera_start_task(void *pvParameters)
{
    while (1) {
        if (bflb_cam_get_frame_count(cam0) > 0) 
        {
            pic_size = bflb_cam_get_frame_info(cam0, &pic);
            bflb_cam_pop_one_frame(cam0);
            //printf("pop picture %d: 0x%08x, len: %d\r\n", j++, (uint32_t)pic, pic_size);
            yuyv2rgb565(pic, picreg, pic_size);
            img_src_cam.data = picreg;
            lv_img_set_src(avatar, &img_src_cam);

            //ai_face(picreg, CROP_WQVGA_X, CROP_WQVGA_Y);

            if(disp_face_result_flag)
            {
                
                lv_label_set_text(ui_LabelPeople, disp_face_result);
            }

        }
    }
}


int cam_start_firmware_task(void)
{
    camera_init();
    xTaskCreate(camera_init_task, "Camera Init", 256, NULL, 3, &camera_init_task_handle);
    xTaskCreate(camera_start_task, "Camera Start", 2000, NULL, 2, &camera_start_task_handle); //2000  //2
    vTaskSuspend(camera_init_task_handle);
    vTaskSuspend(camera_start_task_handle);

    //lcd_set_dir(2,1);//显示旋转180度
}