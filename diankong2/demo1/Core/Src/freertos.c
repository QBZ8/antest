/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define flag (1<<0)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for NumTask */
osThreadId_t NumTaskHandle;
const osThreadAttr_t NumTask_attributes = {
  .name = "NumTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for KeyTask */
osThreadId_t KeyTaskHandle;
const osThreadAttr_t KeyTask_attributes = {
  .name = "KeyTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh,
};
/* Definitions for LightTask */
osThreadId_t LightTaskHandle;
const osThreadAttr_t LightTask_attributes = {
  .name = "LightTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
};
/* Definitions for JudgeTask0 */
osThreadId_t JudgeTask0Handle;
const osThreadAttr_t JudgeTask0_attributes = {
  .name = "JudgeTask0",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityAboveNormal,
};
/* Definitions for LEDQueue */
osMessageQueueId_t LEDQueueHandle;
const osMessageQueueAttr_t LEDQueue_attributes = {
  .name = "LEDQueue"
};
/* Definitions for KeyEvent */
osEventFlagsId_t KeyEventHandle;
const osEventFlagsAttr_t KeyEvent_attributes = {
  .name = "KeyEvent"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartNumTask(void *argument);
void StartKeyTask(void *argument);
void StartLightTask(void *argument);
void StartJudgeTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of LEDQueue */
  LEDQueueHandle = osMessageQueueNew (16, sizeof(uint32_t), &LEDQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of NumTask */
  NumTaskHandle = osThreadNew(StartNumTask, NULL, &NumTask_attributes);

  /* creation of KeyTask */
  KeyTaskHandle = osThreadNew(StartKeyTask, NULL, &KeyTask_attributes);

  /* creation of LightTask */
  LightTaskHandle = osThreadNew(StartLightTask, NULL, &LightTask_attributes);

  /* creation of JudgeTask0 */
  JudgeTask0Handle = osThreadNew(StartJudgeTask, NULL, &JudgeTask0_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Create the event(s) */
  /* creation of KeyEvent */
  KeyEventHandle = osEventFlagsNew(&KeyEvent_attributes);

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartNumTask */
/**
  * @brief  Function implementing the NumTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartNumTask */
void StartNumTask(void *argument)
{
  /* USER CODE BEGIN StartNumTask */
  /* Infinite loop */
	uint32_t  count=0;
	uint32_t  led=1;
	uint32_t  data=0;

	
  for(;;)
  {
	if(count>5)
	{
		count=0;
		led=led+1;
		if(led>5)
		{
			led=1;
		}
	}
	else{
	count=count+1;
	}
	

	data=led*200;
	osMessageQueuePut(LEDQueueHandle,&data,0,osWaitForever);
	
    osDelay(100);
  }
  /* USER CODE END StartNumTask */
}

/* USER CODE BEGIN Header_StartKeyTask */
/**
* @brief Function implementing the KeyTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartKeyTask */
void StartKeyTask(void *argument)
{
  /* USER CODE BEGIN StartKeyTask */
	uint32_t btncount=0;
  /* Infinite loop */
  for(;;)
  {
	  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
	  {
		  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
		  {
			  btncount++;
			  if(btncount%2==1)
			  {
				  osEventFlagsSet(KeyEventHandle,flag);
				  
			  }
			  else
			  {
				  osEventFlagsClear(KeyEventHandle,flag);
			  }
		  }
		  while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12)==GPIO_PIN_RESET)
		  {
			  osDelay(10);
		  }
	  }
	  else
	  {
		  osDelay(10);
	  }
  }
  /* USER CODE END StartKeyTask */
}

/* USER CODE BEGIN Header_StartLightTask */
/**
* @brief Function implementing the LightTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLightTask */
void StartLightTask(void *argument)
{
  /* USER CODE BEGIN StartLightTask */
	uint32_t data=0;
	uint16_t time=0;
  /* Infinite loop */
  for(;;)
  {
	osMessageQueueGet(LEDQueueHandle,&data,NULL,osWaitForever);
	
	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);
    osDelay(data);
  }
  /* USER CODE END StartLightTask */
}

/* USER CODE BEGIN Header_StartJudgeTask */
/**
* @brief Function implementing the JudgeTask0 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartJudgeTask */
void StartJudgeTask(void *argument)
{
  /* USER CODE BEGIN StartJudgeTask */
  /* Infinite loop */
  for(;;)
  {
	 if(osEventFlagsGet(KeyEventHandle)==1)
	 {
		 vTaskSuspend(LightTaskHandle);
	 }
	else
	{
		vTaskResume(LightTaskHandle);
	}
	
    osDelay(10);
  }
  /* USER CODE END StartJudgeTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

