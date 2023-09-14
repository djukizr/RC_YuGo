/**
  ******************************************************************************
  * @file    message.c
  * @brief   Implementation for message.
  * @author  milos
  * @date    Sep 13, 2023
  ******************************************************************************
  */

#include "message.h"

/* Message function *******************************************************************/

void Message_initialize(Message* message)
{
	message->size = 0;
	for (int i = 0; i < MAX_MESSAGE_LENGTH; i++)
	{
		message->content[i] = 0x0;
	}
}

// TODO: Return Message structure instead of updating it as an argument.
void Message_fromString(char* str, Message* dest)
{

	if (strlen(str) > MAX_MESSAGE_LENGTH)
	{
		//Logger_LogMessage("String too long to create a message from it! \n");
		return;
	}

	dest->size = strlen(str);
	memcpy(dest->content, str, dest->size + 1);

}

void Message_hardCopy(const Message* src, Message* dest)
{
	dest->size = src->size;
	for (int i = 0; i < src->size; i++)
	{
		dest->content[i] = src->content[i];
	}
}

void Message_flush(Message* msg)
{

	for (int i = 0; i < MAX_MESSAGE_LENGTH; i++)
	{
		msg->content[i] = 0x0;
	}
	msg->size = 0;

}
