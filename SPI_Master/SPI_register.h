/*
 * SPI_Master_register.h
 *
 *  Created on: Jun 26, 2023
 *      Author: top
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


#define      SPCR          *((volatile u8*)0x2D)             /* SPI Control Register          */
#define      SPCR_SPIE     7                                 /* SPI interrupt enable          */
#define      SPCR_SPE      6                                 /* SPI enable                    */
#define      SPCR_DORD     5                                 /* Data order  1 for LSB FIRST   */
#define      SPCR_MSTR     4                                 /* Master/Slave Select           */
#define      SPCR_CPLO     3                                 /* clock polarity                */
#define      SPCR_CPHA     2                                 /* clock phase                   */
#define      SPCR_SPR1     1                                 /* Select clock rate             */
#define      SPCR_SPR0     0                                 /* Select clock rate             */

#define      SPSR          *((volatile u8*)0x2E)             /* SPI Status Register           */
#define      SPSR_SPI2X    0                                 /* Select clock rate             */
#define      SPSR_SPIF     7                                 /* SPI Interrupt Flag            */

#define      SPDR          *((volatile u8*)0x2F)             /* SPI Data Register             */

#define      PORTA         *((volatile u8 *)0x3B)
#define      DDRA          *((volatile u8 *)0x3A)




#endif /* SPI_REGISTER_H_ */
