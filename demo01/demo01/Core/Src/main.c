/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "cmsis_os.h"
#include "adc.h"
#include "can.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#define MIN_BUZZER_PWM 10000
#define MAX_BUZZER_PWM 20000
#define MAX_PSC 1000
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
   //user_delay_us
		  void user_delay_us(uint16_t us)
			{
				for(;us>0;us--)
				{
					for(uint8_t i=50;i>0;i--)
					{
						;
					}
				}
			}
   //user_delay_ms
			void user_delay_ms(uint16_t ms)
			{
				for(;ms>0;ms--)
				{
					user_delay_us(1000);
				}
			}
	//nop
				void nop_delay_us(uint16_t us)
				{
					for(;us>0;us--)
					{
						for(uint8_t i=10;i>0;i--)
						{
							_nop();
							_nop();
							_nop();
							_nop();
							_nop();
							_nop();
							_nop();
							_nop();
							_nop();
							_nop();
							_nop();
						}
					}
				}
				
				void nop_delay_ms(uint16_t ms)
				{
					for(;ms>0;ms--)
					{
						nop_delay_us(1000);
					}
				}
//HAL_Delay
 void HAL_Delay(uint32_t Delay);	
//TIM1
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim); 
void HAL_TIM_PeriodElapsedCallback(TIM_HallSensor_InitTypeDef*ttim)
{
	if(htim==&htim1)
	{
		bsp_led_toggle();
	}
}	
//aRGB
void aRGB_led_show(uint32_t aRGB)
{
	static uint8_t alpha;
	static uint16_t red,green,blue;
	
	alpha=(aRGB & 0xFF000000)>>24;
	red=((aRGB & 0x00FF0000)>>16)*alpha;
	green=((aRGB & 0x0000FF00)>>8)*alpha;
	blue=((aRGB & 0x000000FF)>>0)*alpha;
	__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_1,blue);
	__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_2,green);
	__HAL_TIM_SetCompare(&htim5,TIM_CHANNEL_3,red);
}
//buzzer
void buzzer_on(uint16_t psc, uint16_t pwm); 
//ADC
void init_vrefint_reciprocal(void)
{
	uint8_t i=0;
	uint32_t total_adc=0;
	for(i=0;i<200;i++)
	{
		total_adc+=adcx_get_chx_value(&hadc1,ADC_CHANNEL_VREFINT);
	}
	voltage_vrefint_proportion=200*1.2f/total_adc;
}

fp32 get_battery_voltage(void)
{
	fp32 voltage;
	uint16_t adcx=0;
	adcx=adcx_get_chx_value(&hadc3,ADC_CHANNEL_8);
	voltage=(fp32)adcx*voltage_vrefint_proportion* 10.090909090909090909090909090909f;
	return voltage;
}

fp32 get_temprate(void)
{
	uint16_t adcx=0;
	fp32 temperate;
	adcx = adcx_get_chx_value(&hadc1, ADC_CHANNEL_TEMPSENSOR); 
	 temperate = (fp32)adcx * voltage_vrefint_proportion; 
	temperate = (temperate - 0.76f) * 400.0f + 25.0f; 
	return temperate; 
}
//usart
void usart_printf(const char *fmt,...)
{
	static uint8_t tx_buf[256]={0};
	static va_list ap;
	static uint16_t len;
	va_start(ap,fmt);
	len=vsprintf((char*)tx_buf,fmt,ap);
	va_end(ap);
	usart1_tx_dma_enable(tx_buf,len);
}

void RC_init(uint8_t *rxl_buf,uint8_t*rx2_buf,uint16_t dma_buf_num)
{
	SET_BIT(huart3.Instance->CR3,USART_CR3_DMAR);
	__HAL_UART_ENABLE_IT(&huart3,UARI_IT_IDLE);
	__HAL_DMA_DISABLE(&hdma_usart3_rx); 
    while(hdma_usart3_rx.Instance->CR & DMA_SxCR_EN) 
    { 
        __HAL_DMA_DISABLE(&hdma_usart3_rx); 
    }
  hdma_usart3_rx.Instance->PAR = (uint32_t) & (USART3->DR); 
	hdma_usart3_rx.Instance->M0AR = (uint32_t)(rx1_buf);
	hdma_usart3_rx.Instance->M1AR = (uint32_t)(rx2_buf);
	hdma_usart3_rx.Instance->NDTR = dma_buf_num;
	SET_BIT(hdma_usart3_rx.Instance->CR, DMA_SxCR_DBM);	
	__HAL_DMA_ENABLE(&hdma_usart3_rx);
		
}

void USART3_IRQHandler(void) 
{ 
    if(huart3.Instance->SR & UART_FLAG_RXNE)//????? 
    { 
        __HAL_UART_CLEAR_PEFLAG(&huart3); 
    } 
    else if(USART3->SR & UART_FLAG_IDLE) 
    { 
        static uint16_t this_time_rx_len = 0; 
 
        __HAL_UART_CLEAR_PEFLAG(&huart3); 
 
        if ((hdma_usart3_rx.Instance->CR & DMA_SxCR_CT) == RESET) 
        { 
            /* Current memory buffer used is Memory 0 */ 
     
            //disable DMA 
            //??DMA 
            __HAL_DMA_DISABLE(&hdma_usart3_rx);
					 //????????,?? = ???? - ???? 
            this_time_rx_len = SBUS_RX_BUF_NUM - hdma_usart3_rx.Instance->NDTR; 
 
            //reset set_data_lenght 
            //???????? 
            hdma_usart3_rx.Instance->NDTR = SBUS_RX_BUF_NUM; 
 
            //set memory buffer 0 
            //?????0 
            DMA1_Stream1->CR &= ~(DMA_SxCR_CT); 
             
            //enable DMA 
            //??DMA 
            __HAL_DMA_ENABLE(&hdma_usart3_rx); 
 
            if(this_time_rx_len == RC_FRAME_LENGTH) 
            { 
                //??????? 
                sbus_to_rc(sbus_rx_buf[1], &rc_ctrl); 
            } 
        } 
    } 
}

static void sbus_to_rc(volatile const uint8_t *sbus_buf, RC_ctrl_t *rc_ctrl) 
{ 
    if (sbus_buf == NULL || rc_ctrl == NULL) 
    { 
        return; 
    } 
 
    rc_ctrl->rc.ch[0] = (sbus_buf[0] | (sbus_buf[1] << 8)) & 0x07ff;         //!< Channel 0 
    rc_ctrl->rc.ch[1] = ((sbus_buf[1] >> 3) | (sbus_buf[2] << 5)) & 0x07ff;  //!< Channel 1 
    rc_ctrl->rc.ch[2] = ((sbus_buf[2] >> 6) | (sbus_buf[3] << 2) |           //!< Channel 2 
                         (sbus_buf[4] << 10)) &0x07ff; 
    rc_ctrl->rc.ch[3] = ((sbus_buf[4] >> 1) | (sbus_buf[5] << 7)) & 0x07ff;  //!< Channel 3 
    rc_ctrl->rc.s[0] = ((sbus_buf[5] >> 4) & 0x0003);                   //!< Switch left 
    rc_ctrl->rc.s[1] = ((sbus_buf[5] >> 4) & 0x000C) >> 2;                 //!< Switch right 
    rc_ctrl->mouse.x = sbus_buf[6] | (sbus_buf[7] << 8);                   //!< Mouse X axis 
    rc_ctrl->mouse.y = sbus_buf[8] | (sbus_buf[9] << 8);                   //!< Mouse Y axis 
    rc_ctrl->mouse.z = sbus_buf[10] | (sbus_buf[11] << 8);                 //!< Mouse Z axis 
    rc_ctrl->mouse.press_l = sbus_buf[12];                              //!< Mouse Left Is Press ? 
    rc_ctrl->mouse.press_r = sbus_buf[13];                              //!< Mouse Right Is Press ? 
    rc_ctrl->key.v = sbus_buf[14] | (sbus_buf[15] << 8);                   //!< KeyBoard value 
    rc_ctrl->rc.ch[4] = sbus_buf[16] | (sbus_buf[17] << 8);                  //NULL 
 
    rc_ctrl->rc.ch[0] -= RC_CH_VALUE_OFFSET; 
    rc_ctrl->rc.ch[1] -= RC_CH_VALUE_OFFSET; 
    rc_ctrl->rc.ch[2] -= RC_CH_VALUE_OFFSET; 
    rc_ctrl->rc.ch[3] -= RC_CH_VALUE_OFFSET; 
    rc_ctrl->rc.ch[4] -= RC_CH_VALUE_OFFSET; 
} 
//ist8310
void ist8310_red_over(uint8_t *status_buf,ist8310_real_data_t*ist8310_real_data)
{
	if(status_buf[0]&0x01)
	{
		int16_t temp_ist8310_data=0;
		ist8310_real_data->status |=1<<IST8310_DATA_READY_BIT;
		temp_ist8310_data=(int16_t)((status_buf[2]<<8)|status_buf[1]);
		ist8310_real_data->mag[0]=MAG_SEN*temp_ist8310_data;
		temp_ist8310_data=(int16_t)((status_buf[4]<<8)|status_buf[3]);
		ist8310_real_data->mag[1]=MAG_SEN*temp_ist8310_data;
		temp_ist8310_data=(int16_t)((status_buf[6]<<8)|status_buf[5]);
		ist8310_real_data->mag[2]=MAG_SEN*temp_ist8310_data;		
	}
	else
{
	ist8310_real_data->status&=~(1<<IST8310_DATA_READY_BIT);
}
}

void ist8310_read_mag(fp32 mag[3])
{
	uint8_t buf[6];
	int16_t temp_ist8310_data=0;
	ist8310_IIC_read_muli_reg(0x03,buf,6);
	
	temp_ist8310_data=(int16_t)((buf[1]<<8)|buf[0]);
	mag[0]=MAG_SEN*temp_ist8310_data;
	temp_ist8310_data=(int16_t)((buf[3]<<8)|buf[2]);
	mag[1]=MAG_SEN*temp_ist8310_data;
	temp_ist8310_data=(int16_t)((buf[5]<<8)|buf[4]);
	mag[2]=MAG_SEN*temp_ist8310_data;	
}
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_TIM1_Init();
  MX_TIM5_Init();
  MX_TIM4_Init();
  MX_TIM8_Init();
  MX_ADC1_Init();
  MX_ADC3_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_USART6_UART_Init();
  MX_I2C3_Init();
  MX_I2C2_Init();
  MX_SPI1_Init();
  MX_CAN1_Init();
  MX_CAN2_Init();
  /* USER CODE BEGIN 2 */
	uint16_t pwm;
	uint16_t psc;

  /* USER CODE END 2 */

  /* Call init function for freertos objects (in cmsis_os2.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		//LEDdemo
		 HAL_GPIO_WritePin(LED_R_GPIO_Port,LED_R_Pin,GPIO_PIN_SET);
		 HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin,GPIO_PIN_SET);
		 HAL_GPIO_WritePin(LED_B_GPIO_Port,LED_B_Pin,GPIO_PIN_SET);
		//LED_TogglePin
		 HAL_GPIO_TogglePin(LED_R_GPIO_Port,LED_R_Pin);
		//turn
		 bsp_led_toggle();
		 nop_delay_ms(500);
		 bsp_led_toggle();
	   user_delay_ms(500);
		 bsp_led_toggle();
		 HAL_Delay(500);
		//buzzer
		pwm++;
		if(pwm>MAX_BUZZER_PWM)
		{	
      pwm=MIN_BUZZER_PWM;			
		}
		if(psc>MAX_PSC)
		{
			psc=0;
		}
		buzzer_on(psc,pwm);
		HAL_Delay(1);
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
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
