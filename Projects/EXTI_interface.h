/*
 * EXTI_int.h
 *
 *  Created on: Feb 14, 2023
 *      Author: top
 */



#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_INT0                        0
#define EXTI_INT1                        1
#define EXTI_INT2                        2

#define LOW_LEVEL                        1
#define ANY_LOGICAL_CHANGE               2
#define FALLING_EDGE                     3
#define RISING_EDGE                      4

ES_t EXTI_enuInit(void);
ES_t EXTI_enuSetSenseLevel(u8 Copy_u8SenseLevel ,u8 Copy_u8IntNumber);
ES_t EXTI_enuEnableInterrupt(u8 Copy_u8IntNumber);
ES_t EXTI_enuDisableInterrupt(u8 Copy_u8IntNumber);
ES_t EXTI_enuCallBackFunPointer(u8 Copy_u8IntNumber , void (* Copy_pvFunPointer)(void));

#endif /* EXTI_INTERFACE_H_ */
