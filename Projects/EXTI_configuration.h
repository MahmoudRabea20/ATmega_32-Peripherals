/*
 * EXTI_config.h
 *
 *  Created on: Feb 14, 2023
 *      Author: top
 */


#ifndef EXTI_CONFIGURATION_H_
#define EXTI_CONFIGURATION_H_

/* Options : 1- LOW_LEVEL
 *           2- ANY_LOGICAL_CHANGE
 *           3- FALLING_EDGE
 *           4- RISING_EDGE
 *
 *   For INT2 only  FALLING_EDGE or  RISING_EDGE      */

#define EXTI_INT0_SENSE_LEVEL		RISING_EDGE
#define EXTI_INT1_SENSE_LEVEL		LOW_LEVEL
#define EXTI_INT2_SENSE_LEVEL		FALLING_EDGE

/* Options : 1- ENABLED
 *           2- DISABLED
 */

#define EXTI_INT0_INIT_STATE        ENABLED
#define EXTI_INT1_INIT_STATE        DISABLED
#define EXTI_INT2_INIT_STATE        DISABLED


#endif /* EXTI_CONFIGURATION_H_ */
