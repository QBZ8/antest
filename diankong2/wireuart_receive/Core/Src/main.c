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

uint8_t frame[7]={0xAA,0x00,0x00,0x01};
volatile uint8_t tx_busy = 0;
uint8_t rx_buf[106]; 
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
		//HAL_UART_Transmit_IT(&huart3,rx_buf,106);
		HAL_UART_Receive_IT(&huart3,rx_buf,106);
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
  char head[4]="";
  char data[1]="";
  char checkout[2]="";
   uint8_t sendData=0;
  uint8_t sumcheck=0;
  uint8_t addcheck=0;
  uint8_t total=0;
  uint8_t error=0;



	tx_busy = 1;
	HAL_UART_Receive_IT(&huart3,rx_buf,106);
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
			 HAL_UART_Transmit_DMA(&huart3, frame, 7);
		     OLED_NewFrame();
			 OLED_PrintString(0,0,"senddata",&font16x16,OLED_COLOR_NORMAL);
			 OLED_ShowFrame();
			 
		  }
		  while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
		  {
			  HAL_Delay(10);
		  }
		  
	  }
	 if (rx_flag)
    {
        rx_flag = 0;
		frame[5]=0;
		frame[6]=0;
		uint8_t rx_sumcheck=0;
        uint8_t rx_addcheck=0;
		for(int i=0;i<104;i++)
		{
			rx_sumcheck+=rx_buf[i];
	        rx_addcheck+=rx_sumcheck;
		}
		if(rx_sumcheck==rx_buf[104]&&rx_addcheck==rx_buf[105])
		{	
			total+=1;
			sendData=100*error/total;
			frame[4]=sendData;
	
			for(int i=0;i<5;i++)
			{
			sumcheck+=frame[i];
			addcheck+=sumcheck;
			}
			frame[5]=sumcheck;
			frame[6]=addcheck;
		OLED_NewFrame();
		sprintf(head, " %02X%02X%02X%02X", rx_buf[0],rx_buf[1],rx_buf[2],rx_buf[3]);
	    OLED_PrintString(0,0,"head",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(32,0,head,&font16x16,OLED_COLOR_NORMAL);
		sprintf(data, " %d", frame[4]);
		OLED_PrintString(0,16,"error",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(48,16,data,&font16x16,OLED_COLOR_NORMAL);
		sprintf(checkout, " %02X%02X", rx_buf[104],rx_buf[105]);
		OLED_PrintString(0,32,"checkout",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(64,32,checkout,&font16x16,OLED_COLOR_NORMAL);
		OLED_ShowFrame();
		sumcheck=0;
        addcheck=0;
		}
		else
		{
			
			error+=1;
			total+=1;
			sendData=100*error/total;
			frame[4]=sendData;

	
			for(int i=0;i<5;i++)
			{
			sumcheck+=frame[i];
			addcheck+=sumcheck;
			}
			frame[5]=sumcheck;
			frame[6]=addcheck;
		OLED_NewFrame();
		sprintf(data, " %d", frame[4]);
		OLED_PrintString(0,16,"error",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(48,16,data,&font16x16,OLED_COLOR_NORMAL);
		sprintf(checkout, " %02X%02X", rx_sumcheck,rx_addcheck);
		OLED_PrintString(0,32,"checkout",&font16x16,OLED_COLOR_NORMAL);
		OLED_PrintString(64,32,checkout,&font16x16,OLED_COLOR_NORMAL);
		OLED_ShowFrame();
	    sumcheck=0;
        addcheck=0;
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
