/*
 * Timer1_private.h
 *
 *  Created on: Aug 8, 2023
 *      Author: top
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A               *((volatile u8 *)0x4f)           /*Timer/Counter1 Control Register A*/

#define TCCR1A_COM1A1        7
#define TCCR1A_COM1A0        6
#define TCCR1A_COM1B1        5
#define TCCR1A_COM1B0        4
#define TCCR1A_FOC1A         3
#define TCCR1A_FOC1B         2
#define TCCR1A_WGM11         1
#define TCCR1A_WGM10         0

#define TCCR1B              *((volatile u8 *)0x4E)           /*Timer/Counter1 Control Register A*/

#define TCCR1B_WGM13        4
#define TCCR1B_WGM12        3
#define TCCR1B_CS12         2
#define TCCR1B_CS11         1
#define TCCR1B_CS10         0

#define OCR1A               *((volatile u16 *)0x4A)           /*Output Compare Register 1 A – OCR1AH and OCR1AL*/

#define ICR1                *((volatile u16 *)0x46)            /* Top Value Register - ICR1H and ICR1L*/



#endif /* TIMER1_PRIVATE_H_ */
