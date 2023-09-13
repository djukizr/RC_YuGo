/**
  ******************************************************************************
  * @file    reciever_static.c
  * @brief	 Provides the user with functionality to add actions to adequate
  * 		 messages.
  * @note	 To use properly the receiver HAL_UART_RxCpltCallback needs to be adapted.
  * @author  milos
  * @date    Jan 20, 2023
  ******************************************************************************
  */

#include "receiver.h"

// TODO: Uncomment logger sectiones when logger is ported to project (Add option to disable logging in Logger)

/* Receiver function *******************************************************************/

Receiver receiver;

void Receiver_initialize(UART_HandleTypeDef* uart_handle)
{

	receiver.uart_handle = uart_handle;
	Message_initialize(&(receiver.message));
	ActionMap_Initialize(&(receiver.actions));

}

void Receiver_addAction(const uint8_t type, Action action)
{

	ActionMap_addAction(&(receiver.actions), type, action);

}

void Receiver_receive()
{

	HAL_UART_Receive_IT(receiver.uart_handle, receiver.message.content, TRANSMITION_MESSAGE_LENGTH);

}

void Receiver_onReceive()
{

	// TODO: Make sure to protect message with semaphore while it is used in action!
	receiver.message.size = receiver.message.content[1];
	ActionMap_executeAction(&(receiver.actions), receiver.message.content[0]);

}

void Receiver_flushMessage()
{

	Message_flush(&(receiver.message));

}
