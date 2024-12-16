/*
 * ADC_priv.h
 *
 *  Created on: Feb 17, 2023
 *      Author: top
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADCH                                 *((volatile u8 *) 0x25)       /* ADC Data Register High Byte             */
#define ADCL                                 *((volatile u8 *) 0x24)       /* ADC Data Register Low Byte              */

#define ADMUX                                *((volatile u8 *) 0x27)       /* ADC Multiplexer selection register      */
#define ADMUX_REFS1                          7                             /* Reference Selection Bit                 */
#define ADMUX_REFS0                          6                             /* Reference Selection Bit                 */
#define ADMUX_ADLAR                          5                             /* ADC Adjust Result                       */
#define ADMUX_MUX4                           4                             /* Analog Channel and Gain Selection Bit   */
#define ADMUX_MUX3                           3                             /* Analog Channel and Gain Selection Bit   */
#define ADMUX_MUX2                           2                             /* Analog Channel and Gain Selection Bit   */
#define ADMUX_MUX1                           1                             /* Analog Channel and Gain Selection Bit   */
#define ADMUX_MUX0                           0                             /* Analog Channel and Gain Selection Bit   */

#define ADCSRA                               *((volatile u8 *) 0x26)       /* ADC Control and Status Register A       */
#define ADCSRA_ADEN                          7                             /* ADC Enable                              */
#define ADCSRA_ADSC                          6                             /* Start Conversion                        */
#define ADCSRA_ADATE                         5                             /* ADC Auto Trigger Enable                 */
#define ADCSRA_ADIF                          4                             /* ADC Interrupt Flag                      */
#define ADCSRA_ADIE                          3                             /* ADC Interrupt Enable                    */
#define ADCSRA_ADPS2                         2                             /* ADC Prescaler Select Bit                */
#define ADCSRA_ADPS1                         1                             /* ADC Prescaler Select Bit                */
#define ADCSRA_ADPS0                         0                             /* ADC Prescaler Select Bit                */

#define AREF                                 1
#define AVCC                                 2
#define Internal                             3

#define DIVIDION_BY_2                        1
#define DIVIDION_BY_4                        2
#define DIVIDION_BY_8                        3
#define DIVIDION_BY_16                       4
#define DIVIDION_BY_32                       5
#define DIVIDION_BY_64                       6
#define DIVIDION_BY_128                      7

#endif /* ADC_PRIVATE_H_ */
