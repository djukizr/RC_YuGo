/**
  ******************************************************************************
  * @file    motor_controller.h
  * @brief   Interface for motor controller.
  * @author  milos
  * @date    Sep 13, 2023
  ******************************************************************************
  */

#ifndef INC_CONTROLLERS_MOTOR_CONTROLLER_H_
#define INC_CONTROLLERS_MOTOR_CONTROLLER_H_

#include "tim.h"

#include "motor.h"

extern Motor motor_fl;
extern Motor motor_fr;
extern Motor motor_rl;
extern Motor motor_rr;

void intializeMotors();

void stopMotors();
void goForward();
void goBackwards();
void turnLeftForward();
void turnRightForward();
void turnLeftBackwards();
void turnRightBackwards();

#endif /* INC_CONTROLLERS_MOTOR_CONTROLLER_H_ */
