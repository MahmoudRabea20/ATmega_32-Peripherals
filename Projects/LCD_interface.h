/*
 * LCD_int.h
 *
 *  Created on: Feb 6, 2023
 *      Author: top
 */

#include "stdTypes.h"
#include "errorState.h"

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);
ES_t LCD_enuWriteCommand(u8 Copy_u8CommandValue);
ES_t LCD_enuWriteData(u8 Copy_u8DataValue);
ES_t LCD_enuWriteString(const char* Copy_pchString);
ES_t LCD_enuWriteIntegerNumber(s32 Copy_s32Number);
ES_t LCD_enuGoToXYPosition(u8 Copy_u8XPosition,u8 Copy_u8YPosition);
ES_t LCD_enuWriteSpecialCharacter(u8 Copy_Au8LetterArray[] ,u8 Copy_u8BlockNumber,u8 Copy_u8XPosition ,u8 Copy_u8YPosition);

#endif /* LCD_INT_H_ */
