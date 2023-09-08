/**
  ******************************************************************************
  * @file    joystick.h
  * @brief   Interface for joystick driver.
  * @author  milos
  * @date    Jul 21, 2023
  ******************************************************************************
  */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

#include "stm32f1xx_hal.h"

#define JOYSTICK_BUFFER_LENGTH 2
#define JOYSTICK_MESSAGE_LENGTH 12

typedef struct {
	ADC_HandleTypeDef* adc_handle_;
	uint32_t data_[JOYSTICK_BUFFER_LENGTH];
	uint8_t message_[JOYSTICK_MESSAGE_LENGTH];
} Joystick;

typedef struct {
	uint32_t pos_x;
	uint32_t pos_y;
} JoystickPosition;

extern Joystick joystick;

void Joystick_Initialize(Joystick* joystick, ADC_HandleTypeDef* adc_handle);

uint32_t Joystick_getX(Joystick* joystick);

uint32_t Joystick_getY(Joystick* joystick);

void Joystick_encodeMessage(Joystick* joystick);

JoystickPosition Joystick_decodeMessage(Joystick* joystick);

void Joystick_sendData(Joystick* joystick, UART_HandleTypeDef* huart_handle);

/* Utility functions *********************************************/

void uint32ToUint8Message(uint8_t* message, uint32_t uint32number);

void uint8MessageToUint32(uint8_t* message, uint32_t* uint32number);

#endif /* INC_JOYSTICK_H_ */
