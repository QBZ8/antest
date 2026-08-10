/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"

#include "tjc.h"
#include "clc.h"
#include "path.h"
#include "analysis.h"

#include <stdint.h>
#define FRAME_LENGTH 7

 int path[200];
 char path8[100];
 uint8_t forbidden[] = {42, 43, 44};
 int len;
 int flag=0;
 char message[2]="ok";
 int temp=0;
 uint8_t animal[5]={0};
 uint8_t num[5]={0};
 uint8_t count=0;
 char txt[19];
 char val[13];
 uint8_t position=0;
 char objname[5]=" ";
 uint8_t ReceivePath[100];
 uint16_t rx_len=0;
 uint8_t LinePath[100];
 uint8_t SendToFC[100];
 uint16_t rx1_len=0;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void handle_forbidden()
{
	temp=receiveData[2];
	forbidden[count]=temp;
	count++;
	if(count>2)
	{
		count=0;
	}
	HAL_UART_Transmit_IT(&huart2,(uint8_t*)forbidden,sizeof(forbidden));
}

void show()
{
	uint8_t tem=receiveData[2]-receiveData[2]/10-9;
	int n = snprintf(txt, sizeof(txt),
                       "b%d.txt=\"%d%d%d%d%d\"\xff\xff\xff",
				tem,receiveData[3],receiveData[4],receiveData[5],receiveData[6],receiveData[7]);
	HAL_UART_Transmit(&huart3,(uint8_t*)txt,n,100);
			
	if(tem!=position)
	{
		for(int i=0;i<5;i++)
		    {
			 animal[i]+=num[i];
					
			 int s = snprintf(val, sizeof(val), "n%d.val=%d\xff\xff\xff",12+i,animal[i]);
				HAL_UART_Transmit(&huart3,(uint8_t*)val,s,100);
		      }
				
			position=tem;
			 }
			
	    for(int i=0;i<5;i++)
		{
			num[i]=receiveData[i+3];
		}
}


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size)
{
	if(huart==&huart3)
	{
		if(receiveData[0]==0xAA)
		{
			if(receiveData[1]==0x01)
			{	
				flag=2;
				
			}
			else if(receiveData[1]==0x02)
			{
				flag=1;
			}
			else if(receiveData[1]==0x06)
			{
				flag=6;
			}
			
			
		}
		HAL_UARTEx_ReceiveToIdle_IT(&huart3,receiveData,sizeof(receiveData));
		
	}
	else if(huart==&huart2)
	{
		rx_len=Size;
		if(receiveData[0]==0xAA)
		{
			if(receiveData[1]==0x03)
			{
				flag=3;
				
			}
			else if(receiveData[1]==0x04)
			{
				flag=4;
			}
			else if(receiveData[1]==0x05)
			{
				flag=5;
			}
			else if(receiveData[1]==0x08)
			{
				flag=8;
			}
		}
			
		HAL_UARTEx_ReceiveToIdle_IT(&huart2,receiveData,sizeof(receiveData));
	}
	else if(huart==&huart1)
	{
		flag=7;
		rx1_len=Size;
		HAL_UARTEx_ReceiveToIdle_IT(&huart1,ReceivePath,sizeof(ReceivePath));
	}
	
	
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  
  
  	initRingBuffer();		//��ʼ�����λ�����
	int a = 100;
	char str[100];
	uint32_t nowtime = HAL_GetTick();
	HAL_UARTEx_ReceiveToIdle_IT(&huart3,receiveData,sizeof(receiveData));
	HAL_UARTEx_ReceiveToIdle_IT(&huart2,receiveData,sizeof(receiveData));
	HAL_UARTEx_ReceiveToIdle_IT(&huart1,ReceivePath,sizeof(ReceivePath));
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	 if(flag==1)
	 {
		 beep();
		 //solve_path_return_start(19, forbidden, 3, path, &len);
		 //path_to_gui_lines(path, len);
		 //HAL_UART_Transmit(&huart1,LinePath,rx_len-2,100);
		 beep();
		 beep();
		 flag=0;
		
	 }
	 else if(flag==2)
	 {
		 beep();
		 handle_forbidden();
		 flag=0;
	 }
	  else if(flag==3)
	 {
		 beep();
		 show();
		 flag=0;
	 }
	 else if(flag==4)
	 {
		 beep();
		 uint8_t cnt=0;
		 SendToFC[cnt++]=0xAA;
		 SendToFC[cnt++]=0xFF;
		 SendToFC[cnt++]=0xF1;
		 SendToFC[cnt++]=0;
		 
		 for(int i=0;i<rx_len-2;i++)
		 {
			 SendToFC[cnt++]=receiveData[i+2];
		 }
		 SendToFC[3]=cnt-4;
		 uint8_t sc=0,ac=0;
		 for(int j=0;j<cnt;j++)
		 {
			 sc+=SendToFC[j];
			 ac+=sc;
		 }
		 SendToFC[cnt++]=sc;
		 SendToFC[cnt++]=ac;
		 HAL_UART_Transmit(&huart1,SendToFC,cnt,100);
		 //HAL_UART_Transmit(&huart1,receiveData,rx_len,100);
		 flag=0;
	 }
	 else if(flag==5)
	 {
		 beep();
		 for(int i=0;i<rx_len-2;i++)
		 {
			 LinePath[i]=receiveData[i+2];
		 }
		 path_to_gui_lines(LinePath, rx_len);
		/* for(int i=0;i<rx_len-2;i++)
		 {
			 hex_to_id(LinePath[i]);
			 HAL_UART_Transmit(&huart2,(uint8_t*)LinePath[i],1,100);
		 }*/
		 flag=0;
	 }
	 else if (flag==6)
	 {
		 beep();
		 uint8_t cnt=0;
		 SendToFC[cnt++]=0xAA;
		 SendToFC[cnt++]=0xFF;
		 SendToFC[cnt++]=0xD1;
		 SendToFC[cnt++]=0;
		 
		 for(int i=0;i<rx_len-2;i++)
		 {
			 SendToFC[cnt++]=LinePath[i];
		 }
		 SendToFC[3]=cnt-4;
		 uint8_t sc=0,ac=0;
		 for(int j=0;j<cnt;j++)
		 {
			 sc+=SendToFC[j];
			 ac+=sc;
		 }
		 SendToFC[cnt++]=sc;
		 SendToFC[cnt++]=ac;
		 HAL_UART_Transmit(&huart1,SendToFC,cnt,100);
		 flag=0;
	 }
	 else if(flag==7)
	 {
		 HAL_UART_Transmit(&huart2,ReceivePath,rx1_len,100);
		 flag=0;
	 }
	 else if(flag==8)
	 {
		 uint8_t txt[2]={0xBB,0xBB};
		 HAL_UART_Transmit(&huart1,txt,2,100);
		 flag=0;
	 }
	
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
