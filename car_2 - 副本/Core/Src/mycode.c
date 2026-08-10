//
// Created by fs on 2026/3/6.
//

#include "mycode.h"
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
volatile uint8_t uart_rx_byte;
char uart_rx_buf[512];
volatile uint16_t uart_rx_len = 0;

// ==========================================
// 3. 串口中断回调函数
// ==========================================
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        if (uart_rx_len < (sizeof(uart_rx_buf) - 1))
        {
            uart_rx_buf[uart_rx_len++] = (char)uart_rx_byte;
            uart_rx_buf[uart_rx_len] = '\0';
        }
        HAL_UART_Receive_IT(&huart1, (uint8_t *)&uart_rx_byte, 1);
    }
}

void mycode_init()
{
    HAL_Delay(1000);
    //OLED_Init();
    //OLED_Clear();
}

void uart_print(UART_HandleTypeDef *huart, char* format, ...)
{
    static char buf[512] = {0};
    va_list ap;
    va_start(ap, format);
    vsnprintf(buf, sizeof(buf), format, ap);
    va_end(ap);
    HAL_UART_Transmit(huart, (uint8_t*)buf, strlen(buf), HAL_MAX_DELAY);
}

/*void Update_Top_Status(uint8_t step)
{
    OLED_ShowNum(0, 0, step, 1, OLED_6X8);
    OLED_Update();
}*/

/*void Update_Error_Status(char* err_msg)
{
    OLED_ShowString(0, 10, "                     ", OLED_6X8);
    OLED_ShowString(0, 10, err_msg, OLED_6X8);
    OLED_Update();
}
*/
// 仅用于初始化阶段的阻塞发送
int8_t Send_Cmd_Wait_Resp_IT(UART_HandleTypeDef *huart, char *cmd, char *expected_resp, uint32_t timeout_ms, uint8_t max_retries)
{
    uint8_t retry_count = 0;
    uint32_t start_time = 0;

    while (retry_count < max_retries)
    {
        memset(uart_rx_buf, 0, sizeof(uart_rx_buf));
        uart_rx_len = 0;

        uart_print(huart, "%s", cmd);
        start_time = HAL_GetTick();

        while ((HAL_GetTick() - start_time) < timeout_ms)
        {
            if (uart_rx_len > 0 && strstr(uart_rx_buf, expected_resp) != NULL)
            {
                uart_print(&huart2, "%s", uart_rx_buf);
                memset(uart_rx_buf, 0, sizeof(uart_rx_buf));
                uart_rx_len = 0;
                return 0;
            }
            HAL_Delay(10);
        }

        if (uart_rx_len > 0) {
            uart_print(&huart2, "%s", uart_rx_buf);
        }

        retry_count++;
        HAL_Delay(500);
    }
    return -1;
}

// ==========================================
// 万能 OneNet 多参数 JSON 构建器 (终极浮点精度修复版)
// ==========================================
void Build_OneNet_Cmd(char *out_buf, const char *topic, const char *msg_id, uint8_t param_count, ...)
{
    static char payload[384];
    memset(payload, 0, sizeof(payload));
    int offset = 0;
    va_list ap;

    offset += sprintf(payload + offset, "{\\\"id\\\":\\\"%s\\\"\\,\\\"version\\\":\\\"1.0\\\"\\,\\\"params\\\":{", msg_id);

    va_start(ap, param_count);
    for(uint8_t i = 0; i < param_count; i++)
    {
        char *key = va_arg(ap, char*);
        int type = va_arg(ap, int);

        if (i > 0) offset += sprintf(payload + offset, "\\,");

        if (type == 'i') {
            int val = va_arg(ap, int);
            offset += sprintf(payload + offset, "\\\"%s\\\":{\\\"value\\\":%d}", key, val);
        }
        else if (type == 'f') {
            // 【核心修复区】：彻底解决 10.2 变成 10.19 的精度截断问题
            double val = va_arg(ap, double);
            int int_part = (int)val;

            // 1. 提取小数部分，强制转正
            double diff = val - int_part;
            if (diff < 0) diff = -diff;

            // 2. 放大 100 倍，并加上 0.5 实现“四舍五入”
            int dec_part = (int)(diff * 100.0 + 0.5);

            // 3. 处理进位：如果小数部分四舍五入后达到了 100 (例如 10.999)
            if (dec_part >= 100) {
                dec_part -= 100;
                if (val >= 0) int_part += 1;
                else int_part -= 1;
            }

            // 4. 处理 -0.xx 这种极其特殊的负小数情况
            if (val < 0 && int_part == 0) {
                offset += sprintf(payload + offset, "\\\"%s\\\":{\\\"value\\\":-%d.%02d}", key, int_part, dec_part);
            } else {
                offset += sprintf(payload + offset, "\\\"%s\\\":{\\\"value\\\":%d.%02d}", key, int_part, dec_part);
            }
        }
        else if (type == 's') {
            char *val = va_arg(ap, char*);
            offset += sprintf(payload + offset, "\\\"%s\\\":{\\\"value\\\":\\\"%s\\\"}", key, val);
        }
		else if (type == 'b') { 
    int val = va_arg(ap, int); // 布尔值通常用 int 传递 (0 或 1)
    if(val) {
        offset += sprintf(payload + offset, "\\\"%s\\\":{\\\"value\\\":true}", key);
    } else {
        offset += sprintf(payload + offset, "\\\"%s\\\":{\\\"value\\\":false}", key);
    }
}
    }
    va_end(ap);

    sprintf(payload + offset, "}}");
    sprintf(out_buf, "AT+MQTTPUB=0,\"%s\",\"%s\",0,0\r\n", topic, payload);
}

void mycode_run()
{
    uint8_t biaozhi = 0;
    uint16_t i = 0;
    static char cmd_buf[512];

    //OLED_ShowString(12, 0, "Wait...", OLED_6X8); OLED_Update();

    HAL_UART_Receive_IT(&huart1, (uint8_t *)&uart_rx_byte, 1);

    uart_print(&huart1, "AT+RST\r\n");
    HAL_Delay(2000);

    //Update_Top_Status(1);
    if (Send_Cmd_Wait_Resp_IT(&huart1, "AT+CWMODE=1\r\n", "OK", 2000, 3) != 0) //Update_Error_Status("ERR: CWMODE");
	{
		
	}
    //Update_Top_Status(2);
    sprintf(cmd_buf, "AT+CWJAP=\"%s\",\"%s\"\r\n", WIFI_SSID, WIFI_PASSWORD);
    if (Send_Cmd_Wait_Resp_IT(&huart1, cmd_buf, "OK", 10000, 3) != 0) //Update_Error_Status("ERR: WIFI");
    {
		
	}
	HAL_Delay(2000);

    //Update_Top_Status(3);
    sprintf(cmd_buf, "AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"\r\n", DEVICE_NAME, PRODUCT_ID, MQTT_TOKEN);
    if (Send_Cmd_Wait_Resp_IT(&huart1, cmd_buf, "OK", 3000, 3) != 0) //Update_Error_Status("ERR: CFG");
	{
		
	}
    //Update_Top_Status(4);
    sprintf(cmd_buf, "AT+MQTTCONN=0,\"%s\",%d,1\r\n", MQTT_SERVER, MQTT_PORT);
    if (Send_Cmd_Wait_Resp_IT(&huart1, cmd_buf, "OK", 8000, 3) != 0) //Update_Error_Status("ERR: CONN");
	{
		
	}
    //Update_Top_Status(5);
    sprintf(cmd_buf, "AT+MQTTSUB=0,\"%s\",0\r\n", TOPIC_POST_REPLY);
    if (Send_Cmd_Wait_Resp_IT(&huart1, cmd_buf, "OK", 5000, 3) != 0) //Update_Error_Status("ERR: SUB1");
	{
		
	}
    //Update_Top_Status(6);
    sprintf(cmd_buf, "AT+MQTTSUB=0,\"%s\",0\r\n", TOPIC_SET);
    if (Send_Cmd_Wait_Resp_IT(&huart1, cmd_buf, "OK", 5000, 3) != 0) //Update_Error_Status("ERR: SUB2");
	{
		
	}
   // OLED_ShowString(12, 0, "RUN    ", OLED_6X8); OLED_Update();
   // Update_Top_Status(7);

    char str[]="abcde";

    while (1)
    {
        //OLED_ShowNum(80, 0, uwTick / 1000, 5, OLED_6X8);
        //OLED_Update();

        if(uwTick / 1000 % 2 == 0) {
            if(biaozhi == 0) {
                biaozhi = 1;
                i++;
                // 不能超过256
                Build_OneNet_Cmd(cmd_buf, TOPIC_POST, "123", 3,
                 "IsBusy", 'b', 0,
                 "Time", 'i', 123,
                 "Money",'f',10.212);


                uart_print(&huart1, "%s", cmd_buf);
                //Update_Error_Status("Uploading...");
            }
        } else {
            biaozhi = 0;
        }

        if (uart_rx_len > 0)
        {
            // 【核心防碎片化优化】：稍微延时 50ms，确保这一帧串口数据彻底接收完毕，防止腰斩解析
            HAL_Delay(50);

            if (uart_rx_len > 3) {
                uart_print(&huart2, "%s", uart_rx_buf);
            }

            // 处理云端下发的命令
            /*if (strstr(uart_rx_buf, "+MQTTSUBRECV") != NULL && strstr(uart_rx_buf, "/set\"") != NULL)
            {
                if (strstr(uart_rx_buf, "\"LED\":true") != NULL || strstr(uart_rx_buf, "\"LED_Green\":true") != NULL)
                {
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
                }
                else if (strstr(uart_rx_buf, "\"LED\":false") != NULL || strstr(uart_rx_buf, "\"LED_Green\":false") != NULL)
                {
                    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
                }

                char msg_id[16] = {0};
                char *id_start = strstr(uart_rx_buf, "\"id\":\"");

                if (id_start != NULL)
                {
                    id_start += 6;
                    char *id_end = strchr(id_start, '"');

                    if (id_end != NULL && (id_end - id_start) < sizeof(msg_id))
                    {
                        strncpy(msg_id, id_start, id_end - id_start);
                        msg_id[id_end - id_start] = '\0';
                        uart_print(&huart1, "AT+MQTTPUB=0,\"%s\",\"{\\\"id\\\":\\\"%s\\\"\\,\\\"code\\\":200\\,\\\"msg\\\":\\\"success\\\"}\",0,0\r\n", TOPIC_SET_REPLY, msg_id);
                    }
                }
            }
            else if (strstr(uart_rx_buf, "+MQTTSUBRECV") != NULL && strstr(uart_rx_buf, "/post/reply") != NULL)
            {
                // 如果是刚才主动发送数据的 reply 回应，更新一下屏幕状态即可
                //Update_Error_Status("Send OK!      ");
            }*/

            // 安全清空接收缓存
            memset(uart_rx_buf, 0, sizeof(uart_rx_buf));
            uart_rx_len = 0;
        }
    }
}

