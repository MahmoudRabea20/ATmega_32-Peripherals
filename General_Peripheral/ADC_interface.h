/*
 * ADC_interface.h
 *
 *  Created on: Jul 29, 2023
 *      Author: top
 */

#include "ErrorState.h"
#include "stdTypes.h"

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

ES_t ADC_enuInit();
ES_t ADC_enuGetChannelReading(u8 Copy_u8ChannelNumber,u8* Copy_u8ADCReadingValue);


#endif /* ADC_INTERFACE_H_ */
