#ifndef DMX_UART_08_H_
#define DMX_UART_08_H_

#include "stm32f7xx_hal.h"
#include "stm32f7xx.h"
#include "stm32f7xx_it.h"
#include "main.h"

uint8_t dmxData_U08[DMX_CHANNELS + 1];

int DMX_U08_SetChannelValue(uint16_t channel, uint8_t value);
uint8_t DMX_U08_GetChannelValue(uint16_t channel);
void DMX_U08_Init(TIM_HandleTypeDef *htimHandle, UART_HandleTypeDef *huartHandle);
void DMX_U08_TIM_IRQHandler(TIM_HandleTypeDef *htimHandle);
void DMX_U08_USART_IRQHandler(UART_HandleTypeDef *huartHandle);

#endif /* DMX_UART_08_H_ */
