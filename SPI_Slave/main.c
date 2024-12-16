/*
 * main.c
 *
 *  Created on: Jun 27, 2023
 *      Author: top
 */

#include <util/delay.h>

#include "DIO_interface.h"
#include "SPI_Slave_interface.h"



int main()
{
	u8 Local_u8data=0;

	DIO_enuSetPinDirection(DIO_u8GROUP_C,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_C,DIO_u8PIN_7,DIO_u8OUTPUT);

	SPI_voidSlaveInit();

	while(1)
	{
		Local_u8data=SPI_u8Tranceive(3);

		if(Local_u8data == 5)
		{
			DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN_7,DIO_u8HIGH_LEVEL);
			DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN_0,DIO_u8LOW_LEVEL);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN_7,DIO_u8LOW_LEVEL);
			DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN_0,DIO_u8HIGH_LEVEL);
		}

	}

}

