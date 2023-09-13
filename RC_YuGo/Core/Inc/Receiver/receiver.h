/**
  ******************************************************************************
  * @file    reciever_static.h
  * @brief   This file contains all externally used variables as well as
  * 		 all the function prototypes for the reciever.c file.
  * @note    This receiver is differs from the original one in the way
  * 		 memory is allocated (due to strange usage issues encountered).
  * 		 However, when possible try and use original receiver with dynamic
  * 		 memory allocation as it is more memory efficient.
  * @author  milos
  * @date    Jan 20, 2023
  ******************************************************************************
  */

#ifndef INC_RECEIVER_STATIC_H_
#define INC_RECEIVER_STATIC_H_

#include <string.h>
#include <stdlib.h>

#include "stm32f4xx_hal.h"
#include "action_map.h"
#include "message.h"

/* Receiver function *******************************************************************/

typedef struct {
	UART_HandleTypeDef* uart_handle;

	Message message;
	ActionMap actions;
} Receiver;

extern Receiver receiver;

// TODO: Think about returning success code
void Receiver_initialize(UART_HandleTypeDef* uart_handle);

void Receiver_addAction(const uint8_t type, Action action);

void Receiver_receive();

void Receiver_onReceive();

void Receiver_flushMessage();

#endif /* INC_RECEIVER_STATIC_H_ */
