/*
 * ADC_prog.c
 *
 *  Created on: Feb 17, 2023
 *      Author: top
 */

#include "ADC_configuration.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "errorState.h"
#include "stdTypes.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

ES_t ADC_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Voltage Reference Selections for ADC */
#if ADC_VOLTAGE_REFERENCE_MODE == AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_VOLTAGE_REFERENCE_MODE == AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_VOLTAGE_REFERENCE_MODE == Internal
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#warning    "Error : Voltage reference selection configuration is wrong "
#endif

	/*Activate ADC Left Adjust Result for resolution */
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/*Select prescaler */
	ADCSRA &= 0b11111000 ;
	ADCSRA |= ADC_PRESCALER_SELECTION ;

	/*Enable ADC */
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	return Local_enuErrorState;


}

u16 ADC_u16GetChannelReading(u8 Copy_u8ChannelNumber)
{
	/*Select channel */
	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8ChannelNumber;

	/*Start conversion */
	SET_BIT( ADCSRA,ADCSRA_ADSC);

	/*Busy waiting (polling) on the conversion complete flag*/
	while( (GET_BIT(ADCSRA,ADCSRA_ADIF)) == 0);

	/*Clear interrupt flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/*Reading*/
	return ADCH;
}



