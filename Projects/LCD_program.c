/*
 * LCD_prog.c
 *
 *  Created on: Feb 6, 2023
 *      Author: top
 */

#include <util/delay.h>

#include "DIO_interface.h"
#include "DIO_private.h"
#include "LCD_configuration.h"
#include "LCD_interface.h"
#include "LCD_private.h"

ES_t LCD_enuSetAllDirection(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection( LCD_RS_GRP , LCD_RS_PIN , DIO_u8OUTPUT );
	DIO_enuSetPinDirection( LCD_RW_GRP , LCD_RW_PIN , DIO_u8OUTPUT );
	DIO_enuSetPinDirection( LCD_ENABLE_GRP , LCD_ENABLE_PIN , DIO_u8OUTPUT );

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPortDirection(LCD_DATA_GRP,0xff);

#elif LCD_MODE == FOUR_BIT

	DIO_enuSetPinDirection( LCD_D4_GRP , LCD_D4_PIN , DIO_u8OUTPUT );
	DIO_enuSetPinDirection( LCD_D5_GRP , LCD_D5_PIN , DIO_u8OUTPUT );
	DIO_enuSetPinDirection( LCD_D6_GRP , LCD_D6_PIN , DIO_u8OUTPUT );
	DIO_enuSetPinDirection( LCD_D7_GRP , LCD_D7_PIN , DIO_u8OUTPUT );

#endif


	return Local_enuErrorState;

}

ES_t LCD_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	LCD_enuSetAllDirection();
	_delay_ms(40);

#if LCD_MODE == EIGHT_BIT

	/* Function Set */
	LCD_enuWriteCommand(0b00111000);

#elif LCD_MODE == FOUR_BIT

	/* Set RS to zero */
	DIO_enuSetPinValue( LCD_RS_GRP , LCD_RS_PIN , DIO_u8LOW_LEVEL );

	/* Function Set */
	LCD_enuSetHalfPort(0b0010);
	LCD_enuSetEnablePulse();

	LCD_enuSetHalfPort(0b0010);
	LCD_enuSetEnablePulse();

	LCD_enuSetHalfPort(0b1000);
	LCD_enuSetEnablePulse();


#endif

	_delay_ms(1);
	/* Display ON/OFF Control */
	LCD_enuWriteCommand(0b00001100);
	_delay_ms(1);
	/* Display Clear */
	LCD_enuWriteCommand(0b00000001);
	_delay_ms(1);

	return Local_enuErrorState;
}

ES_t LCD_enuWriteCommand(u8 Copy_u8CommandValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Set RS to zero */
	DIO_enuSetPinValue( LCD_RS_GRP , LCD_RS_PIN , DIO_u8LOW_LEVEL );
	/* Write Command  */
	LCD_enuWriteNLatch(Copy_u8CommandValue);

	return Local_enuErrorState;
}

ES_t LCD_enuWriteData(u8 Copy_u8DataValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Set RS to one */
	DIO_enuSetPinValue( LCD_RS_GRP , LCD_RS_PIN , DIO_u8HIGH_LEVEL );
	LCD_enuWriteNLatch(Copy_u8DataValue);

	return Local_enuErrorState;
}

static ES_t LCD_enuWriteNLatch(u8 Copy_u8Byte)
{

	ES_t Local_enuErrorState = ES_NOK;

	/* Set RW to zero */
	DIO_enuSetPinValue( LCD_RW_GRP , LCD_RW_PIN , DIO_u8LOW_LEVEL );
	/* Write Data or Command */
#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinValue( LCD_D0_GRP , LCD_D0_PIN , (Copy_u8Byte >> LCD_D0_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D1_GRP , LCD_D1_PIN , (Copy_u8Byte >> LCD_D1_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D2_GRP , LCD_D2_PIN , (Copy_u8Byte >> LCD_D2_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D3_GRP , LCD_D3_PIN , (Copy_u8Byte >> LCD_D3_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D4_GRP , LCD_D4_PIN , (Copy_u8Byte >> LCD_D4_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D5_GRP , LCD_D5_PIN , (Copy_u8Byte >> LCD_D5_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D6_GRP , LCD_D6_PIN , (Copy_u8Byte >> LCD_D6_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D7_GRP , LCD_D7_PIN , (Copy_u8Byte >> LCD_D7_PIN) & DIO_u8BIT_MASK );

	/* Set Enable Pulse */
	LCD_enuSetEnablePulse();

#elif LCD_MODE == FOUR_BIT

	/* Send higher half of byte */
	DIO_enuSetPinValue( LCD_D4_GRP , LCD_D4_PIN , (Copy_u8Byte >> LCD_D4_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D5_GRP , LCD_D5_PIN , (Copy_u8Byte >> LCD_D5_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D6_GRP , LCD_D6_PIN , (Copy_u8Byte >> LCD_D6_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D7_GRP , LCD_D7_PIN , (Copy_u8Byte >> LCD_D7_PIN) & DIO_u8BIT_MASK );

	/* Set Enable Pulse */
	LCD_enuSetEnablePulse();

	/* Send lower half of byte */

	DIO_enuSetPinValue( LCD_D4_GRP , LCD_D4_PIN , (Copy_u8Byte >> LCD_D0_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D5_GRP , LCD_D5_PIN , (Copy_u8Byte >> LCD_D1_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D6_GRP , LCD_D6_PIN , (Copy_u8Byte >> LCD_D2_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D7_GRP , LCD_D7_PIN , (Copy_u8Byte >> LCD_D3_PIN) & DIO_u8BIT_MASK );

	/* Set Enable Pulse */
	LCD_enuSetEnablePulse();

#else
	Error : LCD configuration is wrong

#endif


	return Local_enuErrorState;
}

static ES_t LCD_enuSetHalfPort(u8 Copy_u8HalfByte)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue( LCD_D4_GRP , LCD_D4_PIN , (Copy_u8HalfByte >> LCD_D0_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D5_GRP , LCD_D5_PIN , (Copy_u8HalfByte >> LCD_D1_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D6_GRP , LCD_D6_PIN , (Copy_u8HalfByte >> LCD_D2_PIN) & DIO_u8BIT_MASK );
	DIO_enuSetPinValue( LCD_D7_GRP , LCD_D7_PIN , (Copy_u8HalfByte >> LCD_D3_PIN) & DIO_u8BIT_MASK );

	return Local_enuErrorState;
}

static ES_t LCD_enuSetEnablePulse(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinValue( LCD_ENABLE_GRP , LCD_ENABLE_PIN , DIO_u8HIGH_LEVEL );
	_delay_ms(1);
	DIO_enuSetPinValue( LCD_ENABLE_GRP , LCD_ENABLE_PIN , DIO_u8LOW_LEVEL );
	_delay_ms(2);

	return Local_enuErrorState;

}

ES_t LCD_enuWriteString(const char* Copy_pchString)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8Counter=0;

	if( Copy_pchString != NULL)
	{
		while(Copy_pchString[Local_u8Counter] != '\0')
		{
			LCD_enuWriteData(Copy_pchString[Local_u8Counter]);
			Local_u8Counter++;
		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = NULL_POINTER;
	}

	return Local_enuErrorState;

}


ES_t LCD_enuWriteIntegerNumber(s32 Copy_s32Number)
{
	ES_t Local_enuErrorState = ES_NOK;
	u32 Local_u32OppositedNumber=0;
	u8 Local_u8CurrentDigit;

	if(Copy_s32Number < 0)
	{
		Copy_s32Number *= -1;
		LCD_enuWriteString("-");
	}

	while( Copy_s32Number != 0 )
	{
		Local_u32OppositedNumber = Local_u32OppositedNumber * LCD_u8REMINDERNUMBER + Copy_s32Number % LCD_u8REMINDERNUMBER;
		Copy_s32Number /= LCD_u8REMINDERNUMBER;
	}

	while( Local_u32OppositedNumber != 0)
	{
		Local_u8CurrentDigit = Local_u32OppositedNumber % LCD_u8REMINDERNUMBER;
		LCD_enuWriteData( Local_u8CurrentDigit + 48 );
		Local_u32OppositedNumber /= LCD_u8REMINDERNUMBER ;
	}





	return Local_enuErrorState;

}

ES_t LCD_enuGoToXYPosition(u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8DDRAMAddress;

	if( Copy_u8YPosition == 0 || Copy_u8YPosition == 1)
	{

		Local_u8DDRAMAddress = Copy_u8XPosition + Copy_u8YPosition * 0x40 ;
		Local_u8DDRAMAddress = Local_u8DDRAMAddress | (DIO_u8BIT_MASK << DIO_u8PIN_7 );
		LCD_enuWriteCommand(Local_u8DDRAMAddress);


		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t LCD_enuWriteSpecialCharacter(u8 Copy_Au8LetterArray[] ,u8 Copy_u8BlockNumber,u8 Copy_u8XPosition ,u8 Copy_u8YPosition)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8CGRAMAddress;
	u8 Local_u8Iterator;

	Local_u8CGRAMAddress = Copy_u8BlockNumber * LCD_u8BLOCKBYTES ;
	Local_u8CGRAMAddress = Local_u8CGRAMAddress | (DIO_u8BIT_MASK << DIO_u8PIN_6 );
	Local_u8CGRAMAddress = Local_u8CGRAMAddress & (~(DIO_u8BIT_MASK << DIO_u8PIN_7 ));

	LCD_enuWriteCommand(Local_u8CGRAMAddress);

	for(Local_u8Iterator = 0 ; Local_u8Iterator < 8 ; Local_u8Iterator ++)
	{
		LCD_enuWriteData(Copy_Au8LetterArray[Local_u8Iterator] );
	}

	LCD_enuGoToXYPosition(Copy_u8XPosition,Copy_u8YPosition);

	LCD_enuWriteData(Copy_u8BlockNumber);

	return Local_enuErrorState;
}
