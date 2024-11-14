/*
 * @Author: Eric shixianshuo@qq.com
 * @Date: 2023-07-23 16:03:19
 * @LastEditors: Eric shixianshuo@qq.com
 * @LastEditTime: 2023-07-27 05:02:45
 * @FilePath: \bouffalo_sdk_vmg0\examples\A_work\lvgl\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "mem.h"

#include <lwip/tcpip.h>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

#include "bl_fw_api.h"
#include "wifi_mgmr_ext.h"
#include "wifi_mgmr.h"

#include "bflb_irq.h"
#include "bflb_uart.h"

#include "bl616_glb.h"
#include "rfparam_adapter.h"

#include "shell.h"

#define DBG_TAG "MAIN"
#include "log.h"
#include "board.h"
#include "bflb_gpio.h"
#include "bflb_l1c.h"
#include "bflb_mtimer.h"




int main(void)
{
    board_init();
    
    filesystem_init();

    /* shell任务 5 */
    /* shell_exec_task 4 */
    shell_init_with_task( bflb_device_get_by_name("uart0") );

    /* wifi任务 16 */
    tcpip_init(NULL, NULL);
    wifi_start_firmware_task();

    /* lvgl任务 1 5 */
    lvgl_start_firmware_task();

    /* cam任务 init 3 start 2*/
    cam_start_firmware_task();

    // shell_exec_command("wifi_sta_connect Mk 12345678");

    vTaskStartScheduler();

    
    while (1) {
    }
}
