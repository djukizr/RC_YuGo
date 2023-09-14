/**
  ******************************************************************************
  * @file    actions_controller.c
  * @brief   Implementation for actions.
  * @author  milos
  * @date    Sep 13, 2023
  ******************************************************************************
  */

#include "actions_controller.h"

#define POS_LOWER_LIMMIT 1700
#define POS_UPPER_LIMMIT 3500

uint8_t joystick_action_trigger[1] = {'j'};

void joystickAction()
{
	JoystickPosition joystick_pos = Joystick_decodeMessage(receiver.message.content);

	bool pos_x_stop = joystick_pos.pos_x > POS_LOWER_LIMMIT && joystick_pos.pos_x < POS_UPPER_LIMMIT;
	bool pos_y_stop = joystick_pos.pos_y > POS_LOWER_LIMMIT && joystick_pos.pos_y < POS_UPPER_LIMMIT;
	bool pos_x_forward = joystick_pos.pos_x > POS_UPPER_LIMMIT;
	bool pos_y_right = joystick_pos.pos_y > POS_UPPER_LIMMIT;
	bool pos_x_backwards = joystick_pos.pos_x < POS_LOWER_LIMMIT;
	bool pos_y_left = joystick_pos.pos_y < POS_LOWER_LIMMIT;

	if (pos_x_stop && pos_y_stop)
	{
		stopMotors();
	}
	else if (pos_x_forward && pos_y_stop)
	{
		goForward();
	}
	else if (pos_x_backwards && pos_y_stop)
	{
		goBackwards();
	}
	else if (pos_y_right && (pos_x_forward || pos_x_stop))
	{
		turnRightForward();
	}
	else if (pos_y_left && (pos_x_forward || pos_x_stop))
	{
		turnLeftForward();
	}
	else if (pos_y_right && pos_x_backwards)
	{
		turnRightBackwards();
	}
	else if (pos_y_left && pos_x_backwards)
	{
		turnLeftBackwards();
	}
	else
	{
		// Safeguard
		stopMotors();
	}
}
