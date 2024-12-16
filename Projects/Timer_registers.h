/*
 * Timer0_reg.h
 *
 *  Created on: Apr 14, 2023
 *      Author: top
 */

#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

/* Timer0 */
#define TCCR0               *((volatile u8 *)0x53)           /*Timer/Counter Control Register */
#define OCR0                *((volatile u8 *)0x5C)           /*Output Compare Register*/
#define TCNT0               *((volatile u8 *)0x52)           /*Timer/Counter Register */
#define TIMSK               *((volatile u8 *)0x59)           /*Timer/Counter Interrupt Mask Register */
#define TIFR                *((volatile u8 *)0x58)           /*Timer/Counter Interrupt Flag Register */

#define TIMSK_OCIE0         1
#define TIMSK_TOIE0         0

#define TCCR0_WGM01         3
#define TCCR0_WGM00         6
#define TCCR0_COM01         5
#define TCCR0_COM00         4
#define TIMSK_OCIE0         1                                /*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TOIE0               0                                /*Timer/Counter0 Overflow Interrupt Enable*/

/* Timer1 */
#define TCCR1A              *((volatile u8 *)0x4f)           /*Timer/Counter1 Control Register A*/

#define COM1A1              7
#define COM1A0              6
#define COM1B1              5
#define COM1B0              4
#define FOC1A               3
#define FOC1B               2
#define WGM11               1
#define WGM10               0

#define TCCR1B              *((volatile u8 *)0x4E)           /*Timer/Counter1 Control Register A*/

#define WGM13               4
#define WGM12               3
#define CS12                2
#define CS11                1
#define CS10                0

#define OCR1A               *((volatile u16 *)0x4A)           /*Output Compare Register 1 A – OCR1AH and OCR1AL*/

#define ICR1               *((volatile u16 *)0x46)            /* Top Value Register - ICR1H and ICR1L*/




#endif /* TIMER_REGISTERS_H_ */
