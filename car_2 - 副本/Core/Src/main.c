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
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "stdio.h"
#include "font.h"
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
int upEdge=0;
int downEdge=0;
float distance=0;
float distance_2=0;
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if(htim==&htim1 && htim->Channel==HAL_TIM_ACTIVE_CHANNEL_4)
	{
		upEdge=HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_3);
		downEdge=HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_4);
		distance=(downEdge-upEdge)*0.034/2;
		
	}
	if(htim==&htim1 && htim->Channel==HAL_TIM_ACTIVE_CHANNEL_2)
	{
		upEdge=HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_1);
		downEdge=HAL_TIM_ReadCapturedValue(htim,TIM_CHANNEL_2);
		distance_2=(downEdge-upEdge)*0.034/2;
		
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
  MX_TIM1_Init();
  MX_I2C2_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(100);
  OLED_Init();
  HAL_TIM_Base_Start(&htim1);
  HAL_TIM_IC_Start(&htim1,TIM_CHANNEL_3);
  HAL_TIM_IC_Start_IT(&htim1,TIM_CHANNEL_4);
  HAL_TIM_IC_Start(&htim1,TIM_CHANNEL_1);
  HAL_TIM_IC_Start_IT(&htim1,TIM_CHANNEL_2);
  
  char message[20]="";
  char message_2[20]="";
  char CarState[20]="";
  char CarState_2[20]="";
  char Time[20]="";
  char Time_2[20]="";
  char Money[20]="";
  char Money_2[20]="";
  uint32_t busy_start_time = 0;
  uint32_t busy_start_time2 = 0;
  uint8_t is_busy1 = 0;
  uint8_t is_busy2=0;
  uint32_t busy_duration1 = 0;
  uint32_t busy_duration2 = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  
	 uint32_t now = HAL_GetTick();
	  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_SET);
	  HAL_Delay(1);
	  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
	  //__HAL_TIM_SET_COUNTER(&htim1,0);
	  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
	  HAL_Delay(1);
	  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);
	  __HAL_TIM_SET_COUNTER(&htim1,0);
	  
	  uint32_t sec1 = busy_duration1 / 1000;
      uint32_t min1 = sec1 / 60;
	
      sec1 = sec1 % 60;
	
	 uint32_t sec2 = busy_duration2 / 1000;
      uint32_t min2 = sec2 / 60;
	
      sec2 = sec2 % 60;
	  sprintf(message,"%.2fcm",distance);
	  sprintf(message_2,"%.2fcm",distance_2);
	  sprintf(Time,"%d分:%d秒",min1,sec1);
	  sprintf(Time_2,"%d分:%d秒",min2,sec2);
	
	  sprintf(Money,"%d元",sec1);
	  sprintf(Money_2,"%d元",sec2);
	  if(distance <= 3)
    {
        if(is_busy1 == 0)
        {
            is_busy1 = 1;
            busy_start_time = now;
        }

        busy_duration1 = now - busy_start_time;
        sprintf(CarState,"占用");
    }
    else
    {
        is_busy1 = 0;
        busy_duration1 = 0;
        sprintf(CarState,"空闲");
    }
	if(distance_2 <= 3)
    {
        if(is_busy2 == 0)
        {
            is_busy2 = 1;
            busy_start_time2 = now;
        }

        busy_duration2 = now - busy_start_time2;
        sprintf(CarState_2,"占用");
    }
    else
    {
        is_busy2 = 0;
        busy_duration2 = 0;
        sprintf(CarState_2,"空闲");
    }
	  
	  OLED_NewFrame();
	
	  OLED_PrintString(0,0,CarState,&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,16,Time,&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,32,Money,&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,48,message,&font16x16,OLED_COLOR_NORMAL);
	  
	  OLED_ShowFrame2();
	  
	  OLED_NewFrame();
	  OLED_PrintString(0,0,CarState_2,&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,16,Time_2,&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,32,Money_2,&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,48,message_2,&font16x16,OLED_COLOR_NORMAL);
	  OLED_ShowFrame1();
	  
	
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
