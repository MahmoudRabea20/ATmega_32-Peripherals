/*
 * Timer0_priv.h
 *
 *  Created on: Apr 14, 2023
 *      Author: top
 */

#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define Normal                         1
#define PWM                            2
#define CTC                            3
#define Fast_PWM                       4

#define NO_clock_source_stopped        0
#define NO_Prescaler                   1
#define Division_By_8                  2
#define Division_By_64                 3
#define Division_By_256                4
#define Division_By_1024               5
#define EXT_Clock_Falling_on_T0        6
#define EXT_Clock_Rising_on_T0         7

#endif /* TIMER0_PRIVATE_H_ */
