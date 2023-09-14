/**
  ******************************************************************************
  * @file    action_controller.h
  * @brief   Implementation for action controller.
  * @author  milos
  * @date    Sep 12, 2023
  ******************************************************************************
  */

#include "action_controller.h"

ActionMap action_map;

void JoystickAction()
{
	HAL_ADC_Start_DMA(joystick.adc_handle_, (uint32_t*)joystick.data_, 2);
}

void createActions()
{
	ActionMap_Initialize(&action_map);
	ActionMap_addAction(&action_map, 'j', JoystickAction);
}
