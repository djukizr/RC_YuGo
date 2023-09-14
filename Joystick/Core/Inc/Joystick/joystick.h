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
#include "joystick_utility.h"

#define JOYSTICK_BUFFER_LENGTH 2

typedef struct {
	ADC_HandleTypeDef* adc_handle_;
	uint32_t data_[JOYSTICK_BUFFER_LENGTH];
	uint8_t message_[TRANSMITION_MESSAGE_LENGTH];
} Joystick;

extern Joystick joystick;

void Joystick_Initialize(Joystick* joystick, ADC_HandleTypeDef* adc_handle);

uint32_t Joystick_getX(Joystick* joystick);

uint32_t Joystick_getY(Joystick* joystick);

void Joystick_encodeMessage(Joystick* joystick);

void Joystick_sendData(Joystick* joystick, UART_HandleTypeDef* huart_handle);

#endif /* INC_JOYSTICK_H_ */
