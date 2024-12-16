/*
 * ADC_config.h
 *
 *  Created on: Feb 17, 2023
 *      Author: top
 */

#ifndef ADC_CONFIGURATION_H_
#define ADC_CONFIGURATION_H_

/*Options of Voltage Reference Selections for ADC */
/*          1- AREF (Internal Vref turned off)
 *          2- AVCC (with external capacitor at AREF pin)
 *          3- Internal (2.56V Voltage Reference with external capacitor at AREF pin)
 */

#define ADC_VOLTAGE_REFERENCE_MODE    AVCC

/*Options of Prescaler */
/*          1- DIVIDION_BY_2
 *          2- DIVIDION_BY_4
 *          3- DIVIDION_BY_8
 *          4- DIVIDION_BY_16
 *          3- DIVIDION_BY_32
 *          4- DIVIDION_BY_64
 *          5- DIVIDION_BY_128
 */

#define ADC_PRESCALER_SELECTION       DIVIDION_BY_128

#endif /* ADC_CONFIGURATION_H_ */
