
/**
 * @file
 * A simple program that subscribes to a topic.
 */
#include "FreeRTOS_POSIX.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <lwip/errno.h>
#include <netdb.h>

#include "utils_getopt.h"

#include "mqtt.h"
#include "shell.h"


char recv_command[32];
bool recv_cmd_flag = 0;

uint8_t sendbuf[2048]; /* sendbuf should be large enough to hold multiple whole mqtt messages */
uint8_t recvbuf[1024]; /* recvbuf should be large enough any whole mqtt message expected to be received */

static TaskHandle_t client_daemon;
struct mqtt_client client;
int mqtt_sockfd;
const char* addr;

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
void mqtt_close()
{
    if (mqtt_sockfd)
    {
        close(mqtt_sockfd);
    }
    printf("mqtt disconnecting from %s\r\n", addr);

    vTaskDelete(client_daemon); //关闭的关键
}



void mqtt_init_with_task()
{
    const char* port = "1883";


    int ret = 0;


    addr = "test.mosquitto.org";

    /* open the non-blocking TCP socket (connecting to the broker) */
    mqtt_sockfd = open_nb_socket(addr, port);

    if (mqtt_sockfd < 0) {
        printf("Failed to open socket: %d\r\n", mqtt_sockfd);
        mqtt_close();
    }

    /* setup a client */


    mqtt_init(&client, mqtt_sockfd, sendbuf, sizeof(sendbuf), recvbuf, sizeof(recvbuf), publish_callback_1);
    /* Create an anonymous session */
    const char* client_id = NULL;
    /* Ensure we have a clean session */
    uint8_t connect_flags = MQTT_CONNECT_CLEAN_SESSION;
    /* Send connection request to the broker. */
    ret = mqtt_connect(&client, client_id, NULL, NULL, 0, NULL, NULL, connect_flags, 400);

    if (ret != MQTT_OK)
    {
        printf("fail to connect mqtt \r\n");
    }
    /* check that we don't have any errors */
    if (client.error != MQTT_OK) {
        printf("error: %s\r\n", mqtt_error_str(client.error));
        mqtt_close();
    }

    /* start a thread to refresh the client (handle egress and ingree client traffic) */
    xTaskCreate(client_refresher, (char*)"client_ref", 1024,  &client, 10, &client_daemon);

}

static void publish_callback_1(void** unused, struct mqtt_response_publish *published)
{
    /* note that published->topic_name is NOT null-terminated (here we'll change it to a c-string) */
    char* topic_name = (char*) malloc(published->topic_name_size + 1);
    memcpy(topic_name, published->topic_name, published->topic_name_size);
    topic_name[published->topic_name_size] = '\0';

    char* topic_msg = (char*) malloc(published->application_message_size + 1);
    memcpy(topic_msg, published->application_message, published->application_message_size);
    topic_msg[published->application_message_size] = '\0';

    printf("Received publish('%s'): %s\r\n", topic_name, topic_msg);


    /* recv_command */
    sprintf(recv_command, "%s", topic_msg, strlen(topic_msg));
    recv_cmd_flag = 1;    


    free(topic_name);
    free(topic_msg);
}

static void client_refresher(void* client)
{
    while(1)
    {
        mqtt_sync((struct mqtt_client*) client);
        vTaskDelay(100);
    }

}


void send_pic_large(char* send_pic, char* topic)
{
    /* 定义一个变量来存储application_message的长度 */ 
    int len = strlen(send_pic) + 1; 
    // 定义一个变量来存储每次发送的数据长度 / 
    int chunk = 1000; 
    // 定义一个变量来存储当前发送的位置  
    uint32_t pos = 0; 
    // 使用一个循环，直到application_message发送完毕 /
    while (pos < len) { 
        // 计算剩余的数据长度 /
        int remain = len - pos;
        //如果剩余的数据长度小于每次发送的数据长度，就使用剩余的数据长度 
        if (remain < chunk) { chunk = remain; } 
        /* 调用mqtt_publish函数，使用application_message中从pos开始，长度为chunk的数据 */ 
        mqtt_publish(&client, topic, send_pic + pos, chunk, MQTT_PUBLISH_QOS_0); 
        mqtt_sync(&client);
        bflb_mtimer_delay_ms(1000);
        
        pos += chunk; /* 更新当前发送的位置 */ 
        printf("remian: %d \r\n", remain);
    
    }

    printf("finished: %d \r\n", len);
}
