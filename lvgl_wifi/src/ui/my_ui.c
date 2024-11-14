/*
 * @Author: Eric shixianshuo@qq.com
 * @Date: 2023-07-26 02:10:29
 * @LastEditors: Eric shixianshuo@qq.com
 * @LastEditTime: 2023-07-26 03:48:37
 * @FilePath: \bouffalo_sdk_vmg0\examples\A_work\lvgl_wifi\src\ui\my_ui.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "mem.h"

#include "lv_conf.h"
#include "lvgl.h"

#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "src/ui/lv_demos.h"

#include "lcd.h"


/* lvgl任务函数 */
static TaskHandle_t app_task_gui_hander;
static TaskHandle_t app_task_init_handle;

void app_task_gui()
{   
    ui_init();

	while(1)
	{
		lv_task_handler();
		vTaskDelay(5);
	}
}

void app_task_init()
{
    taskENTER_CRITICAL(); /* 进入临界区 */

	//创建ui任务
    xTaskCreate(app_task_gui,
				(char *)"app_task_gui",
				512, //2048
				NULL,
				5,
				&app_task_gui_hander);

    taskEXIT_CRITICAL(); /* 退出临界区 */

	vTaskDelete(app_task_init_handle); //删除任务自身

}

void lv_log_print_g_cb(const char *buf)
{
    printf("[LVGL] %s", buf);
}

int lvgl_start_firmware_task(void)
{
    /* lvgl init */
    lv_log_register_print_cb(lv_log_print_g_cb);

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    xTaskCreate(app_task_init, 
                (char *)"start_task", 
                1600, 
                NULL, 
                1, 
                &app_task_init_handle);
                
}


