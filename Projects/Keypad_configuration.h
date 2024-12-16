/*
 * Keypad_config.h
 *
 *  Created on: Feb 12, 2023
 *      Author: top
 */

#include "DIO_interface.h"

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_u8GRP                DIO_u8GROUP_C


#define KEYPAD_u8R0_PIN             DIO_u8PIN_0
#define KEYPAD_u8R1_PIN             DIO_u8PIN_1
#define KEYPAD_u8R2_PIN             DIO_u8PIN_2
#define KEYPAD_u8R3_PIN             DIO_u8PIN_3

#define KEYPAD_u8C0_PIN             DIO_u8PIN_4
#define KEYPAD_u8C1_PIN             DIO_u8PIN_5
#define KEYPAD_u8C2_PIN             DIO_u8PIN_6
#define KEYPAD_u8C3_PIN             DIO_u8PIN_7

#define KEYPAD_u8ROWS_NUMBER        4
#define KEYPAD_u8COLUMNS_NUMBER     4

#define KEYPAD_u8NON_PRESSED     0xff

#define KEYPAD_Au8KEYS_VALUES       {{'A','B','C','/'},\
							        { 'D','E','F','X'},\
						            { 'G','H','I','-'},\
							        { 'C','0','=','+'}}




#endif /* KEYPAD_CONFIG_H_ */
