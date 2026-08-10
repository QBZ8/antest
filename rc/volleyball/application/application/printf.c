
#include "stdio.h"
#include "main.h"

// 注意在魔术棒中 添加使用微库


/** 定义printf使用的串口 */
extern UART_HandleTypeDef huart1;


/**
  * @brief  Retargets the C library printf function to the UART.
  * @param  None
  * @retval None
  */
int fputc(int ch, FILE *f)
{
	// 采用轮询方式发送1字节数据，超时时间设置为无限等待 
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}

/**
  * @brief  Retargets the C library scanf function to the UART.
  * @param  None
  * @retval None
  */
int fgetc(FILE *f)
{
	uint8_t ch;
	// 采用轮询方式接收1字节数据，超时时间设置为无限等待 
	HAL_UART_Receive( &huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY );
	return ch;;
}





