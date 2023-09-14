/**
  ******************************************************************************
  * @file    action_controller.h
  * @brief   Interface for action controller.
  * @author  milos
  * @date    Sep 12, 2023
  ******************************************************************************
  */

#ifndef INC_CONTROLLERS_ACTION_CONTROLLER_H_
#define INC_CONTROLLERS_ACTION_CONTROLLER_H_

#include "stm32f1xx_hal.h"

#include "action_map.h"
#include "joystick.h"

extern ActionMap action_map;
extern uint8_t action_data[1];

void createActions();

#endif /* INC_CONTROLLERS_ACTION_CONTROLLER_H_ */
