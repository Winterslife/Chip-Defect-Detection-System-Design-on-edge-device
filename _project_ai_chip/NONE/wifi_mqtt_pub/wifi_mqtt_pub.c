#include "FreeRTOS_POSIX.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <lwip/errno.h>
#include <netdb.h>

#include "utils_getopt.h"

#include "mqtt.h"
#include "shell.h"

uint32_t finish_send_flag;

static uint8_t sendbuf[2048]; /* sendbuf should be large enough to hold multiple whole mqtt messages */
static uint8_t recvbuf[1024]; /* recvbuf should be large enough any whole mqtt message expected to be received */

shell_sig_func_ptr abort_exec;
static TaskHandle_t client_daemon;
int send_sockfd;
const char* addr = "test.mosquitto.org";

extern const char* application_message;

/*
    A template for opening a non-blocking POSIX socket.
*/
static int open_nb_socket(const char* addr, const char* port);

static int open_nb_socket(const char* addr, const char* port) {
    struct addrinfo hints = {0};

    hints.ai_family = AF_UNSPEC; /* IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* Must be TCP */
    int sockfd = -1;
    int rv;
    struct addrinfo *p, *servinfo;

    /* get address information */
    rv = getaddrinfo(addr, port, &hints, &servinfo);
    if(rv != 0) {
        printf("Failed to open socket (getaddrinfo): %s\r\n", rv);
        return -1;
    }

    /* open the first possible socket */
    for(p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) continue;

        /* connect to server */
        rv = connect(sockfd, p->ai_addr, p->ai_addrlen);
        if(rv == -1) {
          close(sockfd);
          sockfd = -1;
          continue;
        }
        break;
    }

    /* free servinfo */
    freeaddrinfo(servinfo);

    /* make non-blocking */
    if (sockfd != -1) {
        int iMode = 1;
        ioctlsocket(sockfd, FIONBIO, &iMode);
    }

    return sockfd;
}

/**
 * @brief The function will be called whenever a PUBLISH message is received.
 */
static void publish_callback_1(void** unused, struct mqtt_response_publish *published);

/**
 * @brief The client's refresher. This function triggers back-end routines to
 *        handle ingress/egress traffic to the broker.
 *
 * @note All this function needs to do is call \ref __mqtt_recv and
 *       \ref __mqtt_send every so often. I've picked 100 ms meaning that
 *       client ingress/egress traffic will be handled every 100 ms.
 */
static void client_refresher(void* client);

/**
 * @brief Safelty closes the \p sockfd and cancels the \p client_daemon before \c exit.
 */

void test_close_sendpic()
{
    if (send_sockfd)
    {
        close(send_sockfd);
    }
    printf("mqtt_pub stop publish to %s\r\n", addr);

    vTaskDelete(client_daemon);

}

//static int example_mqtt(int argc, const char *argv[])
 static int example_mqtt(char* port, char* topic)
{
    int ret = 0;
    
    port = "1883";

    topic = "bl618";

    /* open the non-blocking TCP socket (connecting to the broker) */
    send_sockfd = open_nb_socket(addr, port);

    if (send_sockfd < 0) {
        printf("Failed to open socket: %d\r\n", send_sockfd);
        test_close_sendpic(SHELL_SIGINT);
    }

    /* setup a client */
    struct mqtt_client client;

    mqtt_init(&client, send_sockfd, sendbuf, sizeof(sendbuf), recvbuf, sizeof(recvbuf), publish_callback_1);
    /* Create an anonymous session */
    const char* client_id = NULL;
    /* Ensure we have a clean session */
    uint8_t connect_flags = MQTT_CONNECT_CLEAN_SESSION;
    /* Send connection request to the broker. */
    ret = mqtt_connect(&client, client_id, NULL, NULL, 0, NULL, NULL, connect_flags, 400);
    if (ret != MQTT_OK)
    {
        printf("fail to connect mqtt\r\n");
    }

    /* check that we don't have any errors */
    if (client.error != MQTT_OK) {
        printf("error: %s\r\n", mqtt_error_str(client.error));
        test_close_sendpic(SHELL_SIGINT);
    }

    /* start a thread to refresh the client (handle egress and ingree client traffic) */
    xTaskCreate(client_refresher, (char*)"client_ref", 1024,  &client, 16, &client_daemon);

    printf("Press CTRL-C to exit.\r\n");

    /* block wait CTRL-C exit */

    /* 定义一个变量来存储application_message的长度 */ 
    int len = strlen(application_message) + 1; 
    // 定义一个变量来存储每次发送的数据长度 / 
    int chunk = 1500; 
    // 定义一个变量来存储当前发送的位置  
    uint32_t pos = 0; 
    // 使用一个循环，直到application_message发送完毕 /
    while (pos < len) { 
        // 计算剩余的数据长度 /
        int remain = len - pos;
        //如果剩余的数据长度小于每次发送的数据长度，就使用剩余的数据长度 
        if (remain < chunk) { chunk = remain; } 
        /* 调用mqtt_publish函数，使用application_message中从pos开始，长度为chunk的数据 */ 
        mqtt_publish(&client, topic, application_message + pos, chunk, MQTT_PUBLISH_QOS_0); 
        mqtt_sync(&client);
        bflb_mtimer_delay_ms(1000);
        /* 更新当前发送的位置 */ 
        pos += chunk; 
        printf("remian: %d \r\n", remain);
    
    }
    //mqtt_publish(&client, topic, application_message, strlen(application_message) + 1, MQTT_PUBLISH_QOS_0);

    /* check for errors */
    if (client.error != MQTT_OK) {
        printf("error: %s\r\n", mqtt_error_str(client.error));
        test_close_sendpic(SHELL_SIGINT);
    }
    vTaskDelay(3000);


    printf("Finished chou!");

    finish_send_flag = 1;
    
    /* disconnect */
    /* exit */
    
    test_close_sendpic(SHELL_SIGINT);//不能删除

    
}

static void publish_callback_1(void** unused, struct mqtt_response_publish *published)
{
    /* not used in this example */
}

static void client_refresher(void* client)
{
    while(1)
    {
        mqtt_sync((struct mqtt_client*) client);
        vTaskDelay(10);
    }

}

#ifdef CONFIG_SHELL
#include <shell.h>

extern uint32_t wifi_state;
static int check_wifi_state(void)
{
    if (wifi_state == 1)
    {
        return 0;
    } else {
        return 1;
    }
}

int cmd_mqtt_publisher(int argc, const char **argv)
{
    uint32_t ret = 0;
    
    ret = check_wifi_state();
    if (ret != 0) {
        printf("your wifi not connected!\r\n");
        return 0;
    }

    
    // xTaskCreate(example_mqtt,(char*)"test_mqtt", 8192, argv, 10, NULL);
    example_mqtt("1883", "bl618");


    return 0;
}

SHELL_CMD_EXPORT_ALIAS(cmd_mqtt_publisher, mqtt_pub, mqtt publisher);
#endif
