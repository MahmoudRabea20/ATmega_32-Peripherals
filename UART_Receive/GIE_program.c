/*
 * GIE_prog.c
 *
 *  Created on: Feb 14, 2023
 *      Author: top
 */

#include "errorState.h"
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "GIE_configuration.h"
#include "GIE_interface.h"


#include "GIE_private.h"

void GIE_enuEnableGlobalInt(void)
{


	__asm volatile ("SEI");      /* Inline assembly syntax in GCC toolchain */

	//SET_BIT(SREG,SREG_INT_BIT);


}
void GIE_enuDisableGlobalInt(void)
{


	__asm volatile ("CLI");      /* Inline assembly syntax in GCC toolchain */

	//CLR_BIT(SREG,SREG_INT_BIT);

}
