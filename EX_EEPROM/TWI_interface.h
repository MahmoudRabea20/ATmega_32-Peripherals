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

ES_t TWI_enuSendStartCondition(void);

ES_t TWI_enuSendRepeatedStart(void);

ES_t TWI_enuSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

ES_t TWI_enuSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

ES_t TWI_enuMasterWriteDataByte(u8 Copy_u8DataByte);

ES_t TWI_enuMasterReadDataByte(u8* Copy_u8DataByte);

void TWI_voidSendStopCondition(void);



#endif /* TWI_INTERFACE_H_ */
