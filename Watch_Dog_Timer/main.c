/*
 * main.c
 *
 *  Created on: May 4, 2023
 *      Author: top
 */


#include "errorState.h"
#include "stdTypes.h"
#include "BIT_MATH.h"
//#include <util/delay.h>
#include "DIO_interface.h"


#define WDTCR               *((volatile u8 *)0x41)
#define WDTCR_WDTOE         4
#define WDTCR_WDE           3
#define WDTCR_WDP2          2
#define WDTCR_WDP1          1
#define WDTCR_WDP0          0

void WDT_voidDisable();
void WDT_voidEnable();
void WDT_voidSetSleepValue(u8 Copy_u8Prescaler);

int main()
{

	DIO_enuSetPinDirection(DIO_u8GROUP_C,DIO_u8PIN_2,DIO_u8OUTPUT);


	DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN_2,DIO_u8LOW_LEVEL);

	//_delay_ms(1000);
	DIO_enuSetPinValue(DIO_u8GROUP_C,DIO_u8PIN_2,DIO_u8HIGH_LEVEL);

	WDT_voidSetSleepValue(6);
	WDT_voidEnable();
	WDT_voidDisable();
	while(1);


}

void WDT_voidEnable()
{
	SET_BIT(WDTCR,WDTCR_WDE);
}

void WDT_voidDisable()
{
	WDTCR = (1<<WDTCR_WDE) | (1<<WDTCR_WDTOE) ;
	WDTCR = 0;
}

void WDT_voidSetSleepValue(u8 Copy_u8Prescaler)
{

	WDTCR &= 0b11111000;
	WDTCR = Copy_u8Prescaler;
}

