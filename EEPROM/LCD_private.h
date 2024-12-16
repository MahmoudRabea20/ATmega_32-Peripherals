/*
 * LCD_priv.h
 *
 *  Created on: Feb 6, 2023
 *      Author: top
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

static ES_t LCD_enuSetAllDirection(void);
static ES_t LCD_enuWriteNLatch(u8 Copy_u8Byte);
static ES_t LCD_enuSetEnablePulse(void);
static ES_t LCD_enuSetHalfPort(u8 Copy_u8HalfByte);

#define FOUR_BIT                         4
#define EIGHT_BIT                        8

#define LCD_u8BLOCKBYTES                 8

#define LCD_u8REMINDERNUMBER             10

#endif /* LCD_PRIVATE_H_ */
