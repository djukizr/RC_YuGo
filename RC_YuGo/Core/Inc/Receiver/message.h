/**
  ******************************************************************************
  * @file    message.h
  * @brief   Interface for message.
  * @author  milos
  * @date    Sep 13, 2023
  ******************************************************************************
  */

#ifndef INC_RECEIVER_MESSAGE_H_
#define INC_RECEIVER_MESSAGE_H_

#include "joystick_utility.h"

#ifndef TRANSMITION_MESSAGE_LENGTH
	#define TRANSMITION_MESSAGE_LENGTH 30
#endif

// TODO: Optimize memory usage somehow but still do it statically
#define MAX_MESSAGE_LENGTH TRANSMITION_MESSAGE_LENGTH

/* Message function *******************************************************************/

typedef struct {
	uint8_t content[MAX_MESSAGE_LENGTH];
	uint16_t size;
} Message;

// Do not forget to release memory after hard copy !!!
void Message_initialize(Message* message);

void Message_fromString(char* str, Message* dest);

void Message_hardCopy(const Message* src, Message* dest);

void Message_flush(Message* msg);

#endif /* INC_RECEIVER_MESSAGE_H_ */
