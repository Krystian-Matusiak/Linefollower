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
#include "stm32f3xx_hal.h"

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
#define DIR1_M2_Pin GPIO_PIN_0
#define DIR1_M2_GPIO_Port GPIOF
#define DIR2_M2_Pin GPIO_PIN_1
#define DIR2_M2_GPIO_Port GPIOF
#define CZ_1_Pin GPIO_PIN_0
#define CZ_1_GPIO_Port GPIOA
#define CZ_2_Pin GPIO_PIN_1
#define CZ_2_GPIO_Port GPIOA
#define CZ_3_Pin GPIO_PIN_3
#define CZ_3_GPIO_Port GPIOA
#define CZ_4_Pin GPIO_PIN_4
#define CZ_4_GPIO_Port GPIOA
#define CZ_5_Pin GPIO_PIN_5
#define CZ_5_GPIO_Port GPIOA
#define CZ_6_Pin GPIO_PIN_6
#define CZ_6_GPIO_Port GPIOA
#define BATT_IN_Pin GPIO_PIN_7
#define BATT_IN_GPIO_Port GPIOA
#define PWM_M1_Pin GPIO_PIN_0
#define PWM_M1_GPIO_Port GPIOB
#define DIR1_M1_Pin GPIO_PIN_1
#define DIR1_M1_GPIO_Port GPIOB
#define DIR2_M1_Pin GPIO_PIN_8
#define DIR2_M1_GPIO_Port GPIOA
#define CS1_Pin GPIO_PIN_9
#define CS1_GPIO_Port GPIOA
#define CS2_Pin GPIO_PIN_10
#define CS2_GPIO_Port GPIOA
#define STBY_Pin GPIO_PIN_11
#define STBY_GPIO_Port GPIOA
#define PWM_M2_Pin GPIO_PIN_12
#define PWM_M2_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
