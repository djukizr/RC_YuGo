/**
  ******************************************************************************
  * @file    action_map.c
  * @brief   Implementation for action map.
  * @author  milos
  * @date    Sep 12, 2023
  ******************************************************************************
  */

#include "action_map.h"

void ActionMap_Initialize(ActionMap* action_map)
{
	action_map->capacity = 0;
}

void ActionMap_addAction(ActionMap* action_map, uint8_t action_type, Action action_func)
{
	action_map->array[action_map->capacity].type = action_type;
	action_map->array[action_map->capacity].action = action_func;
	action_map->capacity++;
}

void ActionMap_executeAction(ActionMap* action_map, uint8_t action_type)
{
	for (int i = 0; i < action_map->capacity; i++)
	{
		if (action_map->array[i].type == action_type)
		{
			action_map->array[i].action();
		}
	}
}
