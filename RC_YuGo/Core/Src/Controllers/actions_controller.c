/**
  ******************************************************************************
  * @file    actions.c
  * @brief   Implementation for actions.
  * @author  milos
  * @date    Sep 13, 2023
  ******************************************************************************
  */

#include <Controllers/actions_controller.h>

uint8_t joystick_action_trigger[1] = {'j'};

void joystick_action()
{
	JoystickPosition test = { .pos_x = 0, .pos_y = 0};
	test = Joystick_decodeMessage(receiver.message.content);
	int test2 = 0;
	test2 = 1;
}
