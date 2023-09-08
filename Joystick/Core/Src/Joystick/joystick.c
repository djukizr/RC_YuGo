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

JoystickPosition Joystick_decodeMessage(Joystick* joystick)
{
	JoystickPosition position = {.pos_x = 0, .pos_y = 0};
	uint8MessageToUint32(&(joystick->message_[2]), &position.pos_x);
	uint8MessageToUint32(&(joystick->message_[7]), &position.pos_y);
	return position;
}

void Joystick_sendData(Joystick* joystick, UART_HandleTypeDef* huart_handle)
{
	Joystick_encodeMessage(joystick);
	// Until guarding the data with semaphore use polling
	HAL_UART_Transmit(huart_handle, joystick->message_, JOYSTICK_MESSAGE_LENGTH, 50);
}

void uint32ToUint8Message(uint8_t* message, uint32_t uint32number)
{
	// Pack in Big Endian manner
	int message_length = 4;
	for (int i = 0; i < message_length; i++)
	{
		int shift = (message_length - 1 - i) * 8;
		message[i] = (uint32number >> shift) & 0xFF;
	}
}

void uint8MessageToUint32(uint8_t* message, uint32_t* uint32number)
{
	int message_length = 4;
	*uint32number = 0;
	for (int i = 0; i < message_length; i++)
	{
		int shift = (message_length - 1 - i) * 8;
		*uint32number |= (message[i] << shift) & (0xFF << shift);
	}
}
