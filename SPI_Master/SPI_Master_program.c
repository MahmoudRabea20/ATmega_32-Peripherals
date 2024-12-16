/*
 * SPI_Master_program.c
 *
 *  Created on: Jun 26, 2023
 *      Author: top
 */

#include "BIT_MATH.h"
#include "stdTypes.h"
#include "errorState.h"

#include <util/delay.h>
#include "DIO_interface.h"
#include "SPI_Master_interface.h"
#include "SPI_register.h"
#include "SPI_Master_private.h"

void SPI_voidMasterInit()
{

	/* select master */
	SET_BIT(SPCR,SPCR_MSTR);

	/* select clock rate  /16 */
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);

	/* Output pins*/
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_5,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_6,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_7,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN_0,DIO_u8LOW_LEVEL);

	/*Chip select is pulled up internally */
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_4,DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8GROUP_B,DIO_u8PIN_4,DIO_u8HIGH_LEVEL);

	/* Select Data Order */
	SET_BIT(SPCR,SPCR_DORD);

	/* Enable SPI */
	SET_BIT(SPCR,SPCR_SPE);

}

u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;

	while((GET_BIT(SPSR,SPSR_SPIF)) == 0);
	SET_BIT(SPSR,SPSR_SPIF);

	return SPDR;

}

void SPI_voidMstrResetSlave()
{
	DDRA |= 1<<0;
	PORTA |= 1<<0;
	_delay_ms(1);
	PORTA &= ~(1<<0);
}
