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
#include <string.h>
#include <stdlib.h>

// TODO: Uncomment logger sectiones when logger is ported to project (Add option to disable logging in Logger)

/* Message function *******************************************************************/

// TODO: Move to Utility functions
void copyArray(uint8_t array_src[], uint32_t array_src_size, uint8_t array_dest[], uint32_t array_dest_size)
{

	if (array_src_size != array_dest_size)
	{
		//Logger_LogMessage("Cannot copy! Source and destination arrays must be of same size!\n");
		return;
	}

	for (int i = 0; i < array_src_size; i++)
	{
		array_dest[i] = array_src[i];
	}

}

void Message_initialize(Message* message, uint8_t message_ending_byte)
{
	message->size = 0;
	message->capacity = MESSAGE_CAPACITY;
	message->ending_byte = message_ending_byte;
	for (int i = 0; i < MESSAGE_CAPACITY; i++)
	{
		message->content[i] = 0x0;
	}
}

void Message_hardCopy(const Message* src, Message* dest)
{
	dest->size = src->size;
	dest->capacity = src->capacity;
	dest->ending_byte = src->ending_byte;
	for (int i = 0; i < src->size; i++)
	{
		dest->content[i] = src->content[i];
	}
}

void Message_static_fromString(char* str, Message* dest)
{

	if (strlen(str) > MESSAGE_CAPACITY - 1)
	{
		//Logger_LogMessage("String too long to create a message from it! \n");
		return;
	}

	dest->capacity = dest->size = strlen(str);
	memcpy(dest->content, str, dest->size + 1);
	dest->ending_byte = str[strlen(str) - 1];

}

void Message_flush(Message* msg)
{

	for (int i = 0; i < MESSAGE_CAPACITY; i++)
	{
		msg->content[i] = 0x0;
	}
	msg->size = 0;

}

/* Receiver function *******************************************************************/

Receiver receiver;

void Receiver_initialize(UART_HandleTypeDef* uart_handle, uint8_t message_ending_byte)
{

	receiver.uart_handle = uart_handle;
	Message_initialize(&(receiver.message), message_ending_byte);
	for (int i = 0; i < ACTIONS_CAPACITY; i++)
	{
		Message_initialize(&(receiver.action_trigger_messages[i]), message_ending_byte);
	}
	for (int i = 0; i < ACTIONS_CAPACITY; i++)
	{
		receiver.actions[i] = NULL;
	}
	receiver.actions_size = 0;
	receiver.actions_capacity = ACTIONS_CAPACITY;

}

void Receiver_addAction(const Message* trigger_message, ReceiverAction action)
{

	if (trigger_message->ending_byte != receiver.message.ending_byte)
	{
		//Logger_LogMessage("Action not added as ending byte does not match with the one in receiver!\n");
		return;
	}

	if (receiver.actions_size == receiver.actions_capacity)
	{
		//Logger_LogMessage("Cannot add any additional actions, action array is full!\n");
		return;
	}

	Message_hardCopy(trigger_message, &(receiver.action_trigger_messages[receiver.actions_size]));
	receiver.actions[receiver.actions_size] = action;
	receiver.actions_size++;

}

void Receiver_receive()
{

	if (receiver.message.size == receiver.message.capacity)
	{
		//Logger_LogMessage("Cannot receive any additional bytes, message array is full!\n");
		return;
	}

	HAL_UART_Receive_IT(receiver.uart_handle, &(receiver.message.content[receiver.message.size]), 1);

}

void Receiver_onReceive()
{

	if (receiver.message.content[receiver.message.size] == receiver.message.ending_byte)
	{
		for (int i = 0; i < receiver.actions_size; i++)
		{
			if (memcmp(receiver.action_trigger_messages[i].content, receiver.message.content, receiver.message.size) == 0)
			{
				receiver.actions[i]();
			}
		}
		Receiver_flushMessage();
	}
	else
	{
		receiver.message.size++;
	}

}

void Receiver_flushMessage()
{

	Message_flush(&(receiver.message));

}

void Receiver_flushActions()
{

	for (int i = 0; i < receiver.actions_size; i++)
	{
		Message_flush(&(receiver.action_trigger_messages[i]));
	}
	for (int i = 0; i < ACTIONS_CAPACITY; i++)
	{
		receiver.actions[i] = NULL;
	}
	receiver.actions_size = 0;

}
