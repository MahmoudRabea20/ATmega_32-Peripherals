/*
 * Keypad_prog.c
 *
 *  Created on: Feb 12, 2023
 *      Author: top
 */

#include <util/delay.h>

#include "Keypad_configuration.h"
#include "Keypad_interface.h"

ES_t Keypad_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(KEYPAD_u8GRP,KEYPAD_u8R0_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(KEYPAD_u8GRP,KEYPAD_u8R1_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(KEYPAD_u8GRP,KEYPAD_u8R2_PIN,DIO_u8INPUT);
	DIO_enuSetPinDirection(KEYPAD_u8GRP,KEYPAD_u8R3_PIN,DIO_u8INPUT);

	DIO_enuSetPinDirection(KEYPAD_u8GRP,KEYPAD_u8C0_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KEYPAD_u8GRP,KEYPAD_u8C1_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KEYPAD_u8GRP,KEYPAD_u8C2_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(KEYPAD_u8GRP,KEYPAD_u8C3_PIN,DIO_u8OUTPUT);

	DIO_enuSetPinValue(KEYPAD_u8GRP,KEYPAD_u8C0_PIN,DIO_u8HIGH_LEVEL);
	DIO_enuSetPinValue(KEYPAD_u8GRP,KEYPAD_u8C1_PIN,DIO_u8HIGH_LEVEL);
	DIO_enuSetPinValue(KEYPAD_u8GRP,KEYPAD_u8C2_PIN,DIO_u8HIGH_LEVEL);
	DIO_enuSetPinValue(KEYPAD_u8GRP,KEYPAD_u8C3_PIN,DIO_u8HIGH_LEVEL);

	DIO_enuSetPinValue(KEYPAD_u8GRP,KEYPAD_u8R0_PIN,DIO_u8PULL_UP);
	DIO_enuSetPinValue(KEYPAD_u8GRP,KEYPAD_u8R1_PIN,DIO_u8PULL_UP);
	DIO_enuSetPinValue(KEYPAD_u8GRP,KEYPAD_u8R2_PIN,DIO_u8PULL_UP);
	DIO_enuSetPinValue(KEYPAD_u8GRP,KEYPAD_u8R3_PIN,DIO_u8PULL_UP);



	return Local_enuErrorState;
}

ES_t Keypad_enuGetPressedKey( u8* Copy_pu8PressedKey , u8 Copy_Au8Array[KEYPAD_u8ROWS_NUMBER][KEYPAD_u8COLUMNS_NUMBER] )
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8RowIter;
	u8 Local_u8ColumnIter;
	u8 Local_u8PinValue;
	*Copy_pu8PressedKey = KEYPAD_u8NON_PRESSED;
	u8 Local_Au8RowsPin[KEYPAD_u8ROWS_NUMBER] = {KEYPAD_u8R0_PIN,KEYPAD_u8R1_PIN,KEYPAD_u8R2_PIN,KEYPAD_u8R3_PIN};
	u8 Local_Au8ColumnsPin[KEYPAD_u8COLUMNS_NUMBER] = {KEYPAD_u8C0_PIN,KEYPAD_u8C1_PIN,KEYPAD_u8C2_PIN,KEYPAD_u8C3_PIN};


	for(Local_u8ColumnIter = 0 ; Local_u8ColumnIter < KEYPAD_u8COLUMNS_NUMBER ; Local_u8ColumnIter++ )
	{
		/*  set column to zero*/
		DIO_enuSetPinValue(KEYPAD_u8GRP, Local_Au8ColumnsPin[Local_u8ColumnIter] , DIO_u8LOW_LEVEL);

		for(Local_u8RowIter = 0 ; Local_u8RowIter < KEYPAD_u8ROWS_NUMBER ; Local_u8RowIter++)
		{
			DIO_enuGetPinValue(KEYPAD_u8GRP , Local_Au8RowsPin[Local_u8RowIter] ,&Local_u8PinValue);

			if( Local_u8PinValue == DIO_u8LOW_LEVEL )
			{
				_delay_ms(10); // for debouncing
				DIO_enuGetPinValue(KEYPAD_u8GRP , Local_Au8RowsPin[Local_u8RowIter] ,&Local_u8PinValue);
				if( Local_u8PinValue == DIO_u8LOW_LEVEL )
				{
					*Copy_pu8PressedKey = Copy_Au8Array[Local_u8RowIter][Local_u8ColumnIter];
					//to prevent the holding press ( pooling or busy waiting )
			    	while(Local_u8PinValue == DIO_u8LOW_LEVEL )
			        {
					    DIO_enuGetPinValue(KEYPAD_u8GRP , Local_Au8RowsPin[Local_u8RowIter] ,&Local_u8PinValue);

			        }

		        	return ES_OK;
		    	}
			}

		}

		DIO_enuSetPinValue(KEYPAD_u8GRP, Local_Au8ColumnsPin[Local_u8ColumnIter] , DIO_u8HIGH_LEVEL);
	}


	return Local_enuErrorState;
}
