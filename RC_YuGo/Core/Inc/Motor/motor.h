/**
  ******************************************************************************
  * @file    motor.h
  * @brief   This file contains all the functions used to control motors
  * 		 using L298N Driver.
  * @author  milos
  * @date    Dec 15, 2022
  ******************************************************************************
  */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f4xx_hal.h"

typedef enum {
	CLOCKWISE = 0,
	COUNTER_CLOCKWISE
} RotationDirection;

typedef enum {
	STOPPED = 0,
	RUNNING
} MotorState;

typedef struct {
	TIM_HandleTypeDef* pwm_timer_handle_;
	uint32_t pwm_timer_channel_;
	// Those parameters depend solely on timer configuration
	// and most of all on AutoReload register value
	uint32_t min_cnt_periods_;
	uint32_t max_cnt_periods_;

	// TODO: Think about separate struct for GPIO to go into utility
	GPIO_TypeDef* in1_gpio_;
	uint32_t in1_gpio_pin_;

	GPIO_TypeDef* in2_gpio_;
	uint32_t in2_gpio_pin_;

	RotationDirection rotation_direction_;
	MotorState motor_state_;
} Motor;

// Think about method which makes Motor on heap and returns the pointer
void Motor_initialize(Motor* motor,
		TIM_HandleTypeDef* pwm_timer_handle,
		uint32_t pwm_timer_channel,
		GPIO_TypeDef* in1_gpio,
		uint32_t in1_gpio_pin,
		GPIO_TypeDef* in2_gpio,
		uint32_t in2_gpio_pin,
		uint32_t min_cnt_periods,
		uint32_t max_cnt_periods
);

void Motor_setDirection(Motor* motor, RotationDirection rotation_direction);

void Motor_changeDirection(Motor* motor);

void Motor_setSpeed(Motor* motor, uint32_t speed_percentage);

void Motor_stop(Motor* motor);

#endif /* INC_MOTOR_H_ */
