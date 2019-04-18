/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "./Dmx512/dmx512_Test.h"
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
osThreadId defaultTaskHandle;
osThreadId DMX_TX_U01Handle;
osThreadId DMX_TX_U02Handle;
osThreadId DMX_TX_U03Handle;
osThreadId DMX_TX_U04Handle;
osThreadId DMX_TX_U05Handle;
osThreadId DMX_TX_U06Handle;
osThreadId DMX_TX_U07Handle;
osThreadId DMX_TX_U08Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void Start_DMX_TX_U01(void const * argument);
void Start_DMX_TX_U02(void const * argument);
void Start_DMX_TX_U03(void const * argument);
void Start_DMX_TX_U04(void const * argument);
void Start_DMX_TX_U05(void const * argument);
void Start_DMX_TX_U06(void const * argument);
void Start_DMX_TX_U07(void const * argument);
void Start_DMX_TX_U08(void const * argument);

extern void MX_LWIP_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
return 0;
}
/* USER CODE END 1 */

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
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of DMX_TX_U01 */
  osThreadDef(DMX_TX_U01, Start_DMX_TX_U01, osPriorityNormal, 0, 128);
  DMX_TX_U01Handle = osThreadCreate(osThread(DMX_TX_U01), NULL);

  /* definition and creation of DMX_TX_U02 */
  osThreadDef(DMX_TX_U02, Start_DMX_TX_U02, osPriorityNormal, 0, 128);
  DMX_TX_U02Handle = osThreadCreate(osThread(DMX_TX_U02), NULL);

  /* definition and creation of DMX_TX_U03 */
  osThreadDef(DMX_TX_U03, Start_DMX_TX_U03, osPriorityNormal, 0, 128);
  DMX_TX_U03Handle = osThreadCreate(osThread(DMX_TX_U03), NULL);

  /* definition and creation of DMX_TX_U04 */
  osThreadDef(DMX_TX_U04, Start_DMX_TX_U04, osPriorityNormal, 0, 128);
  DMX_TX_U04Handle = osThreadCreate(osThread(DMX_TX_U04), NULL);

  /* definition and creation of DMX_TX_U05 */
  osThreadDef(DMX_TX_U05, Start_DMX_TX_U05, osPriorityNormal, 0, 128);
  DMX_TX_U05Handle = osThreadCreate(osThread(DMX_TX_U05), NULL);

  /* definition and creation of DMX_TX_U06 */
  osThreadDef(DMX_TX_U06, Start_DMX_TX_U06, osPriorityNormal, 0, 128);
  DMX_TX_U06Handle = osThreadCreate(osThread(DMX_TX_U06), NULL);

  /* definition and creation of DMX_TX_U07 */
  osThreadDef(DMX_TX_U07, Start_DMX_TX_U07, osPriorityNormal, 0, 128);
  DMX_TX_U07Handle = osThreadCreate(osThread(DMX_TX_U07), NULL);

  /* definition and creation of DMX_TX_U08 */
  osThreadDef(DMX_TX_U08, Start_DMX_TX_U08, osPriorityNormal, 0, 128);
  DMX_TX_U08Handle = osThreadCreate(osThread(DMX_TX_U08), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* init code for LWIP */
  MX_LWIP_Init();

  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
	  osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Start_DMX_TX_U01 */
/**
* @brief Function implementing the DMX_TX_U01 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_DMX_TX_U01 */
void Start_DMX_TX_U01(void const * argument)
{
  /* USER CODE BEGIN Start_DMX_TX_U01 */
  /* Infinite loop */
  for(;;)
  {
	DMX_TX_U01_Testing();
  }
  /* USER CODE END Start_DMX_TX_U01 */
}

/* USER CODE BEGIN Header_Start_DMX_TX_U02 */
/**
* @brief Function implementing the DMX_TX_U02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_DMX_TX_U02 */
void Start_DMX_TX_U02(void const * argument)
{
  /* USER CODE BEGIN Start_DMX_TX_U02 */
  /* Infinite loop */
  for(;;)
  {
	DMX_TX_U02_Testing();
  }
  /* USER CODE END Start_DMX_TX_U02 */
}

/* USER CODE BEGIN Header_Start_DMX_TX_U03 */
/**
* @brief Function implementing the DMX_TX_U03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_DMX_TX_U03 */
void Start_DMX_TX_U03(void const * argument)
{
  /* USER CODE BEGIN Start_DMX_TX_U03 */
  /* Infinite loop */
  for(;;)
  {
	DMX_TX_U03_Testing();
  }
  /* USER CODE END Start_DMX_TX_U03 */
}

/* USER CODE BEGIN Header_Start_DMX_TX_U04 */
/**
* @brief Function implementing the DMX_TX_U04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_DMX_TX_U04 */
void Start_DMX_TX_U04(void const * argument)
{
  /* USER CODE BEGIN Start_DMX_TX_U04 */
  /* Infinite loop */
  for(;;)
  {
	DMX_TX_U04_Testing();
  }
  /* USER CODE END Start_DMX_TX_U04 */
}

/* USER CODE BEGIN Header_Start_DMX_TX_U05 */
/**
* @brief Function implementing the DMX_TX_U05 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_DMX_TX_U05 */
void Start_DMX_TX_U05(void const * argument)
{
  /* USER CODE BEGIN Start_DMX_TX_U05 */
  /* Infinite loop */
  for(;;)
  {
	DMX_TX_U05_Testing();
  }
  /* USER CODE END Start_DMX_TX_U05 */
}

/* USER CODE BEGIN Header_Start_DMX_TX_U06 */
/**
* @brief Function implementing the DMX_TX_U06 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_DMX_TX_U06 */
void Start_DMX_TX_U06(void const * argument)
{
  /* USER CODE BEGIN Start_DMX_TX_U06 */
  /* Infinite loop */
  for(;;)
  {
	DMX_TX_U06_Testing();
  }
  /* USER CODE END Start_DMX_TX_U06 */
}

/* USER CODE BEGIN Header_Start_DMX_TX_U07 */
/**
* @brief Function implementing the DMX_TX_U07 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_DMX_TX_U07 */
void Start_DMX_TX_U07(void const * argument)
{
  /* USER CODE BEGIN Start_DMX_TX_U07 */
  /* Infinite loop */
  for(;;)
  {
	DMX_TX_U07_Testing();
  }
  /* USER CODE END Start_DMX_TX_U07 */
}

/* USER CODE BEGIN Header_Start_DMX_TX_U08 */
/**
* @brief Function implementing the DMX_TX_U08 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_DMX_TX_U08 */
void Start_DMX_TX_U08(void const * argument)
{
  /* USER CODE BEGIN Start_DMX_TX_U08 */
  /* Infinite loop */
  for(;;)
  {
	DMX_TX_U08_Testing();
  }
  /* USER CODE END Start_DMX_TX_U08 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
