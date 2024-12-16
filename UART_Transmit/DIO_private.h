/*
 * DIO_priv.h
 *
 *  Created on: Feb 5, 2023
 *      Author: top
 */

#include "errorState.h"
#include "stdTypes.h"

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define PIND   *((volatile u8 *)0x30)
#define DDRD   *((volatile u8 *)0x31)
#define PORTD  *((volatile u8 *)0x32)
#define PINC   *((volatile u8 *)0x33)
#define DDRC   *((volatile u8 *)0x34)
#define PORTC  *((volatile u8 *)0x35)
#define PINB   *((volatile u8 *)0x36)
#define DDRB   *((volatile u8 *)0x37)
#define PORTB  *((volatile u8 *)0x38)
#define PINA   *((volatile u8 *)0x39)
#define DDRA   *((volatile u8 *)0x3A)
#define PORTA  *((volatile u8 *)0x3B)

#define DIO_u8BIT_MASK              1


#endif /* DIO_PRIV_H_ */
