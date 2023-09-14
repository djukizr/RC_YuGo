/**
  ******************************************************************************
  * @file    motor_controller.c
  * @brief   Implementation for motor controller.
  * @author  milos
  * @date    Sep 13, 2023
  ******************************************************************************
  */

#include "motor_controller.h"

// TODO: With mobile app make variable motor speed
#define MOTOR_SPEED 60

Motor motor_fl;
Motor motor_fr;
Motor motor_rl;
Motor motor_rr;

void intializeMotors()
{
	// TODO: Move all constants to define
	Motor_initialize(&motor_fl, &htim1, TIM_CHANNEL_1,
		  MOTOR_FL_IN1_GPIO_Port, MOTOR_FL_IN1_Pin,
		  MOTOR_FL_IN2_GPIO_Port, MOTOR_FL_IN2_Pin,
		  60, 100);

	Motor_initialize(&motor_fr, &htim1, TIM_CHANNEL_2,
		  MOTOR_FR_IN1_GPIO_Port, MOTOR_FR_IN1_Pin,
		  MOTOR_FR_IN2_GPIO_Port, MOTOR_FR_IN2_Pin,
		  60, 100);

	Motor_initialize(&motor_rl, &htim1, TIM_CHANNEL_3,
		  MOTOR_RL_IN1_GPIO_Port, MOTOR_RL_IN1_Pin,
		  MOTOR_RL_IN2_GPIO_Port, MOTOR_RL_IN2_Pin,
		  60, 100);

	Motor_initialize(&motor_rr, &htim1, TIM_CHANNEL_4,
		  MOTOR_RR_IN1_GPIO_Port, MOTOR_RR_IN1_Pin,
		  MOTOR_RR_IN2_GPIO_Port, MOTOR_RR_IN2_Pin,
		  60, 100);
}

void setMotorsForward()
{
	Motor_setDirection(&motor_fl, CLOCKWISE);
	Motor_setDirection(&motor_fr, CLOCKWISE);
	Motor_setDirection(&motor_rl, CLOCKWISE);
	Motor_setDirection(&motor_rr, CLOCKWISE);
}

void setMotorsBackwards()
{
	Motor_setDirection(&motor_fl, COUNTER_CLOCKWISE);
	Motor_setDirection(&motor_fr, COUNTER_CLOCKWISE);
	Motor_setDirection(&motor_rl, COUNTER_CLOCKWISE);
	Motor_setDirection(&motor_rr, COUNTER_CLOCKWISE);
}

void stopMotors()
{
	// Setting speed to zero is not the same as stopping the Motors!
	Motor_stop(&motor_fl);
	Motor_stop(&motor_fr);
	Motor_stop(&motor_rl);
	Motor_stop(&motor_rr);
}

void goForward()
{
	setMotorsForward();

	Motor_setSpeed(&motor_fl, MOTOR_SPEED);
	Motor_setSpeed(&motor_fr, MOTOR_SPEED);
	Motor_setSpeed(&motor_rl, MOTOR_SPEED);
	Motor_setSpeed(&motor_rr, MOTOR_SPEED);
}

void goBackwards()
{
	setMotorsBackwards();

	Motor_setSpeed(&motor_fl, MOTOR_SPEED);
	Motor_setSpeed(&motor_fr, MOTOR_SPEED);
	Motor_setSpeed(&motor_rl, MOTOR_SPEED);
	Motor_setSpeed(&motor_rr, MOTOR_SPEED);
}

void turnLeftForward()
{
	setMotorsForward();

	Motor_stop(&motor_fl);
	Motor_setSpeed(&motor_fr, MOTOR_SPEED);
	Motor_stop(&motor_rl);
	Motor_setSpeed(&motor_rr, MOTOR_SPEED);
}

void turnRightForward()
{
	setMotorsForward();

	Motor_setSpeed(&motor_fl, MOTOR_SPEED);
	Motor_stop(&motor_fr);
	Motor_setSpeed(&motor_rl, MOTOR_SPEED);
	Motor_stop(&motor_rr);
}

void turnLeftBackwards()
{
	setMotorsBackwards();

	Motor_stop(&motor_fl);
	Motor_setSpeed(&motor_fr, MOTOR_SPEED);
	Motor_stop(&motor_rl);
	Motor_setSpeed(&motor_rr, MOTOR_SPEED);
}

void turnRightBackwards()
{
	setMotorsBackwards();

	Motor_setSpeed(&motor_fl, MOTOR_SPEED);
	Motor_stop(&motor_fr);
	Motor_setSpeed(&motor_rl, MOTOR_SPEED);
	Motor_stop(&motor_rr);
}
