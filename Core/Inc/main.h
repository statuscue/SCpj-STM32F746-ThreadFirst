/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "stm32f7xx_hal.h"

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
#define DMX_BAUD_RATE 250000
#define DMX_STATE_MBB 1
#define DMX_STATE_BREAK 2
#define DMX_STATE_MAB 4
#define DMX_STATE_DMA 8
#define DMX_MARK_BEFORE_BREAK 64
#define DMX_MARK_BREAK 176
#define DMX_MARK_AFTER_BREAK 64
#define DMX_CHANNELS 512
#define DMX_START_CODE 0
#define DMX_TIM_Prescaler 107
#define DMX_TIM_CounterPeriod_x32 0xFFFFFFFF
#define DMX_TIM_CounterPeriod_x16 0xFFFF
#define USER_Btn_Pin GPIO_PIN_13
#define USER_Btn_GPIO_Port GPIOC
#define DMX_DE_RE_U07_Pin GPIO_PIN_0
#define DMX_DE_RE_U07_GPIO_Port GPIOF
#define DMX_DE_RE_U08_Pin GPIO_PIN_1
#define DMX_DE_RE_U08_GPIO_Port GPIOF
#define DMX_RX_U07_Pin GPIO_PIN_6
#define DMX_RX_U07_GPIO_Port GPIOF
#define DMX_TX_U07_Pin GPIO_PIN_7
#define DMX_TX_U07_GPIO_Port GPIOF
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOH
#define RMII_MDC_Pin GPIO_PIN_1
#define RMII_MDC_GPIO_Port GPIOC
#define DMX_TX_U04_Pin GPIO_PIN_0
#define DMX_TX_U04_GPIO_Port GPIOA
#define RMII_REF_CLK_Pin GPIO_PIN_1
#define RMII_REF_CLK_GPIO_Port GPIOA
#define RMII_MDIO_Pin GPIO_PIN_2
#define RMII_MDIO_GPIO_Port GPIOA
#define DMX_RX_U02_Pin GPIO_PIN_3
#define DMX_RX_U02_GPIO_Port GPIOA
#define WiFi_SCK_Pin GPIO_PIN_5
#define WiFi_SCK_GPIO_Port GPIOA
#define WiFi_MISO_Pin GPIO_PIN_6
#define WiFi_MISO_GPIO_Port GPIOA
#define RMII_CRS_DV_Pin GPIO_PIN_7
#define RMII_CRS_DV_GPIO_Port GPIOA
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD0_GPIO_Port GPIOC
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_RXD1_GPIO_Port GPIOC
#define LED_DMX_TX_Pin GPIO_PIN_0
#define LED_DMX_TX_GPIO_Port GPIOB
#define DMX_DE_RE_U06_Pin GPIO_PIN_12
#define DMX_DE_RE_U06_GPIO_Port GPIOF
#define DMX_DE_RE_U01_Pin GPIO_PIN_13
#define DMX_DE_RE_U01_GPIO_Port GPIOF
#define DMX_DE_RE_U02_Pin GPIO_PIN_14
#define DMX_DE_RE_U02_GPIO_Port GPIOF
#define DMX_DE_RE_U03_Pin GPIO_PIN_15
#define DMX_DE_RE_U03_GPIO_Port GPIOF
#define DMX_DE_RE_U04_Pin GPIO_PIN_0
#define DMX_DE_RE_U04_GPIO_Port GPIOG
#define DMX_DE_RE_U05_Pin GPIO_PIN_1
#define DMX_DE_RE_U05_GPIO_Port GPIOG
#define RMII_TXD1_Pin GPIO_PIN_13
#define RMII_TXD1_GPIO_Port GPIOB
#define LED_DMX_RX_Pin GPIO_PIN_14
#define LED_DMX_RX_GPIO_Port GPIOB
#define DMX_TX_U03_Pin GPIO_PIN_8
#define DMX_TX_U03_GPIO_Port GPIOD
#define DMX_RX_U03_Pin GPIO_PIN_9
#define DMX_RX_U03_GPIO_Port GPIOD
#define LCD_SCL_Pin GPIO_PIN_12
#define LCD_SCL_GPIO_Port GPIOD
#define LCD_SDA_Pin GPIO_PIN_13
#define LCD_SDA_GPIO_Port GPIOD
#define USB_PowerSwitchOn_Pin GPIO_PIN_6
#define USB_PowerSwitchOn_GPIO_Port GPIOG
#define USB_OverCurrent_Pin GPIO_PIN_7
#define USB_OverCurrent_GPIO_Port GPIOG
#define DMX_TX_U06_Pin GPIO_PIN_6
#define DMX_TX_U06_GPIO_Port GPIOC
#define DMX_RX_U06_Pin GPIO_PIN_7
#define DMX_RX_U06_GPIO_Port GPIOC
#define DMX_TX_U01_Pin GPIO_PIN_9
#define DMX_TX_U01_GPIO_Port GPIOA
#define DMX_RX_U01_Pin GPIO_PIN_10
#define DMX_RX_U01_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define DMX_RX_U04_Pin GPIO_PIN_11
#define DMX_RX_U04_GPIO_Port GPIOC
#define DMX_TX_U05_Pin GPIO_PIN_12
#define DMX_TX_U05_GPIO_Port GPIOC
#define DMX_RX_U05_Pin GPIO_PIN_2
#define DMX_RX_U05_GPIO_Port GPIOD
#define DMX_TX_U02_Pin GPIO_PIN_5
#define DMX_TX_U02_GPIO_Port GPIOD
#define RMII_TX_EN_Pin GPIO_PIN_11
#define RMII_TX_EN_GPIO_Port GPIOG
#define RMII_TXD0_Pin GPIO_PIN_13
#define RMII_TXD0_GPIO_Port GPIOG
#define SW0_Pin GPIO_PIN_3
#define SW0_GPIO_Port GPIOB
#define WiFi_MOSI_Pin GPIO_PIN_5
#define WiFi_MOSI_GPIO_Port GPIOB
#define LED_ARTNET_TXRX_Pin GPIO_PIN_7
#define LED_ARTNET_TXRX_GPIO_Port GPIOB
#define DMX_RX_U08_Pin GPIO_PIN_0
#define DMX_RX_U08_GPIO_Port GPIOE
#define DMX_TX_U08_Pin GPIO_PIN_1
#define DMX_TX_U08_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */
#define DMX_USART_01_IRQ USART1_IRQn
#define DMX_USART_01 USART1
#define DMX_USART_02_IRQ USART2_IRQn
#define DMX_USART_02 USART2
#define DMX_USART_03_IRQ USART3_IRQn
#define DMX_USART_03 USART3
#define DMX_USART_04_IRQ UART4_IRQn
#define DMX_USART_04 UART4
#define DMX_USART_05_IRQ UART5_IRQn
#define DMX_USART_05 UART5
#define DMX_USART_06_IRQ USART6_IRQn
#define DMX_USART_06 USART6
#define DMX_USART_07_IRQ UART7_IRQn
#define DMX_USART_07 UART7
#define DMX_USART_08_IRQ UART8_IRQn
#define DMX_USART_08 UART8

#define DMX_TIM_IRQ TIM2_IRQn
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
