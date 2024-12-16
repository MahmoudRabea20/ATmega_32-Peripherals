/*
 * SPI_Slave_program.c
 *
 *  Created on: Jun 27, 2023
 *      Author: top
 */

#include "BIT_MATH.h"
#include "stdTypes.h"
#include "errorState.h"

#include "DIO_interface.h"
#include "SPI_Slave_interface.h"
#include "SPI_register.h"
#include "SPI_Slave_private.h"

void SPI_voidSlaveInit()
{
	/* select slave */
	CLR_BIT(SPCR,SPCR_MSTR);

	/* Output pins*/
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_4,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_5,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_6,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_7,DIO_u8INPUT);



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
