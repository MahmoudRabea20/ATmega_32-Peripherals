/*
 * Timer0_prog.c
 *
 *  Created on: Apr 14, 2023
 *      Author: top
 */

#include "errorState.h"
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "Timer_registers.h"

#include "Timer0_configuration.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"

static void (*Timer0_NormalFunPtr)(void) = NULL;
static void (*Timer0_CTCFunPtr)(void) = NULL;

ES_t Timer0_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;

#if   TIMER0_u8INTMODE == Normal
	/*Set OVF Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	/*Set Enable Interrupt*/
	SET_BIT(TIMSK,TOIE0);
	//TCNT0 =             // Initial Value
#elif TIMER0_u8INTMODE==PWM
	/*Set interrupt Mode*/
#elif TIMER0_u8INTMODE==CTC
	/*Set interrupt Mode*/
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Set Enable Interrupt*/
	SET_BIT(TIMSK,TIMSK_OCIE0);

	OCR0 = 250      ;      // Compare Value
#elif TIMER0_u8INTMODE==Fast_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	/*Set interrupt Mode*/
#else
	"Error :  Timer Mode Is Wrong"
#endif

	/*Set Prescaler of Timer*/
	TCCR0 &= 0b11111000;
	TCCR0 |= 3;

	/*clear on compare set on top*/
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);

	/*set interrupt enable*/
	SET_BIT(TIMSK,TIMSK_TOIE0);
	SET_BIT(TIMSK,TIMSK_OCIE0);

	return Local_enuErrorState;
}

void Timer0_enuSetCompareValue(u8 Copy_u8CompareValue)
{
	OCR0 = Copy_u8CompareValue ;
}

ES_t Timer0_enuCallBackFunPointer(void (* Copy_pvFunPointer)(void))
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pvFunPointer != NULL)
	{
		if(TIMER0_u8INTMODE == Normal)
		{
			Timer0_NormalFunPtr = Copy_pvFunPointer;
			Local_enuErrorState = ES_OK;
		}
		else if(TIMER0_u8INTMODE == CTC)
		{
			Timer0_CTCFunPtr = Copy_pvFunPointer;
			Local_enuErrorState = ES_OK;
		}

	}
	else
	{
		Local_enuErrorState = NULL_POINTER;
	}

	return Local_enuErrorState;
}


