
#include "ESP8266.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

// ========================================================================
// 1. 个人专属信息配置区 (开源前，把这里的内容清空或者打上马赛克即可)
// ========================================================================
#define WIFI_SSID           "YOUR_WIFI_SSID"
#define WIFI_PASSWORD       "YOUR_WIFI_PASSWORD"

#define MQTT_SERVER         "mqtts.heclouds.com"
#define MQTT_PORT           1883

#define PRODUCT_ID          "c72VG1b5n6"
#define DEVICE_NAME         "stm32"
#define MQTT_TOKEN          "YOUR_MQTT_TOKEN"

// ------------------------------------------------------------------------
// 利用 C 语言字符串自动拼接特性，动态生成对应的 Topic
// ------------------------------------------------------------------------
#define TOPIC_POST_REPLY    "$sys/" PRODUCT_ID "/" DEVICE_NAME "/thing/property/post/reply"
#define TOPIC_SET           "$sys/" PRODUCT_ID "/" DEVICE_NAME "/thing/property/set"
#define TOPIC_POST          "$sys/" PRODUCT_ID "/" DEVICE_NAME "/thing/property/post"
#define TOPIC_SET_REPLY     "$sys/" PRODUCT_ID "/" DEVICE_NAME "/thing/property/set_reply"
// ========================================================================

// ==========================================
// 2. 中断接收所需的全局变量
// ==========================================
//volatile uint8_t uart_rx_byte;
//char uart_rx_buf[512];
//volatile uint16_t uart_rx_len = 0;

// ==========================================
// 3. 串口中断回调函数
// ==========================================
/*void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart==&huart1)
    {
        if (uart_rx_len < (sizeof(uart_rx_buf) - 1))
        {
            uart_rx_buf[uart_rx_len++] = (char)uart_rx_byte;
            uart_rx_buf[uart_rx_len] = '\0';
        }
        HAL_UART_Receive_IT(&huart1, (uint8_t *)&uart_rx_byte, 1);
    }
}*/


