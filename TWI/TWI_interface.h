/*
 * TWI_interface.h
 *
 *  Created on: Jul 8, 2023
 *      Author: top
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidInitMaster(u8 Copy_u8Address);  /* Set Master address to 0 if master will not be addressed */

void TWI_voidInitSlave(u8 Copy_u8Address);

TWI_ErrorStatus TWI_enuSendStartCondition(void);

TWI_ErrorStatus TWI_enuSendRepeatedStart(void);

TWI_ErrorStatus TWI_enuSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_enuSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorStatus TWI_enuMasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrorStatus TWI_enuMasterReadDataByte(u8* Copy_u8DataByte);

TWI_ErrorStatus TWI_enuSendStopCondition(void);



#endif /* TWI_INTERFACE_H_ */
