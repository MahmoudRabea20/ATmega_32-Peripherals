/*
 * DIO_prog.c
 *
 *  Created on: Feb 5, 2023
 *      Author: top
 */

#include "DIO_interface.h"
#include "DIO_private.h"
#include "errorState.h"
#include "stdTypes.h"


ES_t DIO_enuSetPinDirection(u8 Copy_u8GroupID,u8 Copy_u8PinID,u8 Copy_u8PinDirection)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8GroupID <= DIO_u8GROUP_D && Copy_u8PinID <= DIO_u8PIN_7 && Copy_u8PinDirection <= DIO_u8OUTPUT)
	{
		switch(Copy_u8GroupID)
		{
		case DIO_u8GROUP_A :
			DDRA &= ~ ( DIO_u8BIT_MASK << Copy_u8PinID ) ;
			DDRA |= Copy_u8PinDirection << Copy_u8PinID ;
			break;
		case DIO_u8GROUP_B:
			DDRB &= ~ ( DIO_u8BIT_MASK << Copy_u8PinID ) ;
			DDRB |= Copy_u8PinDirection << Copy_u8PinID ;
			break;
		case DIO_u8GROUP_C:
			DDRC &= ~ ( DIO_u8BIT_MASK << Copy_u8PinID ) ;
			DDRC |= Copy_u8PinDirection << Copy_u8PinID ;
			break;
		case DIO_u8GROUP_D:
			DDRD &= ~ ( DIO_u8BIT_MASK << Copy_u8PinID ) ;
			DDRD |= Copy_u8PinDirection << Copy_u8PinID ;
			break;
		}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t DIO_enuSetPinValue(u8 Copy_u8GroupID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8GroupID <= DIO_u8GROUP_D && Copy_u8PinID <= DIO_u8PIN_7 && Copy_u8PinValue <= DIO_u8HIGH_LEVEL)
	{
		switch(Copy_u8GroupID)
		{
		case DIO_u8GROUP_A :
			PORTA &= ~ ( DIO_u8BIT_MASK << Copy_u8PinID ) ;
			PORTA |= Copy_u8PinValue << Copy_u8PinID ;
			break;
		case DIO_u8GROUP_B :
			PORTB &= ~ ( DIO_u8BIT_MASK << Copy_u8PinID ) ;
			PORTB |= Copy_u8PinValue << Copy_u8PinID ;
			break;
		case DIO_u8GROUP_C:
			PORTC &= ~ ( DIO_u8BIT_MASK << Copy_u8PinID ) ;
			PORTC |= Copy_u8PinValue << Copy_u8PinID ;
			break;
		case DIO_u8GROUP_D:
			PORTD &= ~ ( DIO_u8BIT_MASK << Copy_u8PinID ) ;
			PORTD |= Copy_u8PinValue << Copy_u8PinID ;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;

}

ES_t DIO_enuGetPinValue(u8 Copy_u8GroupID,u8 Copy_u8PinID,u8* Copy_pu8PinValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8GroupID <= DIO_u8GROUP_D && Copy_u8PinID <= DIO_u8PIN_7 )
    {
    	switch(Copy_u8GroupID)
    	{
    	case DIO_u8GROUP_A :
    		*Copy_pu8PinValue = ( PINA >> Copy_u8PinID ) & DIO_u8BIT_MASK;
    		break;
    	case DIO_u8GROUP_B :
    		*Copy_pu8PinValue = ( PINB >> Copy_u8PinID ) & DIO_u8BIT_MASK;
    		break;
    	case DIO_u8GROUP_C:
    		*Copy_pu8PinValue = ( PINC >> Copy_u8PinID ) & DIO_u8BIT_MASK;
    		break;
    	case DIO_u8GROUP_D:
    		*Copy_pu8PinValue = ( PIND >> Copy_u8PinID ) & DIO_u8BIT_MASK;
    		break;
    	}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t DIO_enuTogglePinVlaue(u8 Copy_u8GroupID,u8 Copy_u8PinID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8GroupID <= DIO_u8GROUP_D && Copy_u8PinID <= DIO_u8PIN_7 )
    {
    	switch(Copy_u8GroupID)
    	{
    	case DIO_u8GROUP_A :
    		PORTA ^= (DIO_u8BIT_MASK << Copy_u8PinID);
    		break;
    	case DIO_u8GROUP_B :
    		PORTB ^= (DIO_u8BIT_MASK << Copy_u8PinID);
    		break;
    	case DIO_u8GROUP_C:
    		PORTC ^= (DIO_u8BIT_MASK << Copy_u8PinID);
    		break;
    	case DIO_u8GROUP_D:
    		PORTD ^= (DIO_u8BIT_MASK << Copy_u8PinID);
    		break;
    	}

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t DIO_enuSetPortValue(u8 Copy_u8GroupID,u8 Copy_u8PortValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8GroupID <= DIO_u8GROUP_D )
	{
		switch(Copy_u8GroupID)
		{
		case DIO_u8GROUP_A :
			PORTA = Copy_u8PortValue ;
			break;
		case DIO_u8GROUP_B :
			PORTB = Copy_u8PortValue ;
			break;
		case DIO_u8GROUP_C:
			PORTC = Copy_u8PortValue ;
			break;
		case DIO_u8GROUP_D:
			PORTD = Copy_u8PortValue ;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;

}

ES_t DIO_enuSetPortDirection(u8 Copy_u8GroupID,u8 Copy_u8PortDirection)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8GroupID <= DIO_u8GROUP_D )
	{
		switch(Copy_u8GroupID)
		{
		case DIO_u8GROUP_A :
			DDRA = Copy_u8PortDirection ;
			break;
		case DIO_u8GROUP_B :
			DDRB = Copy_u8PortDirection ;
			break;
		case DIO_u8GROUP_C:
			DDRC = Copy_u8PortDirection ;
			break;
		case DIO_u8GROUP_D:
			DDRD = Copy_u8PortDirection ;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;

}
