/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define light_sensor_Pin GPIO_PIN_0
#define light_sensor_GPIO_Port GPIOI
#define LED_8_Pin GPIO_PIN_8
#define LED_8_GPIO_Port GPIOG
#define LED_7_Pin GPIO_PIN_7
#define LED_7_GPIO_Port GPIOG
#define LED_6_Pin GPIO_PIN_6
#define LED_6_GPIO_Port GPIOG
#define switch_catch_Pin GPIO_PIN_12
#define switch_catch_GPIO_Port GPIOH
#define LED_5_Pin GPIO_PIN_5
#define LED_5_GPIO_Port GPIOG
#define LED_4_Pin GPIO_PIN_4
#define LED_4_GPIO_Port GPIOG
#define LED_3_Pin GPIO_PIN_3
#define LED_3_GPIO_Port GPIOG
#define switch_conveyor_Pin GPIO_PIN_11
#define switch_conveyor_GPIO_Port GPIOH
#define switch_stop_Pin GPIO_PIN_10
#define switch_stop_GPIO_Port GPIOH
#define LED_2_Pin GPIO_PIN_2
#define LED_2_GPIO_Port GPIOG
#define KEY_Pin GPIO_PIN_2
#define KEY_GPIO_Port GPIOB
#define LED_1_Pin GPIO_PIN_0
#define LED_1_GPIO_Port GPIOG
#define LED_R_Pin GPIO_PIN_11
#define LED_R_GPIO_Port GPIOE
#define LED_G_Pin GPIO_PIN_14
#define LED_G_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
