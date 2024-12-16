/*
 * Counter_int.h
 *
 *  Created on: Feb 6, 2023
 *      Author: top
 */

#include "errorState.h"
#include "stdTypes.h"

#ifndef COUNTER_INT_H_
#define COUNTER_INT_H_

ES_t Counter_enuInit(void);
ES_t Counter_enuCount(u8 Copy_u8Start,u8 Copy_u8End);

#endif /* COUNTER_INT_H_ */
