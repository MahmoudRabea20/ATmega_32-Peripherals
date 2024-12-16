/*
 * Keypad_prog.c
 *
 *  Created on: Feb 12, 2023
 *      Author: top
 */

#include <util/delay.h>
#include "ErrorState.h"
#include "stdTypes.h"

#include "DIO_interface.h"

#include "Keypad_configuration.h"
#include "Keypad_interface.h"

ES_t Keypad_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(KEYPAD_GRP,KEYPAD_R0_PIN,DIO_INPUT);
	DIO_enuSetPinDirection(KEYPAD_GRP,KEYPAD_R1_PIN,DIO_INPUT);
	DIO_enuSetPinDirection(KEYPAD_GRP,KEYPAD_R2_PIN,DIO_INPUT);
	DIO_enuSetPinDirection(KEYPAD_GRP,KEYPAD_R3_PIN,DIO_INPUT);

	DIO_enuSetPinDirection(KEYPAD_GRP,KEYPAD_C0_PIN,DIO_OUTPUT);
	DIO_enuSetPinDirection(KEYPAD_GRP,KEYPAD_C1_PIN,DIO_OUTPUT);
	DIO_enuSetPinDirection(KEYPAD_GRP,KEYPAD_C2_PIN,DIO_OUTPUT);
	DIO_enuSetPinDirection(KEYPAD_GRP,KEYPAD_C3_PIN,DIO_OUTPUT);

	DIO_enuSetPinValue(KEYPAD_GRP,KEYPAD_C0_PIN,DIO_HIGH_LEVEL);
	DIO_enuSetPinValue(KEYPAD_GRP,KEYPAD_C1_PIN,DIO_HIGH_LEVEL);
	DIO_enuSetPinValue(KEYPAD_GRP,KEYPAD_C2_PIN,DIO_HIGH_LEVEL);
	DIO_enuSetPinValue(KEYPAD_GRP,KEYPAD_C3_PIN,DIO_HIGH_LEVEL);

	DIO_enuSetPinValue(KEYPAD_GRP,KEYPAD_R0_PIN,DIO_PULL_UP);
	DIO_enuSetPinValue(KEYPAD_GRP,KEYPAD_R1_PIN,DIO_PULL_UP);
	DIO_enuSetPinValue(KEYPAD_GRP,KEYPAD_R2_PIN,DIO_PULL_UP);
	DIO_enuSetPinValue(KEYPAD_GRP,KEYPAD_R3_PIN,DIO_PULL_UP);



	return Local_enuErrorState;
}

ES_t Keypad_enuGetPressedKey( u8* Copy_pu8PressedKey)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8RowIter;
	u8 Local_u8ColumnIter;
	u8 Local_u8PinValue;
	*Copy_pu8PressedKey = Keypad_NOT_PREESED;
	u8 Local_Au8RowsPin[KEYPAD_u8ROWS_NUMBER] = {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
	u8 Local_Au8ColumnsPin[KEYPAD_u8COLUMNS_NUMBER] = {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};
	u8 Local_Au8ArrayOfValue[KEYPAD_u8ROWS_NUMBER][KEYPAD_u8COLUMNS_NUMBER] = KEYPAD_Au8KEYS_VALUES ;


	for(Local_u8ColumnIter = 0 ; Local_u8ColumnIter < KEYPAD_u8COLUMNS_NUMBER ; Local_u8ColumnIter++ )
	{
		/*  set column to zero*/
		DIO_enuSetPinValue(KEYPAD_GRP, Local_Au8ColumnsPin[Local_u8ColumnIter] , DIO_LOW_LEVEL);

		for(Local_u8RowIter = 0 ; Local_u8RowIter < KEYPAD_u8ROWS_NUMBER ; Local_u8RowIter++)
		{
			Local_u8PinValue = DIO_u8GetPinValue(KEYPAD_GRP , Local_Au8RowsPin[Local_u8RowIter] );

			if( Local_u8PinValue == DIO_LOW_LEVEL )
			{
				_delay_ms(10); // for debouncing
				Local_u8PinValue = DIO_u8GetPinValue(KEYPAD_GRP , Local_Au8RowsPin[Local_u8RowIter]);
				if( Local_u8PinValue == DIO_LOW_LEVEL )
				{

					*Copy_pu8PressedKey = Local_Au8ArrayOfValue[Local_u8RowIter][Local_u8ColumnIter];
					//to prevent the holding press ( pooling or busy waiting )
					while(Local_u8PinValue == DIO_LOW_LEVEL )
					{
						Local_u8PinValue = DIO_u8GetPinValue(KEYPAD_GRP , Local_Au8RowsPin[Local_u8RowIter] );
					}

					return ES_OK;
				}
			}

		}


		DIO_enuSetPinValue(KEYPAD_GRP, Local_Au8ColumnsPin[Local_u8ColumnIter] , DIO_HIGH_LEVEL);
	}


	return Local_enuErrorState;
}
