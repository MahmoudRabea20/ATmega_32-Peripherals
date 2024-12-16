/*
 * EEPROM_program.c
 *
 *  Created on: Jul 9, 2023
 *      Author: top
 */

#include "BIT_MATH.h"
#include "stdTypes.h"
#include "errorState.h"

#include <util/delay.h>
#include "DIO_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "LCD_interface.h"



void EEPROM_voidWriteDataByte(u16 Copy_u16Address,u8 Copy_u8Data)
{
	u8 Local_u8SlaveAddress = 0;

	Local_u8SlaveAddress = 0b1010000 | (u8)( (Copy_u16Address >> 8));

	TWI_enuStartCondition();

	IIC_enuWriteSlaveAddress(Local_u8SlaveAddress,0);

	IIC_enuWriteData((u8)Copy_u16Address);
	IIC_enuWriteData(Copy_u8Data);
	IIC_enuStopCondition();

	_delay_ms(5);
}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16Address)
{
	u8 Local_u8SlaveAddress = 0;
	u8 Local_u8Data=0;

	Local_u8SlaveAddress = 0b1010000 | (u8)((Copy_u16Address >> 8));

	IIC_enuStartCondition();
	IIC_enuWriteSlaveAddress(Local_u8SlaveAddress,0);
	IIC_enuWriteData((u8)Copy_u16Address);

	IIC_enuRepeatedStartCondition();
	IIC_enuWriteSlaveAddress(Local_u8SlaveAddress,1);
	IIC_enuReadData(&Local_u8Data);
	IIC_enuStopCondition();

	return Local_u8Data;
}
