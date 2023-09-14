/**
  ******************************************************************************
  * @file    motor.h
  * @brief   This file contains implementation of functions defined in motor.h
  * @author  milos
  * @date    Dec 15, 2022
  ******************************************************************************
  */

#include "motor.h"

void Motor_initialize(Motor* motor,
		TIM_HandleTypeDef* pwm_timer_handle,
		uint32_t pwm_timer_channel,
		GPIO_TypeDef* in1_gpio,
		uint32_t in1_gpio_pin,
		GPIO_TypeDef* in2_gpio,
		uint32_t in2_gpio_pin,
		uint32_t min_cnt_periods,
		uint32_t max_cnt_periods
)
{

	motor->pwm_timer_handle_ = pwm_timer_handle;
	motor->pwm_timer_channel_ = pwm_timer_channel;

	__HAL_TIM_SET_COMPARE(pwm_timer_handle, pwm_timer_channel, 0);
    HAL_GPIO_WritePin(in1_gpio, in1_gpio_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(in2_gpio, in2_gpio_pin, GPIO_PIN_RESET);
	motor->in1_gpio_ = in1_gpio;
	motor->in1_gpio_pin_ = in1_gpio_pin;
	motor->in2_gpio_ = in2_gpio;
	motor->in2_gpio_pin_ = in2_gpio_pin;
	motor->rotation_direction_ = CLOCKWISE;
	motor->motor_state_ = STOPPED;

	motor->min_cnt_periods_ = min_cnt_periods;
	motor->max_cnt_periods_ = max_cnt_periods;

	HAL_TIM_PWM_Start(pwm_timer_handle, pwm_timer_channel);

}

void Motor_setDirection(Motor* motor, RotationDirection rotation_direction)
{

	switch (rotation_direction)
	{
	case CLOCKWISE:
	    HAL_GPIO_WritePin(motor->in1_gpio_, motor->in1_gpio_pin_, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(motor->in2_gpio_, motor->in2_gpio_pin_, GPIO_PIN_RESET);
		break;
	case COUNTER_CLOCKWISE:
	    HAL_GPIO_WritePin(motor->in1_gpio_, motor->in1_gpio_pin_, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(motor->in2_gpio_, motor->in2_gpio_pin_, GPIO_PIN_SET);
		break;
	}
	motor->rotation_direction_ = rotation_direction;

}

void Motor_changeDirection(Motor* motor)
{

	if (motor->rotation_direction_ == CLOCKWISE)
	{
		Motor_setDirection(motor, COUNTER_CLOCKWISE);
	}
	else if (motor->rotation_direction_ == COUNTER_CLOCKWISE)
	{
		Motor_setDirection(motor, CLOCKWISE);
	}

}

void Motor_setSpeed(Motor* motor, uint32_t speed_percentage)
{
	// TODO: Make Car structure with run method which will set all Motor speedS
	Motor_setDirection(motor, motor->rotation_direction_);
	uint32_t cnt_periods = motor->min_cnt_periods_ + (motor->max_cnt_periods_ - motor->min_cnt_periods_) * speed_percentage / 100;
	__HAL_TIM_SET_COMPARE(motor->pwm_timer_handle_, motor->pwm_timer_channel_, cnt_periods);

}

void Motor_stop(Motor* motor)
{

    HAL_GPIO_WritePin(motor->in1_gpio_, motor->in1_gpio_pin_, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(motor->in2_gpio_, motor->in2_gpio_pin_, GPIO_PIN_RESET);
    __HAL_TIM_SET_COMPARE(motor->pwm_timer_handle_, motor->pwm_timer_channel_, 0);

}
