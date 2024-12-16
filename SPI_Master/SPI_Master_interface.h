/*
 * SPI_Master_interface.h
 *
 *  Created on: Jun 26, 2023
 *      Author: top
 */

#ifndef SPI_MASTER_INTERFACE_H_
#define SPI_MASTER_INTERFACE_H_

void SPI_voidMasterInit();
u8 SPI_u8Tranceive(u8 Copy_u8Data);
void SPI_voidMstrResetSlave();



#endif /* SPI_MASTER_INTERFACE_H_ */
