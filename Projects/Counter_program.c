/*
 * Counter_prog.c
 *
 *  Created on: Feb 6, 2023
 *      Author: top
 */

#include <util/delay.h>

#include "Counter_private.h"
#include "HEXA_configuration.h"
#include "HEXA_interface.h"

ES_t Counter_enuInit(void)
{
	return HEXA_enuInit();
}

ES_t Counter_enuCount(u8 Copy_u8Start,u8 Copy_u8End)
{
	ES_t Local_enuErrorState = ES_NOK;
	u8 Local_u8StartOfRight = Copy_u8Start % Counter_u8REMINDERNUMBER ;
	u8 Local_u8End = Copy_u8End % Counter_u8REMINDERNUMBER;
	u8 Local_u8EndOfRight = Counter_u8MAXNUMBER;

	if(Copy_u8Start <= Copy_u8End )
	{
		for(u8 i = Copy_u8Start / Counter_u8REMINDERNUMBER ; i <= Copy_u8End / Counter_u8REMINDERNUMBER ; i++)
		{
			if( i != Copy_u8Start / Counter_u8REMINDERNUMBER )
			{
				Local_u8StartOfRight = 0;
			}
			if( i == Copy_u8End / Counter_u8REMINDERNUMBER )
			{
				Local_u8EndOfRight = Local_u8End ;
			}
			for(u8 j = Local_u8StartOfRight ; j <= Local_u8EndOfRight  ; j++)
			{
				for(u8 k=0 ; k <= 25 ; k++)
				{
					HEXA_enuPinDisable(RIGHT_SSG_GRP,RIGHT_SSG_ENABLE_PIN);
					HEXA_enuPinDisable(LEFT_SSG_GRP,LEFT_SSG_ENABLE_PIN);
					HEXA_enuWriteNumber(j);
					HEXA_enuPinEnable(RIGHT_SSG_GRP,RIGHT_SSG_ENABLE_PIN);
					_delay_ms(10);
					HEXA_enuPinDisable(RIGHT_SSG_GRP,RIGHT_SSG_ENABLE_PIN);
					HEXA_enuWriteNumber(i);
					HEXA_enuPinEnable(LEFT_SSG_GRP,LEFT_SSG_ENABLE_PIN);
					_delay_ms(10);
					HEXA_enuPinDisable(LEFT_SSG_GRP,LEFT_SSG_ENABLE_PIN);
				}

			}
		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}
