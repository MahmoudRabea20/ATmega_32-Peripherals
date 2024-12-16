/*
 * UART_interface.h
 *
 *  Created on: May 5, 2023
 *      Author: top
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidInit(void);
u8 UART_u8ReceiveData(void);
void UART_voidSendData(u8 Copy_u8Data);

#endif /* UART_INTERFACE_H_ */
