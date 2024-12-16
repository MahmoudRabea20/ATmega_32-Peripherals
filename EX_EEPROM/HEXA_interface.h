/*
 * HEXA_int.h
 *
 *  Created on: Feb 6, 2023
 *      Author: top
 */

#include "errorState.h"
#include "stdTypes.h"

#ifndef HEXA_INT_H_
#define HEXA_INT_H_

ES_t HEXA_enuInit(void);
ES_t HEXA_enuPinEnable(u8 Copy_u8GroupID,u8 Copy_u8PinID);
ES_t HEXA_enuPinDisable(u8 Copy_u8GroupID,u8 Copy_u8PinID);
ES_t HEXA_enuWriteNumber(u8 Copy_u8Value);

#define HEXA_u8PINDISABLE           0
#define HEXA_u8PINENABLE            1

#endif /* HEXA_INT_H_ */
