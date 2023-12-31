/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#define MOTOR_RR_IN2_Pin GPIO_PIN_13
#define MOTOR_RR_IN2_GPIO_Port GPIOF
#define MOTOR_RR_IN1_Pin GPIO_PIN_14
#define MOTOR_RR_IN1_GPIO_Port GPIOF
#define MOTOR_RL_IN2_Pin GPIO_PIN_15
#define MOTOR_RL_IN2_GPIO_Port GPIOF
#define MOTOR_RL_IN1_Pin GPIO_PIN_0
#define MOTOR_RL_IN1_GPIO_Port GPIOG
#define MOTOR_FL_IN1_Pin GPIO_PIN_7
#define MOTOR_FL_IN1_GPIO_Port GPIOE
#define MOTOR_FL_IN2_Pin GPIO_PIN_8
#define MOTOR_FL_IN2_GPIO_Port GPIOE
#define TIM_PWM_FL_Pin GPIO_PIN_9
#define TIM_PWM_FL_GPIO_Port GPIOE
#define TIM_PWM_FR_Pin GPIO_PIN_11
#define TIM_PWM_FR_GPIO_Port GPIOE
#define TIM_PWM_RL_Pin GPIO_PIN_13
#define TIM_PWM_RL_GPIO_Port GPIOE
#define TIM_PWM_RR_Pin GPIO_PIN_14
#define TIM_PWM_RR_GPIO_Port GPIOE
#define MOTOR_FR_IN1_Pin GPIO_PIN_15
#define MOTOR_FR_IN1_GPIO_Port GPIOE
#define MOTOR_FR_IN2_Pin GPIO_PIN_11
#define MOTOR_FR_IN2_GPIO_Port GPIOB
#define USART1_BL_TX_Pin GPIO_PIN_9
#define USART1_BL_TX_GPIO_Port GPIOA
#define USART1_BL_RX_Pin GPIO_PIN_10
#define USART1_BL_RX_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
