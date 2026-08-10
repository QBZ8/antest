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
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "stdio.h"
#include "string.h"
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

uint8_t frame[106]={0xAA,0x00,0x00,0x64};
volatile uint8_t tx_busy = 0;
uint8_t rx_buf[7]; 
volatile uint16_t rx_len = 0;
volatile uint8_t rx_flag = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart==&huart3)
	{
		//HAL_UART_Transmit_IT(&huart3,rx_buf,7);
		HAL_UART_Receive_IT(&huart3,rx_buf,7);
		rx_flag = 1;
	}
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart3)
    {
        tx_busy = 0;
		
    }
}


/**void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart == &huart3)
    {
        rx_len = Size;
        rx_flag = 1;

        // ���¿��� DMA ���գ��ǳ���Ҫ��
        HAL_UART_Receive_DMA(&huart3, rx_buf, sizeof(rx_buf));
        __HAL_DMA_DISABLE_IT(&hdma_usart3_rx, DMA_IT_HT);
    }
}**/
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
  MX_USART3_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(20);
  OLED_Init();
  
  __HAL_DMA_DISABLE_IT(&hdma_usart3_rx,DMA_IT_HT);
  
  uint8_t sendData[100]={0x8F,0x14,0xE3,0x5D,0xBB,0x9A,0x2C,0x71,0xD9,0x06,
						 0xA7,0x3E,0x82,0x4B,0xF0,0xC5,0x39,0x6E,0x53,0x1D,
						 0xFC,0x28,0x97,0x63,0xAD,0x40,0x7B,0xE8,0x15,0xCE,
						 0x22,0x89,0x56,0xB4,0x0F,0x3A,0xD7,0x60,0x9C,0x77,
						 0x4D,0xEA,0x31,0x8B,0x12,0xF9,0x64,0xA3,0x0C,0x5F,
						 0x91,0x7E,0xC2,0x29,0x54,0xBF,0x18,0xE6,0x43,0xAA,
						 0x35,0x80,0xFD,0x1A,0x67,0xBE,0x09,0xD2,0x4E,0x95,
						 0x78,0x26,0xB3,0x0A,0xE1,0x5C,0x87,0x3B,0x44,0xAF,
						 0x10,0xDB,0x75,0x8E,0x21,0xFA,0x6D,0x34,0x99,0xC6,
						 0x2B,0x50,0xED,0x86,0x1F,0x72,0xBC,0x07,0x48,0xF3};
  
    uint8_t senderrorData[106]={0xAA,0x00,0x00,0x64,
		                 0x7F,0x14,0xE3,0x5D,0xBB,0x9A,0x2C,0x71,0xD9,0x06,
						 0xA7,0x3E,0x82,0x4B,0xF0,0xC5,0x39,0x6E,0x53,0x1D,
						 0xFC,0x28,0x97,0x63,0xAD,0x40,0x7B,0xE8,0x15,0xCE,
						 0x22,0x89,0x56,0xB4,0x0F,0x3A,0xD7,0x60,0x9C,0x77,
						 0x4D,0xEA,0x31,0x8B,0x12,0xF9,0x64,0xA3,0x0C,0x5F,
						 0x91,0x7E,0xC2,0x29,0x54,0xBF,0x18,0xE6,0x43,0xAA,
						 0x35,0x80,0xFD,0x1A,0x67,0xBE,0x09,0xD2,0x4E,0x95,
						 0x78,0x26,0xB3,0x0A,0xE1,0x5C,0x87,0x3B,0x44,0xAF,
						 0x10,0xDB,0x75,0x8E,0x21,0xFA,0x6D,0x34,0x99,0xC6,
						 0x2B,0x50,0xED,0x86,0x1F,0x72,0xBC,0x07,0x48,0xF3,
						 0xA3,0xEC};
  uint8_t sumcheck=0;
  uint8_t addcheck=0;
  
  char head[4]="";
  char data[1]="";
  char checkout[2]="";
  for(int i=0;i<100;i++)
{
	frame[4+i]=sendData[i];
}	
  for(int i=0;i<104;i++)
{
	sumcheck+=frame[i];
	addcheck+=sumcheck;
}
	frame[104]=sumcheck;
	frame[105]=addcheck;


	tx_busy = 1;
	HAL_UART_Receive_IT(&huart3,rx_buf,7);
    OLED_NewFrame();
	OLED_PrintString(0,0,"ready",&font16x16,OLED_COLOR_NORMAL);
    OLED_ShowFrame();
	//HAL_UART_Receive_DMA(&huart3, rx_buf, sizeof(rx_buf));
	//__HAL_DMA_DISABLE_IT(&hdma_usart3_rx, DMA_IT_HT); // �رհ봫�ж�
	//HAL_UART_Transmit_DMA(&huart3, frame, 106);
	//HAL_UART_Receive_DMA(&huart3,frame,sizeof(frame));
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
	  {
		  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
		  {
			 HAL_UART_Transmit_DMA(&huart3, frame, 106);
		     OLED_NewFrame();
			 OLED_PrintString(0,0,"senddata",&font16x16,OLED_COLOR_NORMAL);
			 OLED_ShowFrame();
		  }
		  while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
		  {
			  HAL_Delay(10);
		  }
		  
	  }
	  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET)
	  {
		  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET)
		  {
			 HAL_UART_Transmit_DMA(&huart3, senderrorData, 106);
		     OLED_NewFrame();
			 OLED_PrintString(0,0,"senddata",&font16x16,OLED_COLOR_NORMAL);
			 OLED_ShowFrame();
		  }
		  while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET)
		  {
			  HAL_Delay(10);
		  }
		  
	  }
	 if (rx_flag)
    {
        rx_flag = 0;
		uint8_t rx_sumcheck=0;
        uint8_t rx_addcheck=0;
		for(int i=0;i<5;i++)
		{
			rx_sumcheck+=rx_buf[i];
	        rx_addcheck+=rx_sumcheck;
		}
		if(rx_sumcheck==rx_buf[5]&&rx_addcheck==rx_buf[6])
		{
		OLED_NewFrame();
		sprintf(head, " %02X%02X%02X%02X", rx_buf[0],rx_buf[1],rx_buf[2],rx_buf[3]);
	    OLED_PrintString(0,0,"head",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(32,0,head,&font16x16,OLED_COLOR_NORMAL);
		sprintf(data, " %d", rx_buf[4]);
		OLED_PrintString(0,16,"error",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(48,16,data,&font16x16,OLED_COLOR_NORMAL);
		sprintf(checkout, " %02X%02X", rx_buf[5],rx_buf[6]);
		OLED_PrintString(0,32,"checkout",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(64,32,checkout,&font16x16,OLED_COLOR_NORMAL);
		OLED_ShowFrame();
		}
		else
		{
		OLED_NewFrame();
		sprintf(checkout, " %02X%02X", rx_sumcheck,rx_addcheck);
		OLED_PrintString(0,32,"checkout",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(48,32,checkout,&font16x16,OLED_COLOR_NORMAL);
		OLED_ShowFrame();
		}
		
		
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
