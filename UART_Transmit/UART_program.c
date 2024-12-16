/*
 * UART_Receive_program.c
 *
 *  Created on: May 5, 2023
 *      Author: top
 */


#include "BIT_MATH.h"
#include "stdTypes.h"
#include "errorState.h"

#include "DIO_interface.h"
#include "UART_configuration.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_register.h"



void UART_voidInit(void)
{
	u8 Local_u8UCSRCVal=0;

	/*Enable Interrupt RX complete and TX ready*/
	SET_BIT(UCSRB,UCSRB_RXCIE);
	SET_BIT(UCSRB,UCSRB_UDRIE);

	/* Set bit 7 for UCSRC*/
	SET_BIT(Local_u8UCSRCVal,UCSRC_URSEL);

	/* Set Character Size = 8-bit */
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCVal,UCSRC_UCSZ1);


	/* Send val to register */
	UCSRC = Local_u8UCSRCVal;

	/*Baud Rate (bps) = 9600 */
	UBRRL = 103;

	/* Enable Receive */
	SET_BIT(UCSRB,UCSRB_RXEN);

	/* Enable Transmitter */
	SET_BIT(UCSRB,UCSRB_TXEN);

}

u8 UART_u8ReceiveData(void)
{

	while( (GET_BIT(UCSRA,UCSRA_RXC)) ==0 );//wait until receive data
	return  UDR;
}

void UART_voidSendData(u8 Copy_u8Data)
{
	while((GET_BIT(UCSRA,UCSRA_UDRE)) ==0); // wait until UDR is empty
	UDR = Copy_u8Data;
}
