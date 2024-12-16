/*
 * EEPROM_interface.h
 *
 *  Created on: Jul 9, 2023
 *      Author: top
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidWriteDataByte(u16 Copy_u16Address,u8 Copy_u8Data);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16Address);

#endif /* EEPROM_INTERFACE_H_ */
