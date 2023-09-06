/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include <stdbool.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define	SET_SDA_LOW		HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_RESET)
#define	SET_SDA_HIGH	HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_SET)
#define	SET_SCL_LOW		HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_RESET)
#define	SET_SCL_HIGH	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET)
#define	READ_SDA			HAL_GPIO_ReadPin(GPIOA, SDA_Pin)
#define	MODE_READ 1
#define	MODE_WRITE 0
#define	ACK 0
#define	NACK 1

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t dataReceiveFromSlave;
uint8_t sizeDataReceiveFromSlave;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

void i2cInit();
void changeSDAModeToInput();
void changeSDAModeToOutput();
void i2cStart();
void i2cStop();
void clockSignal();
void resetSCLAndSDA();
bool checkAck();
bool sendData(uint8_t data);
uint8_t readData();
bool beginTrans(uint8_t addressSlave, uint8_t mode);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t addressSlave = 0x6E;
	i2cInit();
	
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		
		HAL_Delay(3000);
		bool checkSendAddress;
		do
		{
			checkSendAddress = beginTrans(addressSlave,MODE_WRITE);
		} while(checkSendAddress == NACK);
		
		if (checkSendAddress == ACK)
		{
			for (uint8_t i = 45; i < 50; ++i)
			{
				bool checkSendData;
				HAL_Delay(2000);
				do
				{
					checkSendData = sendData(i);
				} while (checkSendData == NACK);
				
			}
			
			i2cStop();
		}
		
		HAL_Delay(3000);
		do
		{
			checkSendAddress = beginTrans(addressSlave,MODE_READ);
		} while(checkSendAddress == NACK);
		
		if (checkSendAddress == ACK)
		{
			HAL_Delay(2000);
			dataReceiveFromSlave = readData();
			
			i2cStop();
		}
		
		
		
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SCL_Pin|SDA_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : SCL_Pin SDA_Pin */
  GPIO_InitStruct.Pin = SCL_Pin|SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

void i2cInit()
{
	HAL_GPIO_WritePin(GPIOA, SCL_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, SDA_Pin, GPIO_PIN_SET);
}

void changeSDAModeToOutput()
{
	GPIOA->CRL &= ~(GPIO_CRH_MODE8 | GPIO_CRH_MODE8);
	GPIOA->CRL |= GPIO_CRH_MODE8_0;
	GPIOA->BSRR = SDA_Pin;
}

void changeSDAModeToInput()
{
	GPIOA->CRL &= ~(GPIO_CRH_MODE8 | GPIO_CRH_MODE8);
	GPIOA->CRL |= GPIO_CRH_MODE8_1;
	GPIOA->BRR = SDA_Pin;
}
void i2cStart()
{
	resetSCLAndSDA();
	HAL_Delay(10);
	SET_SDA_LOW;
	HAL_Delay(10);
	SET_SCL_LOW;
	HAL_Delay(10);
	
	resetSCLAndSDA();
	
}

void i2cStop()
{
	
	
	SET_SDA_LOW;
	HAL_Delay(30);
	
	
	SET_SDA_HIGH;
	HAL_Delay(30);
	
	
}

void clockSignal()
{	
	SET_SCL_LOW;
	__ASM volatile("nop"::); // do nothing operation
	HAL_Delay(10);
	SET_SCL_HIGH;
	__ASM volatile("nop"::); // do nothing operation
}

void resetSCLAndSDA()
{
	HAL_Delay(10);
	SET_SDA_HIGH;
	HAL_Delay(10);
	SET_SCL_HIGH;
}

bool checkAck()
{
	resetSCLAndSDA();
	
	changeSDAModeToInput();
	HAL_Delay(60);
	if (READ_SDA == 0)
	{
		changeSDAModeToOutput();
		resetSCLAndSDA();
		return ACK;
	}
	else
	{
		changeSDAModeToOutput();
		resetSCLAndSDA();
		return NACK;
	}
}

bool sendData(uint8_t data)
{
	//data: 0xQWERTYUI
	HAL_Delay(20);
	uint8_t i = 0, x = 0;
	for (i = 0; i < 8; ++i)
	{
		x = data & 0x80; 
		// 0x80: 0x10000000
		// &: logic and which mean we compare bit by bit between data and 0x80
		// because 0x80 have only first bit is 1, rest is 0, so x is Q00000000, basically we only compare first bit
		// if first bit of data, for example here is Q, is 1, then x is 10000000
		// else, x is 00000000
		if ( x > 0)
		{
			SET_SDA_HIGH;
		}
		else
		{
			SET_SDA_LOW;
		}
		// after set up SDA base on x, now we send a clock signal, so that will activate interrupt in the slave
		// to let the slave know it's time to take bit data
		clockSignal();
		
		// then we moving our fisrt bit Q to last position, continue compare second bit and moving on until send all 8 bit
		data = data << 1;
		// now data is: 0xWERTYUIQ
		// note: this also depend on our mcu architecture is little endian or big endian
	}
	return checkAck();
}

uint8_t readData()
{
	uint8_t i = 0, sizeData = 0;
	uint8_t data = 0x00;
	changeSDAModeToInput();
	HAL_Delay(20);
	// our data is 0x00000000
	for (i = 0; i < 8; ++i)
	{
		
		clockSignal(); // activate an interrupt in the slave 
		HAL_Delay(10); // then wait for the slave to make a change SDA line base on bit data
		data = data << 1;
		data = data | READ_SDA; // now we use bitwise operation OR to take first bit data of the slave
														// for example, if first bit data of the slave is 1, now our data is 0x00000001
											// now we move to second bit, which mean now our data is 0x00000010
											// then keep moving on until we take all 8 bit data from slave
		++sizeData;
	}

	changeSDAModeToOutput();
	if (sizeData == 8)
	{
		SET_SDA_LOW;
		HAL_Delay(60);
	}
	else
	{
		SET_SDA_HIGH;
		HAL_Delay(60);
	}
	resetSCLAndSDA();
	return data;
}

bool beginTrans(uint8_t addressSlave, uint8_t mode)
{
	addressSlave = addressSlave << 1;
	uint8_t addressFrame = addressSlave | mode;
	i2cStart();
	HAL_Delay(20);
	return sendData(addressFrame);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
