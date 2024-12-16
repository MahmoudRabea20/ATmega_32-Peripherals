/*
 * TWI_program.c
 *
 *  Created on: Jul 8, 2023
 *      Author: top
 */

#include "BIT_MATH.h"
#include "stdTypes.h"
#include "errorState.h"

#include "TWI_interface.h"
#include "TWI_register.h"
#include "TWI_private.h"



void TWI_voidInitMaster(u8 Copy_u8Address)  /* Set Master address to 0 if master will not be addressed */
{
	/* Set SCL frequency to 400 kbps with 16MHz system frequency */
	/* 1- set TWBR to 12  */
	TWBR=12;

	/* 2- clear the prescaler bits(TWPS)*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	/* check if the master will not be addressed */
	if(Copy_u8Address != 0)
	{
		TWAR = Copy_u8Address << 1;
	}
	else
	{
		/* Do Nothing */
	}

	/* Enable Acknowledge bit */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidInitSlave(u8 Copy_u8Address)
{
	/* Set Slave Address  */
	TWAR = Copy_u8Address << 1;

	/* Enable Acknowledge bit */
	SET_BIT(TWCR,TWCR_TWEA);

	/* Enable TWI */
	SET_BIT(TWCR,TWCR_TWEN);
}

ES_t TWI_enuSendStartCondition(void)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Set start condition bit */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);


	/* Wait until the operation finishes and the flag is raised */
	while(((TWCR >> TWCR_TWINT) & 1) == 0);

	/* Check the operation status*/
	if( (TWSR & 0xF8) != START_ACK )
	{
		Local_enuErrorState = StartConditionError ;
	}
	else
	{
		/* Do Nothing */
	}


	return Local_enuErrorState;

}

ES_t TWI_enuSendRepeatedStart(void)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Set start condition bit */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until the operation finishes and the flag is raised */
	while(((TWCR >> TWCR_TWINT) & 1) == 0);

	/* Check the operation status*/
	if( (TWSR & 0xF8) != REP_START_ACK )
	{
		Local_enuErrorState = RepeatedStartError ;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_enuErrorState;
}

ES_t TWI_enuSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Send the 7bit Slave address on the bus*/
	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR,0);

	/*Clear the start condition bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until the operation finishes and the flag is raised */
	while(((TWCR >> TWCR_TWINT) & 1) == 0);

	/* Check the operation status*/
	if( (TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK )
	{
		Local_enuErrorState = SlaveAddressWithWriteError ;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_enuErrorState;
}

ES_t TWI_enuSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Send the 7bit Slave address on the bus*/
	TWDR = Copy_u8SlaveAddress << 1;

	/* Set bit0 for reading */
	SET_BIT(TWDR,0);

	/*Clear the start condition bit */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until the operation finishes and the flag is raised */
	while(((TWCR >> TWCR_TWINT) & 1) == 0);

	/* Check the operation status*/
	if( (TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK )
	{
		Local_enuErrorState = SlaveAddressWithReadError ;
	}
	else
	{
		/* Do Nothing */
	}

	return Local_enuErrorState;
}

ES_t TWI_enuMasterWriteDataByte(u8 Copy_u8DataByte)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Write the data byte on the bus*/
	TWDR = Copy_u8DataByte;

	/* Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until the operation finishes and the flag is raised */
	while(((TWCR >> TWCR_TWINT) & 1) == 0);

	/* Check the operation status*/
	if( (TWSR & 0xF8) != MSTR_WR_BYTE_ACK )
	{
		Local_enuErrorState = MasterWriteByteError ;
	}
	else
	{
		/* Do Nothing */
	}


	return Local_enuErrorState;
}

ES_t TWI_enuMasterReadDataByte(u8* Copy_u8DataByte)
{
	ES_t Local_enuErrorState = ES_OK;

	/* Clear the interrupt flag to allow the slave to send the data */
	SET_BIT(TWCR,TWCR_TWINT);

	/* Wait until the operation finishes and the flag is raised */
	while(((TWCR >> TWCR_TWINT) & 1) == 0);

	/* Check the operation status*/
	if( (TWSR & 0xF8) != MSTR_RD_BYTE_WITH_ACK )
	{
		Local_enuErrorState = MasterReadByteError ;
	}
	else
	{
		/* Read the received data*/
		*Copy_u8DataByte = TWDR;
	}

	return Local_enuErrorState;
}

void TWI_voidSendStopCondition(void)
{
	/* Send Stop condition on the bus */
	SET_BIT(TWCR,TWCR_TWSTO);

	/* Clear the interrupt flag to start the previous operation */
	SET_BIT(TWCR,TWCR_TWINT);
}
