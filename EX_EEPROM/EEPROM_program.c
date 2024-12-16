
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "errorState.h"

#include "EEPROM_private.h"
#include "EEPROM_interface.h"
#include "util/delay.h"

void EEPROM_voidWriteByte(u16 Copy_u16Address , u8 Copy_u8Data )
{
	/* Wait for completion of previous write */
	while(((EECR >> EECR_EEWE ) & 1) == 1);

	/* Set up address and data registers */
	EEAR = Copy_u16Address;
	EEDR = Copy_u8Data;

	/* Write logical one to EEMWE */
	EECR |= (1<<EECR_EEMWE);

	/* Start eeprom write by setting EEWE */
    EECR |= (1<<EECR_EEWE) ;
}

u8  EEPROM_u8ReadByte(u16 Copy_u16Address)
{
//	/* Wait for completion of previous write */
//	while(((EECR >> EECR_EEWE ) & 1) == 1);

	/* Set up address register */
	EEAR = Copy_u16Address;

	/* Start eeprom read by writing EERE */
	SET_BIT(EECR,EECR_EERE);

	CLR_BIT(EECR,EECR_EEWE);

	/* Return data from data register */
	return EEDR;

}

void EEPROM_voidWriteBlock(u16 Copy_u16Address,u8* Copy_Au8Data,u16 Copy_u16Size)
{
	u16 Local_u16counter = 0;        /*Bytes write counter*/

	while (Local_u16counter < Copy_u16Size)
	{
		/* Wait for completion of previous write */
		while(EECR & (1<<EECR_EEWE));

		/* Set up address register

		/* Set up address register */
		EEAR = Copy_u16Address + Local_u16counter;

		/* Read the byte in the address of EEAR */
		SET_BIT(EECR,EECR_EERE);

		if (EEDR != (*(Copy_Au8Data + Local_u16counter)))   /* Compare the value read to the value to be written */
		{ /* if they are not equal then write the data */
			EEDR = *(Copy_Au8Data + Local_u16counter);      /*move the data to EEDR*/

			/* Write logical one to EEMWE */
			SET_BIT(EECR,EECR_EEMWE);

			/* Start EEPROM write by setting EEWE */
			SET_BIT(EECR,EECR_EEWE);
		}
		else
		{
			/* Do Nothing */
		}
		Local_u16counter++;                                /*increase bytes counter*/
	}
}

void EEPROM_voidReadBlock( u16 u16Address, u8* Copy_Au8Data,u16 Copy_u16Size)
{
	u16 Local_u16Counter = 0;           /* the counter of bytes that are read */

	while (Local_u16Counter < Copy_u16Size) /*loop until move all bytes to the given array*/
	{
		/* Set up address register */
		EEAR = u16Address + Local_u16Counter;

		/* Start EEPROM read by writing EERE */
		SET_BIT(EECR,EECR_EERE);

		/* move data from data register to the array */
		*(Copy_Au8Data + Local_u16Counter) = EEDR;

		Local_u16Counter++;//increase the bytes counter
	}
}
