#include "./Dmx512/dmx_uart_03.h"

static volatile uint8_t dmxSendState_U03;

static TIM_HandleTypeDef *dmxHtim_U03;
static UART_HandleTypeDef *dmxHuart_U03;

static GPIO_InitTypeDef dmx_GPIO_InitStruct;

int DMX_U03_SetChannelValue(uint16_t channel, uint8_t value) {
	if (channel >= DMX_CHANNELS)
		return 0;
	dmxData_U03[channel + 1] = value;
	return 1;
}

uint8_t DMX_U03_GetChannelValue(uint16_t channel) {
	if (channel >= DMX_CHANNELS)
		return 0;
	return dmxData_U03[channel + 1];
}

void DMX_U03_DisableUsart(UART_HandleTypeDef *dmxHuart_U03) {
	HAL_NVIC_DisableIRQ(DMX_USART_03_IRQ);

	dmx_GPIO_InitStruct.Pin = DMX_TX_U03_Pin | DMX_RX_U03_Pin;
	dmx_GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	dmx_GPIO_InitStruct.Pull = GPIO_NOPULL;
	dmx_GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(DMX_TX_U03_GPIO_Port, &dmx_GPIO_InitStruct);
}

void DMX_U03_EnableUsart(UART_HandleTypeDef *dmxHuart_U03) {
	HAL_NVIC_EnableIRQ(DMX_USART_03_IRQ);

	dmx_GPIO_InitStruct.Pin = DMX_TX_U03_Pin | DMX_RX_U03_Pin;
	dmx_GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	dmx_GPIO_InitStruct.Pull = GPIO_PULLUP;
	dmx_GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	dmx_GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
	HAL_GPIO_Init(DMX_TX_U03_GPIO_Port, &dmx_GPIO_InitStruct);
}

void DMX_U03_Init(TIM_HandleTypeDef *htimHandle, UART_HandleTypeDef *huartHandle) {
	dmxHtim_U03 = htimHandle;
	dmxHuart_U03 = huartHandle;

	int i;
	for (i = 0; i < DMX_CHANNELS; i++)
		DMX_U03_SetChannelValue(i, 0);

	dmxSendState_U03 = DMX_STATE_BREAK;
	dmxHtim_U03->Init.Period = DMX_MARK_BREAK;

	HAL_NVIC_SetPriority(DMX_USART_03_IRQ, 5, 0);
	HAL_NVIC_EnableIRQ(DMX_USART_03_IRQ);


	DMX_U03_DisableUsart(dmxHuart_U03);

	HAL_GPIO_WritePin(DMX_TX_U03_GPIO_Port, DMX_TX_U03_Pin, GPIO_PIN_RESET);

	HAL_NVIC_SetPriority(DMX_TIM_IRQ, 5, 0);
	HAL_NVIC_EnableIRQ(DMX_TIM_IRQ);

	HAL_TIM_Base_Init(dmxHtim_U03);
	HAL_TIM_Base_Start_IT(dmxHtim_U03);
}

void DMX_U03_USART_IRQHandler(UART_HandleTypeDef *huartHandle) {
	// This function is called on USART interrupt
	HAL_UART_IRQHandler(dmxHuart_U03);

	if (USART_ISR_TC & DMX_USART_03->ISR) {
		// Finished sending data over USART. Next is Mark Before Break. Set TX high.
		// Account for the time it takes to setup GPIO output mode.
		dmxSendState_U03 = DMX_STATE_MBB;
		HAL_TIM_Base_Start(dmxHtim_U03);
		dmxHtim_U03->Instance->CNT = 0;
		DMX_U03_DisableUsart(dmxHuart_U03);
		HAL_GPIO_WritePin(DMX_TX_U03_GPIO_Port, DMX_TX_U03_Pin, GPIO_PIN_SET);
		HAL_TIM_Base_Stop(dmxHtim_U03);
		uint32_t elapsedTime = dmxHtim_U03->Instance->CNT;
		long time = DMX_MARK_BEFORE_BREAK - 1 - elapsedTime;
		dmxHtim_U03->Instance->ARR = (time > 0) ? time : 1;
		HAL_NVIC_EnableIRQ(DMX_TIM_IRQ);
		HAL_TIM_Base_Start_IT(dmxHtim_U03);
	}
}

void DMX_U03_TIM_IRQHandler(TIM_HandleTypeDef *htimHandle) {
	// This function is called on timer interrupt.
	if (dmxSendState_U03 == DMX_STATE_MBB) {
		// Mark Before Break finished. Next state is Break. Set TX Low.
		dmxSendState_U03 = DMX_STATE_BREAK;
		HAL_GPIO_WritePin(DMX_TX_U03_GPIO_Port, DMX_TX_U03_Pin, GPIO_PIN_RESET);
		dmxHtim_U03->Instance->ARR = DMX_MARK_BREAK;

	} else if (dmxSendState_U03 == DMX_STATE_BREAK) {
		// Break finished. Next state is Mark After Break. Set TX high.
		// Account for the time it takes to setup GPIO alternate function mode.
		dmxSendState_U03 = DMX_STATE_MAB;
		HAL_TIM_Base_Stop_IT(dmxHtim_U03);
		HAL_TIM_Base_Start(dmxHtim_U03);
		dmxHtim_U03->Instance->CNT = 0;
		HAL_GPIO_WritePin(DMX_TX_U03_GPIO_Port, DMX_TX_U03_Pin, GPIO_PIN_SET);
		DMX_U03_EnableUsart(dmxHuart_U03);
		uint32_t elapsedTime = dmxHtim_U03->Instance->CNT;
		long time = DMX_MARK_AFTER_BREAK - 1 - elapsedTime;
		dmxHtim_U03->Instance->ARR = (time > 0) ? time : 1;
		HAL_NVIC_EnableIRQ(DMX_TIM_IRQ);
		HAL_TIM_Base_Start_IT(dmxHtim_U03);

	} else if (dmxSendState_U03 == DMX_STATE_MAB) {
		// Mark After Break finished. Next send data over USART, then state Mark Before Break.
		dmxSendState_U03 = DMX_STATE_DMA;
		HAL_TIM_Base_Stop_IT(dmxHtim_U03);
		HAL_NVIC_DisableIRQ(DMX_TIM_IRQ);
		while (HAL_UART_Transmit_DMA(dmxHuart_U03, dmxData_U03, DMX_CHANNELS + 1) != HAL_OK)
			;
		HAL_UART_IRQHandler(dmxHuart_U03);
	}
}
