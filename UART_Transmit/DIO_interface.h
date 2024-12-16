/*
 * DIO_int.h
 *
 *  Created on: Feb 5, 2023
 *      Author: top
 */

#include "stdTypes.h"
#include "errorState.h"

#ifndef DIO_INT_H_
#define DIO_INT_H_


ES_t DIO_enuSetPinDirection(u8 Copy_u8GroupID,u8 Copy_u8PinID,u8 Copy_u8PinDirection);
ES_t DIO_enuSetPinValue(u8 Copy_u8GroupID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
ES_t DIO_enuSetPortValue(u8 Copy_u8GroupID,u8 Copy_u8PortValue);
ES_t DIO_enuSetPortDirection(u8 Copy_u8GroupID,u8 Copy_u8PortDirection);
ES_t DIO_enuGetPinValue(u8 Copy_u8GroupID,u8 Copy_u8PinID,u8* Copy_pu8PinValue);
ES_t DIO_enuTogglePinVlaue(u8 Copy_u8GroupID,u8 Copy_u8PinID);

#define DIO_u8GROUP_A    0
#define DIO_u8GROUP_B    1
#define DIO_u8GROUP_C    2
#define DIO_u8GROUP_D    3

#define DIO_u8PIN_0      0
#define DIO_u8PIN_1      1
#define DIO_u8PIN_2	     2
#define DIO_u8PIN_3      3
#define DIO_u8PIN_4      4
#define DIO_u8PIN_5      5
#define DIO_u8PIN_6      6
#define DIO_u8PIN_7      7

#define DIO_u8LOW_LEVEL  0
#define DIO_u8HIGH_LEVEL 1

#define DIO_u8BIT_MASK   1

#define DIO_u8INPUT		 0
#define DIO_u8OUTPUT     1

#define DIO_u8FLOAT	     0
#define DIO_u8PULL_UP	 1

#endif /* DIO_INT_H_ */
