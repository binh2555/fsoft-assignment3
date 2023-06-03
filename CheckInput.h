#ifndef _CHECKINPUT_H_
#define _CHECKINPUT_H_

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
* API
******************************************************************************/
uint8_t getData(uint32_t *variableStoreValue);    /* function for user enter data */
uint8_t checkArrIsInteger(uint8_t arr[]);    /* function to check a array is only the integer character */

#endif    /* _CHECKINPUT_H_ */

