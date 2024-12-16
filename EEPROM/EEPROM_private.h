/*
 * EEPROM_private.h
 *
 *  Created on: Sep 22, 2023
 *      Author: top
 */

#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define EEAR                  *((volatile u16*)0x3E)  /*The EEPROM Address Register*/

#define EEDR                  *((volatile u8*)0x3D)    /*The EEPROM Data Register*/

#define EECR                  *((volatile u8*)0x3C)    /*The EEPROM Control Register*/

#define EECR_EERE             0                        /*EEPROM Read Enable*/
#define EECR_EEWE             1                        /*EEPROM Write Enable*/
#define EECR_EEMWE            2                        /*EEPROM Master Write Enable*/
#define EECR_EERIE            3                        /*EEPROM Ready Interrupt Enable*/

#define BIT_MASK              1

#endif /* EEPROM_PRIVATE_H_ */
