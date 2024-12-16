/*
 * LED_prog.c
 *
 *  Created on: Feb 5, 2023
 *      Author: top
 */

#include "LED_configuration.h"
#include "LED_interface.h"

ES_t LED_enuTurnOn(u8 Copy_u8GroupID,u8 Copy_u8PinID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if( (Copy_u8GroupID == C_GRP || Copy_u8GroupID == D_GRP) && ( Copy_u8PinID == C_PIN2 || Copy_u8PinID == C_PIN7 || Copy_u8PinID == D_PIN ))
	{
		DIO_enuSetPinDirection(Copy_u8GroupID,Copy_u8PinID,LED_u8OUTPUT);
	    DIO_enuSetPinValue(Copy_u8GroupID,Copy_u8PinID,LED_u8HIGHLEVEL);

	    Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t LED_enuTurnOff(u8 Copy_u8GroupID,u8 Copy_u8PinID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if( (Copy_u8GroupID == C_GRP || Copy_u8GroupID == D_GRP) && ( Copy_u8PinID == C_PIN2 || Copy_u8PinID == C_PIN7 || Copy_u8PinID == D_PIN ))
	{
		DIO_enuSetPinDirection(Copy_u8GroupID,Copy_u8PinID,LED_u8OUTPUT);
	    DIO_enuSetPinValue(Copy_u8GroupID,Copy_u8PinID,LED_u8LOWLEVEL);

	    Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;

}

ES_t LED_enuToggle(u8 Copy_u8GroupID,u8 Copy_u8PinID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if( (Copy_u8GroupID == C_GRP || Copy_u8GroupID == D_GRP) && ( Copy_u8PinID == C_PIN2 || Copy_u8PinID == C_PIN7 || Copy_u8PinID == D_PIN ))
	{
		DIO_enuSetPinDirection(Copy_u8GroupID,Copy_u8PinID,LED_u8OUTPUT);
		DIO_enuTogglePinVlaue(Copy_u8GroupID,Copy_u8PinID);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

