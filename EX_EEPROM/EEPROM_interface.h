

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidWriteByte(u16 Copy_u16Address, u8 Copy_u8Data);

u8   EEPROM_u8ReadByte(u16 Copy_u16ByteAddress);

void EEPROM_voidWriteBlock(u16 Copy_u16Address,u8* Copy_Au8Data,u16 Copy_u16Size);

void EEPROM_voidReadBlock(u16 Copy_u16Address, u8* Copy_Au8Data,u16 Copy_u16Size);

#endif /* EEPROM_INTERFACE_H_ */
