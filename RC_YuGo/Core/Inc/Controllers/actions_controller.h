/**
  ******************************************************************************
  * @file    actions_controller.h
  * @brief   Interface for actions.
  * @author  milos
  * @date    Sep 13, 2023
  ******************************************************************************
  */

#ifndef INC_ACTIONS_ACTIONS_H_
#define INC_ACTIONS_ACTIONS_H_

#include <stdbool.h>

#include "joystick_utility.h"
#include "receiver.h"
#include "motor_controller.h"

extern uint8_t joystick_action_trigger[1];

void joystickAction();

#endif /* INC_ACTIONS_ACTIONS_H_ */
