/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32l0xx_hal.h"

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
void Sys_Enter_Standby(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY_UP_Pin GPIO_PIN_13
#define KEY_UP_GPIO_Port GPIOC
#define KEY_DOWN_Pin GPIO_PIN_14
#define KEY_DOWN_GPIO_Port GPIOC
#define KEY_RIGHT_Pin GPIO_PIN_15
#define KEY_RIGHT_GPIO_Port GPIOC
#define KEY_SELECT_Pin GPIO_PIN_1
#define KEY_SELECT_GPIO_Port GPIOA
#define Debug_TX_Pin GPIO_PIN_2
#define Debug_TX_GPIO_Port GPIOA
#define KEY_L3_Pin GPIO_PIN_3
#define KEY_L3_GPIO_Port GPIOA
#define ADC_LY_Pin GPIO_PIN_4
#define ADC_LY_GPIO_Port GPIOA
#define ADC_LX_Pin GPIO_PIN_5
#define ADC_LX_GPIO_Port GPIOA
#define KEY_R3_Pin GPIO_PIN_6
#define KEY_R3_GPIO_Port GPIOA
#define ADC_RX_Pin GPIO_PIN_7
#define ADC_RX_GPIO_Port GPIOA
#define ADC_RY_Pin GPIO_PIN_0
#define ADC_RY_GPIO_Port GPIOB
#define BEEP_Pin GPIO_PIN_1
#define BEEP_GPIO_Port GPIOB
#define KEY_MODE_Pin GPIO_PIN_2
#define KEY_MODE_GPIO_Port GPIOB
#define MOTOR_L_Pin GPIO_PIN_10
#define MOTOR_L_GPIO_Port GPIOB
#define MOTOR_R_Pin GPIO_PIN_11
#define MOTOR_R_GPIO_Port GPIOB
#define KEY_FORK_Pin GPIO_PIN_12
#define KEY_FORK_GPIO_Port GPIOB
#define KEY_CIRCLE_Pin GPIO_PIN_13
#define KEY_CIRCLE_GPIO_Port GPIOB
#define KEY_SQUARE_Pin GPIO_PIN_14
#define KEY_SQUARE_GPIO_Port GPIOB
#define KEY_TRIANGLE_Pin GPIO_PIN_15
#define KEY_TRIANGLE_GPIO_Port GPIOB
#define KEY_START_Pin GPIO_PIN_8
#define KEY_START_GPIO_Port GPIOA
#define BLE_TX_Pin GPIO_PIN_9
#define BLE_TX_GPIO_Port GPIOA
#define BLE_RX_Pin GPIO_PIN_10
#define BLE_RX_GPIO_Port GPIOA
#define KEY_R2_Pin GPIO_PIN_11
#define KEY_R2_GPIO_Port GPIOA
#define KEY_R1_Pin GPIO_PIN_12
#define KEY_R1_GPIO_Port GPIOA
#define Debug_RX_Pin GPIO_PIN_15
#define Debug_RX_GPIO_Port GPIOA
#define LED_POWER_Pin GPIO_PIN_3
#define LED_POWER_GPIO_Port GPIOB
#define LED_MODE_Pin GPIO_PIN_4
#define LED_MODE_GPIO_Port GPIOB
#define KEY_L2_Pin GPIO_PIN_8
#define KEY_L2_GPIO_Port GPIOB
#define KEY_L1_Pin GPIO_PIN_9
#define KEY_L1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
