/*
 * EXTI_priv.h
 *
 *  Created on: Feb 14, 2023
 *      Author: top
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define GICR                             *((volatile u8 *) 0x5B)       /* PIE Register                  */
#define GICR_INT1_ENABLE_BIT             7                             /* to enable INT1                */
#define GICR_INT0_ENABLE_BIT             6                             /* to enable INT0                */
#define GICR_INT2_ENABLE_BIt             5                             /* to enable INT2                */

#define MCUCR                            *((volatile u8 *) 0x55)       /* Sense control for INT1 & INT0 */
#define MCUCR_ISC00                      0
#define MCUCR_ISC01                      1
#define MCUCR_ISC10                      2
#define MCUCR_ISC11                      3

#define MCUCSR                           *((volatile u8 *) 0x54)       /* Sense control for INT2        */
#define MCUCSR_ISC2                      6

#define LOW_LEVEL                        1
#define ANY_LOGICAL_CHANGE               2
#define FALLING_EDGE                     3
#define RISING_EDGE                      4

#define ENABLED                          1
#define DISABLED                         2



#endif /* EXTI_PRIVATE_H_ */
