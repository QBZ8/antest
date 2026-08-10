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
#include "i2c.h"
#include "tim.h"
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
#define COUNT_MAX 40
#define ANGLE_MAX 180

 volatile uint8_t flag = 0;
 volatile uint8_t count=0;
 uint8_t receivedata[3]="";
 int angle=0;
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
void MPU6050_INIT()
{
HAL_Delay(100);
uint8_t SendAddress=0x6b;
uint8_t SendData=0x00;//解除休眠
HAL_I2C_Mem_Write(&hi2c2,0xD1,SendAddress,1,&SendData,1,0xff);

SendAddress=0x19;
SendData=0x07;//采样率分频器
HAL_I2C_Mem_Write(&hi2c2,0xD1,SendAddress,1,&SendData,1,0xff);

SendAddress=0x1A;
SendData=0x06;//低通滤波器
HAL_I2C_Mem_Write(&hi2c2,0xD1,SendAddress,1,&SendData,1,0xff);

SendAddress=0x1B;
SendData=0x08;//陀螺仪 +-500°
HAL_I2C_Mem_Write(&hi2c2,0xD1,SendAddress,1,&SendData,1,0xff);

SendAddress=0x1C;
SendData=0x00;//加速度计 +-2g
HAL_I2C_Mem_Write(&hi2c2,0xD1,SendAddress,1,&SendData,1,0xff);

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
  MX_I2C1_Init();
  MX_TIM4_Init();
  MX_I2C2_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(20);
  OLED_Init();
  
  
  char message[10]="";
  char acceleration_x[6]="";
  char acceleration_y[6]="";
  char acceleration_z[6]="";
 // char acceleration[30]="";
  //char gyroscope[30]="";
  char gyroscope_x[10]="";
  char gyroscope_y[10]="";
  char gyroscope_z[10]="";
  char all[60]="";
  int duty=0;
  char flag0[]="key mode";
  char flag1[]="usart mode";
 
  HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
  uint8_t MPU_DATA[14]="";
  uint8_t StartAddress=0x3B;
  double ACCEL_XOUT=0.0,ACCEL_YOUT=0.0,ACCEL_ZOUT=0.0;
  double GYRO_XOUT=0.0,GYRO_YOUT=0.0,GYRO_ZOUT=0.0;
  HAL_UART_Receive_IT(&huart2,receivedata,3);
  MPU6050_INIT();
  
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	HAL_I2C_Mem_Read(&hi2c2,0xD1,StartAddress,I2C_MEMADD_SIZE_8BIT,MPU_DATA,14,50);
	float Temp=(MPU_DATA[6]<<8)|MPU_DATA[7];
	if(Temp>32768) Temp-=65536;
	Temp=(36.53+Temp/340);
	
	short int ACCEL_XOUT1=((MPU_DATA[0]<<8)|MPU_DATA[1]);ACCEL_XOUT=(double)ACCEL_XOUT1/16384;
	short int ACCEL_YOUT1=((MPU_DATA[2]<<8)|MPU_DATA[3]);ACCEL_YOUT=(double)ACCEL_YOUT1/16384;
	short int ACCEL_ZOUT1=((MPU_DATA[4]<<8)|MPU_DATA[5]);ACCEL_ZOUT=(double)ACCEL_ZOUT1/16384;

	short int GYRO_XOUT1=((MPU_DATA[8]<<8)|MPU_DATA[9]);GYRO_XOUT=(double)GYRO_XOUT1/65.5;
	short int GYRO_YOUT1=((MPU_DATA[10]<<8)|MPU_DATA[11]);GYRO_YOUT=(double)GYRO_YOUT1/65.5;
	short int GYRO_ZOUT1=((MPU_DATA[12]<<8)|MPU_DATA[13]);GYRO_ZOUT=(double)GYRO_ZOUT1/65.5;
	  
	 //sprintf(acceleration,"acceleration x:%0.2f,y:%0.2f,z:%0.2f",ACCEL_XOUT,ACCEL_YOUT,ACCEL_ZOUT);
	 //sprintf(gyroscope,"gyroscope x:%0.2f,y:%0.2f,z:%0.2f",GYRO_XOUT,GYRO_YOUT,GYRO_ZOUT);
	 sprintf(all,"accel x:%0.2f,y:%0.2f,z:%0.2f\ngyro x:%0.2f,y:%0.2f,z:%0.2f",ACCEL_XOUT,ACCEL_YOUT,ACCEL_ZOUT,GYRO_XOUT,GYRO_YOUT,GYRO_ZOUT);
	 
	 sprintf(acceleration_x,"x:%0.2f",ACCEL_XOUT);
	 sprintf(acceleration_y,"y:%0.2f",ACCEL_YOUT);
	 sprintf(acceleration_z,"z:%0.2f",ACCEL_ZOUT);
	  
	 sprintf(gyroscope_x,"x:%0.2f",GYRO_XOUT);
	 sprintf(gyroscope_y,"y:%0.2f",GYRO_YOUT);
	 sprintf(gyroscope_z,"z:%0.2f",GYRO_ZOUT);
	  
	  
	 
	// HAL_UART_Transmit_IT(&huart2,(uint8_t*)gyroscope,strlen(acceleration)); 

	 
	  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
  {
	  HAL_Delay(10);
	  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
	  {
		  flag+=1;
		  if(flag>1)
		  {flag=0;}
		  while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET){};
	  }
  }
	static uint32_t last_display_time = 0;
if(HAL_GetTick() - last_display_time > 100) { // 每100ms更新一次显示
    last_display_time = HAL_GetTick();
	OLED_NewFrame();
  if(flag==0)
  {
	  OLED_PrintString(0,0,"acceleration",&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,16,acceleration_x,&font16x16,OLED_COLOR_NORMAL);
      OLED_PrintString(0,32,acceleration_y,&font16x16,OLED_COLOR_NORMAL);
      OLED_PrintString(0,48,acceleration_z,&font16x16,OLED_COLOR_NORMAL);
  }
  else if(flag==1)
  {

	  OLED_PrintString(0,0,"gyroscope",&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,16,gyroscope_x,&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,32,gyroscope_y,&font16x16,OLED_COLOR_NORMAL);
	  OLED_PrintString(0,48,gyroscope_z,&font16x16,OLED_COLOR_NORMAL);
  }
	  OLED_ShowFrame();
    HAL_UART_Transmit_IT(&huart2,(uint8_t*)all,strlen(all));
  }

 
	  
	  
	  
	  
  /*if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
  {
	  HAL_Delay(10);
	  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
	  {
		  count+=1;
		  if(count>COUNT_MAX)
		  {count=0;}
		  while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET){};
	  }
  }*/
  
    /*if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET)
  {
	  HAL_Delay(10);
	  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET)
	  {
		  count-=1;
		  if(count<0)
		  {count=COUNT_MAX;}
		  while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13)==GPIO_PIN_RESET){};
	  }
  }*/
  
    //__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,150);
	
  
  
 /* OLED_NewFrame();

  sprintf(message,"angle:%d",angle);
  
  	static uint32_t last_display_time = 0;
if(HAL_GetTick() - last_display_time > 2000) { // 每50ms更新一次显示
    last_display_time = HAL_GetTick();

  if(angle>120)
  {
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
	  HAL_Delay(100);
	  
  }
  else if(angle<60)
  {
	  
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
	  HAL_Delay(100);
  }
   else if(60<=angle&&angle<=120)
  {
	  
	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,GPIO_PIN_RESET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);
	  HAL_Delay(100);
  }
  }*/
  /*if(angle>120)
  {
	  OLED_PrintString(0,0,"左偏角过大",&font16x16,OLED_COLOR_NORMAL);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
  }
  else if(angle<30)
  {
	  OLED_PrintString(0,0,"右偏角过大",&font16x16,OLED_COLOR_NORMAL);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET);
  }
   else if(30<=angle&&angle<=120)
  {
	  OLED_PrintString(0,0,"姿态正常",&font16x16,OLED_COLOR_NORMAL);
	  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);
  }*/
  
  //OLED_PrintString(0,20,"右偏角过大",&font16x16,OLED_COLOR_NORMAL);
  //OLED_PrintString(0,40,"姿态正常",&font16x16,OLED_COLOR_NORMAL);

   /*if(angle>120)
  {
	  OLED_PrintString(0,0,"左偏角过大",&font16x16,OLED_COLOR_NORMAL);
	 
	  
  }
  else if(angle<60)
  {
	  OLED_PrintString(0,0,"右偏角过大",&font16x16,OLED_COLOR_NORMAL);
	  
  }
   else if(60<=angle&&angle<=120)
  {
	  OLED_PrintString(0,0,"姿态正常",&font16x16,OLED_COLOR_NORMAL);
	  
  }
  OLED_PrintString(0,20,message,&font16x16,OLED_COLOR_NORMAL);
  //OLED_PrintString(0,40,mesg,&font16x16,OLED_COLOR_NORMAL);
  
  OLED_ShowFrame();*/

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
