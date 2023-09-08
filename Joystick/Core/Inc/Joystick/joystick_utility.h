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

#include "stm32f1xx_hal.h"

#define JOYSTICK_MESSAGE_LENGTH 12

typedef struct {
	uint32_t pos_x;
	uint32_t pos_y;
} JoystickPosition;

JoystickPosition Joystick_decodeMessage(uint8_t* message);

void uint32ToUint8Message(uint8_t* message, uint32_t uint32number);

void uint8MessageToUint32(uint8_t* message, uint32_t* uint32number);

#endif /* INC_JOYSTICK_JOYSTICK_UTILITY_H_ */
