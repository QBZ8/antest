//
// Created by fs on 2026/3/6.
//

#ifndef ESP8266_MQTT_ONENET_MYCODE_H
#define ESP8266_MQTT_ONENET_MYCODE_H
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include "stdio.h"


#include "usart.h"

// ========================================================================
// 1. ����ר����Ϣ������ (��Դǰ���������������ջ��ߴ��������˼���)
// ========================================================================
#define WIFI_SSID           "YOUR_WIFI_SSID"
#define WIFI_PASSWORD       "YOUR_WIFI_PASSWORD"

#define MQTT_SERVER         "mqtts.heclouds.com"
#define MQTT_PORT           1883

#define PRODUCT_ID          "c72VG1b5n6"
#define DEVICE_NAME         "stm32"
#define MQTT_TOKEN          "YOUR_MQTT_TOKEN"

// ------------------------------------------------------------------------
// ���� C �����ַ����Զ�ƴ�����ԣ���̬���ɶ�Ӧ�� Topic
// ------------------------------------------------------------------------
#define TOPIC_POST_REPLY    "$sys/" PRODUCT_ID "/" DEVICE_NAME "/thing/property/post/reply"
#define TOPIC_SET           "$sys/" PRODUCT_ID "/" DEVICE_NAME "/thing/property/set"
#define TOPIC_POST          "$sys/" PRODUCT_ID "/" DEVICE_NAME "/thing/property/post"
#define TOPIC_SET_REPLY     "$sys/" PRODUCT_ID "/" DEVICE_NAME "/thing/property/set_reply"
// ========================================================================

void mycode_init(void);
void mycode_run(void);
void uart_print(UART_HandleTypeDef *huart, char* format, ...);
void Build_OneNet_Cmd(char *out_buf, const char *topic, const char *msg_id, uint8_t param_count, ...);


extern volatile uint8_t uart_rx_byte;
extern char uart_rx_buf[512];
extern volatile uint16_t uart_rx_len ;

extern volatile uint8_t openmv_rx_byte;
extern char openmv_rx_buf[16];
extern volatile uint8_t openmv_rx_len;
extern volatile uint8_t openmv_number;
extern volatile uint8_t openmv_data_ready;

#endif //ESP8266_MQTT_ONENET_MYCODE_H
