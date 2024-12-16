/*
 * EXTI_prog.c
 *
 *  Created on: Feb 14, 2023
 *      Author: top
 */

#include "errorState.h"
#include "stdTypes.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

#include "EXTI_configuration.h"
#include "EXTI_interface.h"

#include "EXTI_private.h"

static void (*EXTI_fun_ptr[3])(void)={NULL};

ES_t EXTI_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

    /* Set Direction of INT Pins */

	DIO_enuSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN_2,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_D,DIO_u8PIN_3,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN_2,DIO_u8INPUT);

	/* Enable Internal Pull up */

	DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN_2,DIO_u8PULL_UP);
	DIO_enuSetPinValue(DIO_u8GROUP_D,DIO_u8PIN_3,DIO_u8PULL_UP);
	DIO_enuSetPinValue(DIO_u8GROUP_B,DIO_u8PIN_2,DIO_u8PULL_UP);

	/* For INT0 */
#if EXTI_INT0_INIT_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0_ENABLE_BIT);
#elif EXTI_INT0_INIT_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0_ENABLE_BIT);
#endif

#if EXTI_INT0_SENSE_LEVEL == LOW_LEVEL
	/* Clear ISC00 & ISC01 */
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_INT0_SENSE_LEVEL == ANY_LOGICAL_CHANGE
	/* Set ISC00 & Clear ISC01 */
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif EXTI_INT0_SENSE_LEVEL == FALLING_EDGE
	/* Clear ISC00 & Set ISC01 */
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_INT0_SENSE_LEVEL == RISING_EDGE
	/* Set ISC00 & ISC01 */
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "Error : Sense level configuration is wrong"
#endif


	/* For INT1 */
#if EXTI_INT1_INIT_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1_ENABLE_BIT);
#elif EXTI_INT1_INIT_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1_ENABLE_BIT);
#endif

#if EXTI_INT1_SENSE_LEVEL == LOW_LEVEL
	/* Clear ISC10 & ISC11 */
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_INT1_SENSE_LEVEL == ANY_LOGICAL_CHANGE
	/* Set ISC10 & Clear ISC11 */
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif EXTI_INT1_SENSE_LEVEL == FALLING_EDGE
	/* Clear ISC10 & Set ISC11*/
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_INT1_SENSE_LEVEL == RISING_EDGE
	/* Set ISC10 & ISC11 */
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Error : Sense level configuration is wrong"
#endif

	/* For INT2 */
#if EXTI_INT2_INIT_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2_ENABLE_BIt);
#elif EXTI_INT2_INIT_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2_ENABLE_BIt);
#endif

#if EXTI_INT2_SENSE_LEVEL == FALLING_EDGE
	/* Clear ISC2 */
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif EXTI_INT2_SENSE_LEVEL == RISING_EDGE
	/* Set ISC2 */
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error	"Error : Sense level configuration is wrong"
#endif

	return Local_enuErrorState;
}

ES_t EXTI_enuCallBackFunPointer(u8 Copy_u8IntNumber , void (* Copy_pvFunPointer)(void))
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pvFunPointer != NULL)
	{
		if(Copy_u8IntNumber < 3)
		{
			EXTI_fun_ptr[Copy_u8IntNumber] = Copy_pvFunPointer;

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = OUT_OF_RANGE;
		}
	}
	else
	{
		ES_t Local_enuErrorState = NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuEnableInterrupt(u8 Copy_u8IntNumber)
{
	ES_t Local_enuErrorState = ES_OK;

	if(Copy_u8IntNumber < 3)
	{
		switch(Copy_u8IntNumber)
		{
		case EXTI_INT0 : SET_BIT(GICR,GICR_INT0_ENABLE_BIT);
			break;
		case EXTI_INT1 : SET_BIT(GICR,GICR_INT1_ENABLE_BIT);
			break;
		case EXTI_INT2 : SET_BIT(GICR,GICR_INT2_ENABLE_BIt);
			break;
		default        : Local_enuErrorState = ES_NOK;

		}
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_t EXTI_enuDisableInterrupt(u8 Copy_u8IntNumber)
{
	ES_t Local_enuErrorState = ES_OK;

	if(Copy_u8IntNumber < 3)
	{
		switch(Copy_u8IntNumber)
		{
		case EXTI_INT0 : CLR_BIT(GICR,GICR_INT0_ENABLE_BIT);
			break;
		case EXTI_INT1 : CLR_BIT(GICR,GICR_INT1_ENABLE_BIT);
			break;
		case EXTI_INT2 : CLR_BIT(GICR,GICR_INT2_ENABLE_BIt);
			break;
		default        : Local_enuErrorState = ES_NOK;

		}
	}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}


ES_t EXTI_enuSetSenseLevel(u8 Copy_u8SenseLevel ,u8 Copy_u8IntNumber)
{
	ES_t Local_enuErrorState = ES_OK;

	if(Copy_u8IntNumber == EXTI_INT0)
	{
		switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL          : CLR_BIT(MCUCR,MCUCR_ISC00);
		                          CLR_BIT(MCUCR,MCUCR_ISC01);
		    break;
		case ANY_LOGICAL_CHANGE : SET_BIT(MCUCR,MCUCR_ISC00);
								  CLR_BIT(MCUCR,MCUCR_ISC01);
            break;
		case FALLING_EDGE       : CLR_BIT(MCUCR,MCUCR_ISC00);
		             		      SET_BIT(MCUCR,MCUCR_ISC01);
		    break;
		case RISING_EDGE        : SET_BIT(MCUCR,MCUCR_ISC00);
		                          SET_BIT(MCUCR,MCUCR_ISC01);
		    break;
		default                 : Local_enuErrorState = ES_NOK;
		}
	}
	else if(Copy_u8IntNumber == EXTI_INT1)
	{
		switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL          : CLR_BIT(MCUCR,MCUCR_ISC10);
		                          CLR_BIT(MCUCR,MCUCR_ISC11);
		    break;
		case ANY_LOGICAL_CHANGE : SET_BIT(MCUCR,MCUCR_ISC10);
								  CLR_BIT(MCUCR,MCUCR_ISC11);
            break;
		case FALLING_EDGE       : CLR_BIT(MCUCR,MCUCR_ISC10);
		             		      SET_BIT(MCUCR,MCUCR_ISC11);
		    break;
		case RISING_EDGE        : SET_BIT(MCUCR,MCUCR_ISC10);
		                          SET_BIT(MCUCR,MCUCR_ISC11);
		    break;
		default                 : Local_enuErrorState = ES_NOK;
		}
	}
	else if(Copy_u8IntNumber == EXTI_INT2)
	{
		switch(Copy_u8SenseLevel)
		{
		case FALLING_EDGE       : CLR_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		case RISING_EDGE        : SET_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		default                 : Local_enuErrorState = ES_NOK;
		}
		}
	else
	{
		Local_enuErrorState = OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
/*
//INT0
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_fun_ptr[EXTI_INT0] != NULL)
	{
		EXTI_fun_ptr[EXTI_INT0]();
	}
}

//INT1
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_fun_ptr[EXTI_INT1] != NULL)
	{
		EXTI_fun_ptr[EXTI_INT1]();
	}
}

//INT2
void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_fun_ptr[EXTI_INT2] != NULL)
	{
		EXTI_fun_ptr[EXTI_INT2]();
	}
}

*/
