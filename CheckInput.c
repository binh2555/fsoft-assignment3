#include "CheckInput.h"

/*******************************************************************************
* Definitions
******************************************************************************/
#define MAX_LENGTH_OF_ARR 15U    /* the limit of data length that user can enter */

/*******************************************************************************
* Code implementation
* function for user enter data
* Paremeter:
        @variableStoreValue : this variable is used to store the input data as integer
* Return: this function return 'n' if data that user entered is invalid,valid data
          must be only integer characters,if data is valid,this function return 'y'
******************************************************************************/
uint8_t getData(uint32_t *variableStoreValue)
{
    uint8_t data[MAX_LENGTH_OF_ARR] = {0};    /* this array store data that user entered */
    uint8_t getDataFlag1 = 0;    /* this variable is used to store the status of data,the status can be valid or invalid */
    uint8_t getDataFlag2 = 'n';    /* this variable is used to store the status of getData function,if this function success,
                                    * getDataFlag2 = 'y', else getDataFlag2 = 'n' */
    uint32_t signOfValue = 1;    /* this value store sign of input data */

    fflush(stdin);
    fgets(data,MAX_LENGTH_OF_ARR,stdin);
    if ('-' == data[0])
    {
        data[0] = '0';
        signOfValue = -1;
    }
    getDataFlag1 = checkArrIsInteger(data);

    if ('y' == getDataFlag1)
    {
        *variableStoreValue = atoi(data) * signOfValue;
        getDataFlag2 = 'y';
    }
    
    return getDataFlag2;
}

/*******************************************************************************
* Code implementation
* function to check a array is only the integer character
* Paremeter:
        @arr[] : the array need to check
* Return: if yes return 'y',no return 'n'
******************************************************************************/
uint8_t checkArrIsInteger(uint8_t arr[])
{
    uint8_t checkFlag = 'y';    /* this variable is used to store the status of the character array which is passed */
    
    for (uint32_t count=0; arr[count+1]!='\0'; count++)
    {
        if (0 == isdigit(arr[count]))
        {
            checkFlag = 'n';
        }
    }
    
    return checkFlag;
}

