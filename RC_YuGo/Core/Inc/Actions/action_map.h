/**
  ******************************************************************************
  * @file    action_map.h
  * @brief   Interface for action map.
  * @author  milos
  * @date    Sep 12, 2023
  ******************************************************************************
  */

#ifndef INC_ACTIONS_ACTION_MAP_H_
#define INC_ACTIONS_ACTION_MAP_H_

#include <stdint.h>

// TODO: Create real Hash Map

#define MAX_ACTION_NUMBER 30

typedef void(*Action)(void);

typedef struct {
	uint8_t type;
	Action action;
} ActionPair;

typedef struct {
	ActionPair array[MAX_ACTION_NUMBER];
	uint8_t capacity;
} ActionMap;

void ActionMap_Initialize(ActionMap* action_map);

void ActionMap_addAction(ActionMap* action_map, uint8_t action_type, Action action_func);

void ActionMap_executeAction(ActionMap* action_map, uint8_t action_type);

#endif /* INC_ACTIONS_ACTION_MAP_H_ */
