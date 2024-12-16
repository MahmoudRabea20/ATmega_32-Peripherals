/*
 * LED_int.h
 *
 *  Created on: Feb 5, 2023
 *      Author: top
 */

#include "errorState.h"
#include "stdTypes.h"

#ifndef LED_INT_H_
#define LED_INT_H_

ES_t LED_enuTurnOn(u8 Copy_u8GroupID,u8 Copy_u8PinID);
ES_t LED_enuTurnOff(u8 Copy_u8GroupID,u8 Copy_u8PinID);
ES_t LED_enuToggle(u8 Copy_u8GroupID,u8 Copy_u8PinID);

#define LED_u8OUTPUT       1

#define LED_u8HIGHLEVEL    1
#define LED_u8LOWLEVEL     0

#endif /* LED_INT_H_ */
