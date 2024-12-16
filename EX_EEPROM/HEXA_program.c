/*
 * HEXA_prog.c
 *
 *  Created on: Feb 6, 2023
 *      Author: top
 */

#include "DIO_private.h"
#include "HEXA_configuration.h"
#include "HEXA_interface.h"
#include "HEXA_private.h"

//u8 HEXA_u8NumberOfSegment[] = {0,1,2,3,4,5,6,7,8,9};

ES_t HEXA_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK ,flag=ES_OK, Local_enuArray[8];

	Local_enuArray[0]=DIO_enuSetPinDirection(RIGHT_SSG_GRP,RIGHT_SSG_ENABLE_PIN,DIO_u8OUTPUT);
	Local_enuArray[1]=DIO_enuSetPinDirection(LEFT_SSG_GRP,LEFT_SSG_ENABLE_PIN,DIO_u8OUTPUT);
	Local_enuArray[2]=DIO_enuSetPinDirection(SSG_GRP,BIT0_PIN,DIO_u8OUTPUT);
	Local_enuArray[3]=DIO_enuSetPinDirection(SSG_GRP,BIT1_PIN,DIO_u8OUTPUT);
	Local_enuArray[4]=DIO_enuSetPinDirection(SSG_GRP,BIT2_PIN,DIO_u8OUTPUT);
	Local_enuArray[5]=DIO_enuSetPinDirection(SSG_GRP,BIT3_PIN,DIO_u8OUTPUT);
	Local_enuArray[6]=DIO_enuSetPinValue(SSG_GRP,RIGHT_SSG_ENABLE_PIN,DIO_u8LOW_LEVEL);
	Local_enuArray[7]=DIO_enuSetPinValue(SSG_GRP,LEFT_SSG_ENABLE_PIN,DIO_u8LOW_LEVEL);

	for(u8 Local_u8Iterator=0 ; Local_u8Iterator<=7 ; Local_u8Iterator++)
	{
		if( Local_enuArray[Local_u8Iterator] != ES_OK)
		{
			flag = ES_NOK;
			break;
		}
	}
	Local_enuErrorState = flag;
	return Local_enuErrorState;

}

ES_t HEXA_enuPinEnable(u8 Copy_u8GroupID,u8 Copy_u8PinID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if( ( Copy_u8GroupID == RIGHT_SSG_GRP ) && ( Copy_u8PinID == RIGHT_SSG_ENABLE_PIN || Copy_u8PinID == LEFT_SSG_ENABLE_PIN ))
	{
		DIO_enuSetPinValue(Copy_u8GroupID,Copy_u8PinID,HEXA_u8PINENABLE);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t HEXA_enuPinDisable(u8 Copy_u8GroupID,u8 Copy_u8PinID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if( ( Copy_u8GroupID == RIGHT_SSG_GRP ) && ( Copy_u8PinID == RIGHT_SSG_ENABLE_PIN || Copy_u8PinID == LEFT_SSG_ENABLE_PIN ))
	{
		DIO_enuSetPinValue(Copy_u8GroupID,Copy_u8PinID,HEXA_u8PINDISABLE);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t HEXA_enuWriteNumber(u8 Copy_u8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	if( Copy_u8Value <= HEXA_u8MAXNUMBER  )
	{
		DIO_enuSetPinValue(SSG_GRP,BIT0_PIN,(DIO_u8BIT_MASK & ( Copy_u8Value >> HEXA_u8SH0BIT )));
		DIO_enuSetPinValue(SSG_GRP,BIT1_PIN,(DIO_u8BIT_MASK & ( Copy_u8Value >> HEXA_u8SH1BIT )));
		DIO_enuSetPinValue(SSG_GRP,BIT2_PIN,(DIO_u8BIT_MASK & ( Copy_u8Value >> HEXA_u8SH2BIT )));
		DIO_enuSetPinValue(SSG_GRP,BIT3_PIN,(DIO_u8BIT_MASK & ( Copy_u8Value >> HEXA_u8SH3BIT )));

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}
