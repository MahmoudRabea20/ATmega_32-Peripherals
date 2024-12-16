/*
 * LCD_config.h
 *
 *  Created on: Feb 6, 2023
 *      Author: top
 */

#include "DIO_interface.h"

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_MODE               FOUR_BIT

/*            Control pins                 */

#define LCD_RS_GRP             DIO_u8GROUP_B
#define LCD_RS_PIN             DIO_u8PIN_1

#define LCD_RW_GRP             DIO_u8GROUP_B
#define LCD_RW_PIN             DIO_u8PIN_2

#define LCD_ENABLE_GRP         DIO_u8GROUP_B
#define LCD_ENABLE_PIN         DIO_u8PIN_3

/*            Data pins                    */

#define LCD_DATA_GRP           DIO_u8GROUP_A

#define LCD_D0_GRP             DIO_u8GROUP_A
#define LCD_D0_PIN             DIO_u8PIN_0

#define LCD_D1_GRP             DIO_u8GROUP_A
#define LCD_D1_PIN             DIO_u8PIN_1

#define LCD_D2_GRP             DIO_u8GROUP_A
#define LCD_D2_PIN             DIO_u8PIN_2

#define LCD_D3_GRP             DIO_u8GROUP_A
#define LCD_D3_PIN             DIO_u8PIN_3

#define LCD_D4_GRP             DIO_u8GROUP_A
#define LCD_D4_PIN             DIO_u8PIN_4

#define LCD_D5_GRP             DIO_u8GROUP_A
#define LCD_D5_PIN             DIO_u8PIN_5

#define LCD_D6_GRP             DIO_u8GROUP_A
#define LCD_D6_PIN             DIO_u8PIN_6

#define LCD_D7_GRP             DIO_u8GROUP_A
#define LCD_D7_PIN             DIO_u8PIN_7


#endif /* LCD_CONFIG_H_ */
