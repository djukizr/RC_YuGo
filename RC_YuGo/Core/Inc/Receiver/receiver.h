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

#include "stm32f4xx_hal.h"

typedef void(*ReceiverAction)(void);

// TODO: Move to Utility functions
void copyArray(uint8_t array1[], uint32_t array1_size, uint8_t array2[], uint32_t array2_size);

/* Message function *******************************************************************/

#define MESSAGE_CAPACITY 30

typedef struct {
	uint8_t content[MESSAGE_CAPACITY];
	uint16_t size;
	uint16_t capacity;
	uint8_t ending_byte; // TODO: Think if it is more appropriate to have this ending_byte in receiver
} Message;

// Do not forget to release memory after hard copy !!!
void Message_initialize(Message* message, uint8_t message_ending_byte);

void Message_hardCopy(const Message* src, Message* dest);

void Message_flush(Message* msg);

/* Receiver function *******************************************************************/

#define ACTIONS_CAPACITY 10

typedef struct {
	UART_HandleTypeDef* uart_handle;

	// Message Attributes
	Message message;

	// Action Attributes
	Message action_trigger_messages[ACTIONS_CAPACITY];
	ReceiverAction actions[ACTIONS_CAPACITY];
	uint16_t actions_size;
	uint16_t actions_capacity;
} Receiver;

extern Receiver receiver;

// TODO: Think about returning success code
void Receiver_initialize(UART_HandleTypeDef* uart_handle, uint8_t message_ending_byte);

void Receiver_addAction(const Message* trigger_message, ReceiverAction action);

void Receiver_receive();

void Receiver_onReceive();

void Receiver_flushMessage();

void Receiver_flushActions();

#endif /* INC_RECEIVER_STATIC_H_ */
