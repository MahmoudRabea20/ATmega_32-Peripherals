/*
 * Keypad_int.h
 *
 *  Created on: Feb 12, 2023
 *      Author: top
 */

#include "DIO_interface.h"
#include "stdTypes.h"
#include "errorState.h"
#include "Keypad_configuration.h"

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

ES_t Keypad_enuInit(void);
ES_t Keypad_enuGetPressedKey( u8* Copy_pu8PressedKey , u8 Copy_Au8ArrayCopy_Au8Array[KEYPAD_u8ROWS_NUMBER][KEYPAD_u8COLUMNS_NUMBER] );

#endif /* KEYPAD_INT_H_ */
