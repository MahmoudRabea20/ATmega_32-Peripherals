/*
 * main.c
 *
 *  Created on: May 5, 2023
 *      Author: top
 */


#include "DIO_interface.h"
#include "UART_interface.h"
#include "LCD_interface.h"
#include "UART_register.h"
#include <avr/io.h>



int main()
{
	DIO_enuSetPortDirection(DIO_u8GROUP_B,DIO_u8OUTPUT);

	UART_voidInit();
	GIE_enuEnableGlobalInt();
	LCD_enuInit();

	while(1)
	{

	}
}

void __vector_14  (void)  __attribute__((signal));
void __vector_14  (void)
{

	DIO_enuSetPortValue(1,UDR);







}
/*
int main()
{

	u8 Local_u8ReceivedData=0;

	LCD_enuInit();
	DIO_enuSetPinDirection(DIO_u8GROUP_A,DIO_u8PIN_0,DIO_u8OUTPUT);
	UART_voidInit();



	while(1)
	{
		Local_u8ReceivedData = UART_u8ReceiveData();

		if(Local_u8ReceivedData !=0 )
		{
			DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN_0,1);
			LCD_enuWriteIntegerNumber(Local_u8ReceivedData);
			break;
		}

	}



	return 0;



}
 */
