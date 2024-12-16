/*
 * Timer0_int.h
 *
 *  Created on: Apr 14, 2023
 *      Author: top
 */

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

ES_t Timer0_enuInit();
ES_t Timer0_enuCallBackFunPointer(void (* Copy_pvFunPointer)(void));
void Timer0_enuSetCompareValue(u8 Copy_u8CompareValue);

/*
 * Options of Timer Mode :
 *          1- Normal(Overflow)
 *          2- PWM(Phase correct)
 *          3- CTC
 *          4- Fast PWM
 */

#define TIMER0_u8INTMODE            Fast_PWM

/*
 * Options of Prescaler :
 *          1- NO_clock_source_stopped
 *          2- NO_Prescaler
 *          3- Division_By_8
 *          4- Division_By_64
 *          5- Division_By_256
 *          6- Division_By_1024
 *          7- EXT_Clock_Falling_on_T0
 *          8- EXT_Clock_Rising_on_T0
 */

#define TIMER0_u8PRESCALER       Division_By_64

#endif /* TIMER0_INTERFACE_H_ */
