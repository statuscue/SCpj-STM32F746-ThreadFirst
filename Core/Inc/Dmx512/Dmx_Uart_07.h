#ifndef DMX_UART_07_H_
#define DMX_UART_07_H_

#include "stm32f7xx_hal.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include "main.h"

uint8_t dmxData_U07[DMX_CHANNELS + 1];

int DMX_U07_SetChannelValue(uint16_t channel, uint8_t value);
uint8_t DMX_U07_GetChannelValue(uint16_t channel);
void DMX_U07_Init(TIM_HandleTypeDef *htimHandle, UART_HandleTypeDef *huartHandle);
void DMX_U07_TIM_IRQHandler(TIM_HandleTypeDef *htimHandle);
void DMX_U07_USART_IRQHandler(UART_HandleTypeDef *huartHandle);

#endif /* DMX_UART_07_H_ */
