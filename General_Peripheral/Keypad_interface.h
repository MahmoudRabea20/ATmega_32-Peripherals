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
ES_t Keypad_enuGetPressedKey( u8* Copy_pu8PressedKey);

#define Keypad_NOT_PREESED				0xff

#endif /* KEYPAD_INT_H_ */
