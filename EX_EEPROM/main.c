


#include "stdTypes.h"
#include "BIT_MATH.h"
#include "errorState.h"
//
//#include "DIO_interface.h"
#include "LCD_interface.h"
#include "EX_EEPROM_interface.h"
#include "TWI_interface.h"
//#include "Keypad_interface.h"
#include <util/delay.h>
//
//int main()
//{
//	u8 Local_u8Data = 0;
//	u8 Local_Au8TData[4];
//	u8 Local_u8PressedValue;
//	u8 Local_u8ASCounter = 0;
//
//	u8 Local_Au8RData[4];
//	LCD_enuInit();
//
//	EEPROM_voidWriteByte(0x0025,15);
////	EEPROM_voidWriteByte(0x0027,6);
////	EEPROM_voidWriteByte(0x0029,7);
////	EEPROM_voidWriteByte(0x0031,8);
//
//
//	Local_u8Data = EEPROM_u8ReadByte((0x0025));
//	LCD_enuWriteIntegerNumber(Local_u8Data);
//
////	Local_u8Data = EEPROM_u8ReadByte((0x0027));
////	LCD_enuWriteIntegerNumber(Local_u8Data);
////
////	Local_u8Data = EEPROM_u8ReadByte((0x0029));
////	LCD_enuWriteIntegerNumber(Local_u8Data);
////
////	Local_u8Data = EEPROM_u8ReadByte((0x0031));
////	LCD_enuWriteIntegerNumber(Local_u8Data);
//
//
//
//	//		Keypad_enuInit();
//	//		LCD_enuWriteString("Set Admin pass");
//	//		LCD_enuGoToXYPosition(0,1);
//	//
//	//		/***************************** Set Admin Password *****************************************/
//	//
//	//		while(1)
//	//		{
//	//			do
//	//			{
//	//				Keypad_enuGetPressedKey(&Local_u8PressedValue);
//	//
//	//			}
//	//			while( Local_u8PressedValue == Keypad_NOT_PREESED);
//	//
//	//			if(Local_u8PressedValue == 'C')
//	//			{
//	//				LCD_enuClear();
//	//				LCD_enuWriteString("Password saved");
//	//				_delay_ms(1000);
//	//				LCD_enuClear();
//	//				break;
//	//			}
//	//			else if(Local_u8PressedValue == '-')
//	//			{
//	//				Local_u8ASCounter--;
//	//				LCD_enuDeleteCharacter(1);
//	//			}
//	//			else
//	//			{
//	//				LCD_enuWriteIntegerNumber(Local_u8PressedValue);
//	//				_delay_ms(1000);
//	//				LCD_enuGoToXYPosition(Local_u8ASCounter,1);
//	//				LCD_enuWriteData('*');
//	//				Local_Au8TData[Local_u8ASCounter] = Local_u8PressedValue ;
//	//				Local_u8ASCounter ++;
//	//			}
//	//		}
//	//		LCD_enuWriteData('*');
//	//		EEPROM_vWriteBlockToAddress(0x0025,Local_Au8TData,4);
//	//
//	//		LCD_enuWriteData('*');
//	//
//	//
//
//
//	while(1);
//}
//
//
//
//
//
//
//
//
//
//

//
//
//
////#include <avr/io.h>
////#include <util/twi.h>
////#include "LCD_interface.h"
////
////#define EEPROM_ADDR 0b10100000 // Replace with the actual address of your EEPROM
////
////void I2C_Init() {
////	TWBR = 0x20; // Set the bit rate register for desired baud rate (you may need to adjust this)
////	TWSR = 0;    // Prescaler = 1
////	TWCR = (1 << TWEN); // Enable TWI
////}
////
////void EEPROM_WriteByte(uint16_t address, uint8_t data) {
////	// Start condition
////	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	// Send device address with write operation
////	TWDR = EEPROM_ADDR;
////	TWCR = (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	// Send memory address
////	TWDR = (uint8_t)(address >> 8); // MSB of address
////	TWCR = (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	TWDR = (uint8_t)(address & 0xFF); // LSB of address
////	TWCR = (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////	// Send data to be written
////	TWDR = data;
////	TWCR = (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	// Stop condition
////	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
////	while (TWCR & (1 << TWSTO)); // Wait for stop condition to be executed
////}
////
////uint8_t EEPROM_ReadByte(uint16_t address) {
////	// Start condition
////	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	// Send device address with write operation
////	TWDR = EEPROM_ADDR;
////	TWCR = (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	// Send memory address
////	TWDR = (uint8_t)(address >> 8); // MSB of address
////	TWCR = (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	TWDR = (uint8_t)(address & 0xFF); // LSB of address
////	TWCR = (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	// Repeat start condition for read
////	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////	// Send device address with read operation
////	TWDR = EEPROM_ADDR | 1; // Set the read bit
////	TWCR = (1 << TWEN) | (1 << TWINT);
////	while (!(TWCR & (1 << TWINT)));
////
////	// Enable reception of data
////	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
////
////	// Wait for data reception
////	while (!(TWCR & (1 << TWINT)));
////
////	// Read the received data
////	uint8_t data = TWDR;
////
////	// Stop condition
////	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
////	while (TWCR & (1 << TWSTO)); // Wait for stop condition to be executed
////
////	return data;
////}
////
////int main() {
////	I2C_Init();
////
////	LCD_enuInit();
////
////	uint16_t address = 0x0010;
////	uint8_t data_to_write = 29;
////
////	EEPROM_WriteByte(address, data_to_write);
////
////	uint8_t data_read = EEPROM_ReadByte(address);
////
////	LCD_enuWriteIntegerNumber(data_read);
////
////	// Use the data_read variable for further processing
////
////	return 0;
////}
//
//
///*
// * main.c
// *
// *  Created on: Jul 9, 2023
// *      Author: top
// */
//
//#include <util/delay.h>
//
//#include "DIO_interface.h"
//#include "IIC_int.h"
//#include "EEPROM_interface.h"
//#include "HEXA_interface.h"
//#include "UART_interface.h"
//#include "LCD_interface.h"
//
int main()
{
	u8 Local_u8ReceivedData = 0 ;

	//HEXA_enuInit();
	LCD_enuInit();
	TWI_voidInitMaster(0);

	EEPROM_voidWriteDataByte(43,29);
//	Local_u8ReceivedData = EEPROM_u8ReadDataByte(43);
//	LCD_enuWriteIntegerNumber(Local_u8ReceivedData);

	EEPROM_voidWriteDataByte(45,33);
	Local_u8ReceivedData = EEPROM_u8ReadDataByte(45);


	LCD_enuWriteIntegerNumber(Local_u8ReceivedData);


	Local_u8ReceivedData = EEPROM_u8ReadDataByte(43);

	LCD_enuWriteIntegerNumber(Local_u8ReceivedData);
//
//	EEPROM_voidWriteDataByte(45,3);
//	Local_u8ReceivedData = EEPROM_u8ReadDataByte(45);
//	LCD_enuWriteIntegerNumber(Local_u8ReceivedData);
//
//	EEPROM_voidWriteDataByte(46,4);
//	Local_u8ReceivedData = EEPROM_u8ReadDataByte(46);
//	LCD_enuWriteIntegerNumber(Local_u8ReceivedData);











	while(1);

	//}
//
	/////*	while(1)
	////	{
	////
	////		HEXA_enuPinDisable(DIO_u8GROUP_B,DIO_u8PIN_1);
	////		HEXA_enuPinDisable(DIO_u8GROUP_B,DIO_u8PIN_2);
	////		HEXA_enuWriteNumber(Local_u8ReceivedData % 10) ;
	////		HEXA_enuPinEnable(DIO_u8GROUP_B,DIO_u8PIN_1);
	////		_delay_ms(10);
	////		HEXA_enuPinDisable(DIO_u8GROUP_B,DIO_u8PIN_1);
	////		HEXA_enuWriteNumber(Local_u8ReceivedData / 10) ;
	////		HEXA_enuPinEnable(DIO_u8GROUP_B,DIO_u8PIN_2);
	////		_delay_ms(10);
	////		HEXA_enuPinDisable(DIO_u8GROUP_B,DIO_u8PIN_2);
	////
	////
	////
	////	}
	////	*/
	////}
	////
}
