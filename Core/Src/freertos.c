/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId testTaskHandle;
osThreadId armTaskHandle;
osThreadId conveyorTaskHandle;
osThreadId detectTaskHandle;
osThreadId interactiveTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void test_task(void const * argument);
void arm_task(void const * argument);
void conveyor_task(void const * argument);
void detect_task(void const * argument);
void interactive_task(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

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

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of testTask */
  osThreadDef(testTask, test_task, osPriorityNormal, 0, 128);
  testTaskHandle = osThreadCreate(osThread(testTask), NULL);

  /* definition and creation of armTask */
  osThreadDef(armTask, arm_task, osPriorityIdle, 0, 512);
  armTaskHandle = osThreadCreate(osThread(armTask), NULL);

  /* definition and creation of conveyorTask */
  osThreadDef(conveyorTask, conveyor_task, osPriorityIdle, 0, 128);
  conveyorTaskHandle = osThreadCreate(osThread(conveyorTask), NULL);

  /* definition and creation of detectTask */
  osThreadDef(detectTask, detect_task, osPriorityIdle, 0, 128);
  detectTaskHandle = osThreadCreate(osThread(detectTask), NULL);

  /* definition and creation of interactiveTask */
  osThreadDef(interactiveTask, interactive_task, osPriorityIdle, 0, 128);
  interactiveTaskHandle = osThreadCreate(osThread(interactiveTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_test_task */
/**
  * @brief  Function implementing the testTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_test_task */
__weak void test_task(void const * argument)
{
  /* USER CODE BEGIN test_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END test_task */
}

/* USER CODE BEGIN Header_arm_task */
/**
* @brief Function implementing the armTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_arm_task */
__weak void arm_task(void const * argument)
{
  /* USER CODE BEGIN arm_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END arm_task */
}

/* USER CODE BEGIN Header_conveyor_task */
/**
* @brief Function implementing the conveyorTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_conveyor_task */
__weak void conveyor_task(void const * argument)
{
  /* USER CODE BEGIN conveyor_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END conveyor_task */
}

/* USER CODE BEGIN Header_detect_task */
/**
* @brief Function implementing the detectTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_detect_task */
__weak void detect_task(void const * argument)
{
  /* USER CODE BEGIN detect_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END detect_task */
}

/* USER CODE BEGIN Header_interactive_task */
/**
* @brief Function implementing the interactiveTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_interactive_task */
__weak void interactive_task(void const * argument)
{
  /* USER CODE BEGIN interactive_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END interactive_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
