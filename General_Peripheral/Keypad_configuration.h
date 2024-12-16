/*
 * Keypad_config.h
 *
 *  Created on: Feb 12, 2023
 *      Author: top
 */

#include "DIO_interface.h"

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_GRP                  DIO_GROUP_B



#define KEYPAD_R0_PIN               DIO_PIN_0
#define KEYPAD_R1_PIN               DIO_PIN_1
#define KEYPAD_R2_PIN               DIO_PIN_2
#define KEYPAD_R3_PIN               DIO_PIN_3

#define KEYPAD_C0_PIN               DIO_PIN_4
#define KEYPAD_C1_PIN               DIO_PIN_5
#define KEYPAD_C2_PIN               DIO_PIN_6
#define KEYPAD_C3_PIN               DIO_PIN_7

#define KEYPAD_u8ROWS_NUMBER        4
#define KEYPAD_u8COLUMNS_NUMBER     4

#define KEYPAD_Au8KEYS_VALUES       {{ 7, 8, 9, '/'},\
							        {  4, 5, 6, 'X'},\
						            {  1, 2, 3, '-'},\
							        { 'C',0,'=','+'}}




#endif /* KEYPAD_CONFIG_H_ */
