/*
 * @Author: Eric shixianshuo@qq.com
 * @Date: 2023-07-26 21:42:35
 * @LastEditors: Eric shixianshuo@qq.com
 * @LastEditTime: 2023-07-27 05:21:47
 * @FilePath: \bouffalo_sdk_vmg0\examples\A_work\_project_ai_chip\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

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

#include "board.h"
#include "shell.h"

#define DBG_TAG "MAIN"
#include "log.h"


#include <sys/socket.h>






int main(void)
{

    board_init();
    
    //filesystem_init();

    shell_init_with_task( bflb_device_get_by_name("uart0") );

    tcpip_init(NULL, NULL);
    wifi_start_firmware_task();

    shell_exec_command("wifi_sta_connect Mk 12345678"); //上电自动联网，在shell_freertos.c里添加了这个函数20230717

    ai_chip_init_with_task();



    vTaskStartScheduler();

    while (1) {
    }
}




