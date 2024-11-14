
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <lwip/api.h>
#include <lwip/arch.h>
#include <lwip/opt.h>
#include <lwip/inet.h>
#include <lwip/errno.h>
#include <netdb.h>

#include "shell.h"
#include "utils_getopt.h"
#include "bflb_mtimer.h"

#define HOST_NAME "183.230.40.33"
#define ONENET_HTTP_POST_MAX_LEN 1024
#define ONENET_HTTP_POST_CONTENT_MAX_LEN 1024
#define ONENET_HTTP_POST_CONTENT_LEN_MAX_LEN 4
#define DEV_ID "1087729306"  //设备ID  更换为自己的设备id后再编译
#define API_KEY "AxI=dXrzGwUZu5QwkZW66r98saw="  //API-KEY  更换为自己的API-KEY后再编译



unsigned char* pic = "FF D8 ";
uint32_t pic_size = 0;

// clang-format off
// static const uint8_t get_buf[] = "GET / HTTP/1.1 \r\nHost: www.gov.cn\r\n\r\n";
uint32_t recv_buf[4 * 1024] = { 0 };
// clang-format on

shell_sig_func_ptr abort_exec;
uint64_t total_cnt = 0;
int sock_client = -1;

static void test_close_sendpic(int sig)
{
    if (sock_client) {
        closesocket(sock_client);
    }
    abort_exec(sig);
    if (total_cnt > 0) {
        printf("Total send data=%lld\r\n", total_cnt);
    }
}

#define PING_USAGE                                \
    "wifi_http_test [hostname] [port]\r\n"        \
    "\t hostname: hostname or dest server ip\r\n" \
    "\t port: dest server listen port, defualt port:80\r\n"

static void wifi_test_http_client_init(int argc, char **argv)
{

    abort_exec = shell_signal(SHELL_SIGINT, test_close_sendpic);
    printf("Http client task start ...\r\n");

    char *host_name;
    char *addr;
    char *port;
    struct sockaddr_in remote_addr;

    // if (argc < 2) {
    //     printf("%s", PING_USAGE);
    //     return;
    // }
    

    if (argc > 1) {
    /* get address (argv[1] if present) */
    host_name = argv[1];
#ifdef LWIP_DNS
    ip4_addr_t dns_ip;
    netconn_gethostbyname(host_name, &dns_ip);
    addr = ip_ntoa(&dns_ip);
#endif
    }
    else {
        addr = HOST_NAME;
    }
    /* get port number (argv[2] if present) */
    if (argc > 2) {
        port = argv[2];
    } else {
        port = "80";
    }

    do{
        if ((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Http Client create socket error\r\n");
            return;
        }


        remote_addr.sin_family = AF_INET;
        remote_addr.sin_port = htons(atoi(port));
        remote_addr.sin_addr.s_addr = inet_addr(addr);
        memset(&(remote_addr.sin_zero), 0, sizeof(remote_addr.sin_zero));

        printf("Host:%s, Server ip Address : %s:%s\r\n", HOST_NAME, addr, port);

        if (connect(sock_client, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) != 0) {
            printf("Http client connect server falied!\r\n");
            closesocket(sock_client);
            return;
        }

        printf("Http client connect server success!\r\n");
        printf("Press CTRL-C to exit.\r\n");
        memset(recv_buf, 0, sizeof(recv_buf));
        total_cnt = 0;
        
        //创建post数据
        char post_buf[ONENET_HTTP_POST_MAX_LEN + 1];
        char post_content[ONENET_HTTP_POST_CONTENT_MAX_LEN];
        char post_content2[ONENET_HTTP_POST_CONTENT_MAX_LEN];
        char post_content_len[ONENET_HTTP_POST_CONTENT_LEN_MAX_LEN];
        
        memset(post_content, 0, sizeof(post_content));
        memset(post_content2, 0, sizeof(post_content));
        memset(post_buf, 0, sizeof(post_buf));


        pic_size = strlen(pic) + 1; //结果 = 分配内存大小 * 3 + 1
        printf("pic_size = strlen(pic) + 1 :%d",pic_size);

        strcat(post_content,"{\"datastreams\":[{\"id\":\"temp\",\"datapoints\":[{\"value\":\"");
        strcat(post_content2,"\"}]},]}");

        sprintf(post_content_len, "%d", strlen(post_content) + pic_size + strlen(post_content2));

        strcat(post_buf, "POST /devices/");
        strcat(post_buf, DEV_ID);
        strcat(post_buf, "/datapoints HTTP/1.1\r\n");
        strcat(post_buf, "api-key:");
        strcat(post_buf, API_KEY);
        strcat(post_buf, "\r\n");
        strcat(post_buf, "Host:api.heclouds.com\r\n");
        strcat(post_buf, "Content-Length:");
        strcat(post_buf, post_content_len);
        strcat(post_buf, "\r\n\r\n");
        strcat(post_buf, post_content);
        
        write(sock_client, post_buf, strlen(post_buf));
        printf("\r\nSend:-----------\r\n%s", post_buf);
        memset(post_buf, 0, sizeof(post_buf));

        if(pic_size > ONENET_HTTP_POST_MAX_LEN)
        {
            for(uint8_t i = 0; i < ONENET_HTTP_POST_MAX_LEN; )
            {
                uint32_t size_now = pic_size - ONENET_HTTP_POST_MAX_LEN * i;
                if(size_now >= ONENET_HTTP_POST_MAX_LEN)
                {
                    memcpy(post_buf, pic + ONENET_HTTP_POST_MAX_LEN * i , ONENET_HTTP_POST_MAX_LEN);
                    post_buf[ONENET_HTTP_POST_MAX_LEN] = '\0'; 

                    write(sock_client, post_buf, strlen(post_buf));
                    printf("%s", post_buf);
                    memset(post_buf, 0, sizeof(post_buf)); 

                }
                else if(size_now < ONENET_HTTP_POST_MAX_LEN)
                {
                    memcpy(post_buf, pic + ONENET_HTTP_POST_MAX_LEN * i , size_now);
                    post_buf[ONENET_HTTP_POST_MAX_LEN] = '\0';  

                    write(sock_client, post_buf, strlen(post_buf));
                    printf("%s", post_buf);
                    memset(post_buf, 0, sizeof(post_buf));

                    break;
                }
                i++;
            }
        }
        else
        {
            memcpy(post_buf, pic , pic_size);
            post_buf[ONENET_HTTP_POST_MAX_LEN] = '\0';  

            write(sock_client, post_buf, strlen(post_buf));
            printf("%s", post_buf);
            memset(post_buf, 0, sizeof(post_buf));
        }


        strcat(post_buf,post_content2);
        strcat(post_buf, "\r\n\r\n");
        printf("%s", post_buf);
        write(sock_client, post_buf, sizeof(post_buf));
        memset(post_buf, 0, sizeof(post_buf));
        
        //释放内存
        free(pic);
        pic = "FF D8 ";


        //接受响应
        while (1) {
            total_cnt = recv(sock_client, (uint8_t *)recv_buf, sizeof(recv_buf), 0);
            if (total_cnt <= 0)
                break;
            printf("%s\r\n", (uint8_t *)recv_buf);
            vTaskDelay(5000);
        }
        closesocket(sock_client);
        // return;
    }while(0);
}

#ifdef CONFIG_SHELL
#include <shell.h>

int cmd_wifi_http_client(int argc, char **argv)
{
    wifi_test_http_client_init(argc, argv);

    return 0;
}

SHELL_CMD_EXPORT_ALIAS(cmd_wifi_http_client, onenet_post, wifi http client test);
#endif
