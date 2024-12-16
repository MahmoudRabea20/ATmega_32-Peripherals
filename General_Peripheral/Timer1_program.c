/*
 * Timer1_program.c
 *
 *  Created on: Aug 8, 2023
 *      Author: top
 */

#include "stdTypes.h"
#include "ErrorState.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "Timer1_interface.h"
#include "Timer1_configuration.h"
#include "Timer1_private.h"

ES_t Timer1_enuWave_FastPWM(f32 Copy_f32ComparedValue)
{
	ES_t Local_enuErrorState = ES_OK;

	/*Set OC1A as output*/
	DIO_enuSetPinDirection(DIO_GROUP_D,DIO_PIN_5,DIO_OUTPUT);

	/*Select Fast PWM Mode , Set on Compare Clear on Top*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	/*Set Prescaler = 64 */
	SET_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

	/*Select Fast PWM mode Top in ICR1*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*Set Top in ICR1*/
	ICR1 = 4999;

	/*Set Compare Value*/
	OCR1A = Copy_f32ComparedValue * 250;

	return Local_enuErrorState;
}
