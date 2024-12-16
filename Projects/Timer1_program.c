/*
 * Timer1_program.c
 *
 *  Created on: May 4, 2023
 *      Author: top
 */

#include "errorState.h"
#include "stdTypes.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Timer_registers.h"

#include "Timer1_configuration.h"
#include "Timer1_private.h"
#include "Timer1_interface.h"

void Timer1_enuInit()
{
	/*Compare Output Mode, Fast PWM = set on top clear on compare*/
	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1A0);

	/* Waveform Generation Mode = Fast PWM */
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);

	/* Top value*/
	ICR1 = 2500;

	/**/
	OCR1A = 125;

	/* Prescaler = 64 */
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);

}

void Timer1_enuSetCompareValue(u16 Copy_u16CompareValue)
{
	OCR1A = Copy_u16CompareValue ;
}
