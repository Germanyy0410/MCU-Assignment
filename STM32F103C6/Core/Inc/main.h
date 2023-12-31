/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_PEDESTRIAN_Pin GPIO_PIN_0
#define BUTTON_PEDESTRIAN_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_1
#define BUTTON_1_GPIO_Port GPIOA
#define BUTTON_2_Pin GPIO_PIN_4
#define BUTTON_2_GPIO_Port GPIOA
#define SEG2_Pin GPIO_PIN_5
#define SEG2_GPIO_Port GPIOA
#define SEG3_Pin GPIO_PIN_7
#define SEG3_GPIO_Port GPIOA
#define BUTTON_3_Pin GPIO_PIN_0
#define BUTTON_3_GPIO_Port GPIOB
#define SEG0_Pin GPIO_PIN_1
#define SEG0_GPIO_Port GPIOB
#define SEG1_Pin GPIO_PIN_2
#define SEG1_GPIO_Port GPIOB
#define D6_PEDESTRIAN_Pin GPIO_PIN_10
#define D6_PEDESTRIAN_GPIO_Port GPIOB
#define BUTTON_2_1_Pin GPIO_PIN_11
#define BUTTON_2_1_GPIO_Port GPIOB
#define LED_RED_1_Pin GPIO_PIN_13
#define LED_RED_1_GPIO_Port GPIOB
#define LED_AMBER_1_Pin GPIO_PIN_14
#define LED_AMBER_1_GPIO_Port GPIOB
#define LED_GREEN_1_Pin GPIO_PIN_15
#define LED_GREEN_1_GPIO_Port GPIOB
#define D7_PEDESTRIAN_Pin GPIO_PIN_8
#define D7_PEDESTRIAN_GPIO_Port GPIOA
#define SEG4_Pin GPIO_PIN_9
#define SEG4_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_10
#define LED_1_GPIO_Port GPIOA
#define SEG5_Pin GPIO_PIN_11
#define SEG5_GPIO_Port GPIOA
#define SEG6_Pin GPIO_PIN_12
#define SEG6_GPIO_Port GPIOA
#define LED_RED_2_Pin GPIO_PIN_13
#define LED_RED_2_GPIO_Port GPIOA
#define LED_AMBER_2_Pin GPIO_PIN_14
#define LED_AMBER_2_GPIO_Port GPIOA
#define LED_GREEN_2_Pin GPIO_PIN_15
#define LED_GREEN_2_GPIO_Port GPIOA
#define LED_2_Pin GPIO_PIN_3
#define LED_2_GPIO_Port GPIOB
#define LED_4_Pin GPIO_PIN_4
#define LED_4_GPIO_Port GPIOB
#define LED_3_Pin GPIO_PIN_5
#define LED_3_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_6
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_7
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_8
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_9
#define EN3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */
TIM_HandleTypeDef htim3;

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
