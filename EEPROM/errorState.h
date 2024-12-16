/*
 * errorState.h
 *
 *  Created on: Feb 5, 2023
 *      Author: top
 */

#ifndef ERRORSTATE_H_
#define ERRORSTATE_H_

typedef enum
{
	ES_NOK,
	ES_OK,
	OUT_OF_RANGE,
	NULL_POINTER
}ES_t;

typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,

}TWI_ErrorStatus;

#endif /* ERRORSTATE_H_ */
