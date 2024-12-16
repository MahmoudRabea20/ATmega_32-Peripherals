/*
 * main.c
 *
 *  Created on: May 5, 2023
 *      Author: top
 */


#include "DIO_interface.h"
#include "UART_interface.h"
#include "UART_register.h"


int main()
{
	UART_voidInit();
	GIE_enuEnableGlobalInt();




	while(1)
	{

	}
}

void __vector_14  (void)  __attribute__((signal));
void __vector_14  (void)
{

	 UDR=5;



}

/*

int main()
{


	UART_voidInit();

	while(1)
	{
		UART_voidSendData(1);

	}



}

 */
