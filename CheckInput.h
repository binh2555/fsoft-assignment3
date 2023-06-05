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

/*******************************************************************************
* Code implementation
* function for user enter data
* Paremeter:
        @variableStoreValue : this variable is used to store the input data as integer
* Return: this function return 'n' if data that user entered is invalid,valid data
          must be only integer characters,if data is valid,this function return 'y'
******************************************************************************/
uint8_t getData(uint32_t *variableStoreValue);    /* function for user enter data */

/*******************************************************************************
* Code implementation
* function to check a array is only the integer character
* Paremeter:
        @arr[] : the array need to check
* Return: if yes return 'y',no return 'n'
******************************************************************************/
uint8_t checkArrIsInteger(uint8_t arr[]);    /* function to check a array is only the integer character */

#endif    /* _CHECKINPUT_H_ */

