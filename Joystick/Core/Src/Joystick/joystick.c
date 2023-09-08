/**
  ******************************************************************************
  * @file    joystick.c
  * @brief   Implementation of joystick driver.
  * @author  milos
  * @date    Jul 21, 2023
  ******************************************************************************
  */

#include "joystick.h"

Joystick joystick;

void Joystick_Initialize(Joystick* joystick, ADC_HandleTypeDef* adc_handle)
{
	joystick->adc_handle_ = adc_handle;
}

uint32_t Joystick_getX(Joystick* joystick)
{
	return joystick->data_[0];
}

uint32_t Joystick_getY(Joystick* joystick)
{
	return joystick->data_[1];
}

void Joystick_encodeMessage(Joystick* joystick)
{
	joystick->message_[0] = 'j';
	joystick->message_[1] = 'x';
	uint32ToUint8Message(&(joystick->message_[2]), joystick->data_[0]);
	joystick->message_[6] = 'y';
	uint32ToUint8Message(&(joystick->message_[7]), joystick->data_[1]);
	joystick->message_[11] = '\n';
}

void Joystick_sendData(Joystick* joystick, UART_HandleTypeDef* huart_handle)
{
	Joystick_encodeMessage(joystick);
	// Until guarding the data with semaphore use polling
	HAL_UART_Transmit(huart_handle, joystick->message_, JOYSTICK_MESSAGE_LENGTH, 50);
}
