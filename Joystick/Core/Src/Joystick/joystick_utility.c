/**
  ******************************************************************************
  * @file    joystick_utility.c
  * @brief   Implementation of joystick utilities.
  * @author  milos
  * @date    Sep 8, 2023
  ******************************************************************************
  */

#include "joystick_utility.h"

JoystickPosition Joystick_decodeMessage(uint8_t* message)
{
	JoystickPosition position = {.pos_x = 0, .pos_y = 0};
	uint8MessageToUint32(&(message[2]), &position.pos_x);
	uint8MessageToUint32(&(message[7]), &position.pos_y);
	return position;
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

void flushTransmitionMessage(uint8_t* message)
{
	for (int i = 0; i < TRANSMITION_MESSAGE_LENGTH; i++)
	{
		message[i] = '\0';
	}
}
