/**
  ******************************************************************************
  * @file    joystick_utility.h
  * @brief   Interface for joystick utilities.
  * @author  milos
  * @date    Sep 8, 2023
  ******************************************************************************
  */

#ifndef INC_JOYSTICK_JOYSTICK_UTILITY_H_
#define INC_JOYSTICK_JOYSTICK_UTILITY_H_

#include <stdint.h>

// TODO: Create a file with definitions to be shared between components
#define TRANSMITION_MESSAGE_LENGTH 30

typedef struct {
	uint32_t pos_x;
	uint32_t pos_y;
} JoystickPosition;

JoystickPosition Joystick_decodeMessage(uint8_t* message);

void uint32ToUint8Message(uint8_t* message, uint32_t uint32number);

void uint8MessageToUint32(uint8_t* message, uint32_t* uint32number);

void flushTransmitionMessage(uint8_t* message);

#endif /* INC_JOYSTICK_JOYSTICK_UTILITY_H_ */
