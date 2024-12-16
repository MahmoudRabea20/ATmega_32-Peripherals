/*
 * ADC_program.c
 *
 *  Created on: Jul 29, 2023
 *      Author: top
 */

#include "ErrorState.h"
#include "stdTypes.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "ADC_configuration.h"
#include "ADC_private.h"
#include "ADC_register.h"
#include "ADC_interface.h"

ES_t ADC_enuInit()
{
	ES_t Local_enuErrorState = ES_OK;

	/* Select Reference */
	ADMUX &= (0b00111111);
	ADMUX |= (ADC_VOLTAGE_REFERENCE_MODE << 6);

	/*Activate ADC Left Adjust Result for resolution */
	SET_BIT(ADMUX,ADMUX_ADLAR);

	/* Set Prescaler */
	ADCSRA &= (0b11111000);
	ADCSRA |= ADC_PRESCALER_SELECTION;

	/*Enable the ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	return Local_enuErrorState;
}

ES_t ADC_enuGetChannelReading(u8 Copy_u8ChannelNumber,u8* Copy_u8ADCReadingValue)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Select channel */
	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8ChannelNumber;

	/*Start Conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Wait until conversion completion */
	while(((ADCSRA >> ADCSRA_ADIF) & 1 ) == 0 );

	/* Clear tha interrupt flag */
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	/*Reading the converted value*/
	*Copy_u8ADCReadingValue = ADCH;

	return Local_enuErrorState;

}
