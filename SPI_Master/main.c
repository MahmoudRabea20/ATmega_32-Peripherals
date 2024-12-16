/*
 * main.c
 *
 *  Created on: Jun 26, 2023
 *      Author: top
 */

#include <util/delay.h>

#include "DIO_interface.h"
#include "SPI_Master_interface.h"



int main()
{


	SPI_voidMasterInit();


	while(1)
	{
		SPI_u8Tranceive(5);
		SPI_voidMstrResetSlave();


	}

}
