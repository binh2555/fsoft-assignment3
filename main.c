#include "LinkedList.h"

#define MAX_SIZE_OF_ARR (20U)
#define MAX_LENGTH_OF_SELECT (15U)

int main(void)
{
	uint8_t assignment3[MAX_SIZE_OF_ARR];
	MyIntNode linkedList[MAX_SIZE_OF_ARR];
	uint8_t select[MAX_LENGTH_OF_SELECT] = {0};    /* this array store the selection that user entered */
	uint32_t indexOfCase1 = -1;
	uint32_t valueOfCase1 = -1;
	uint8_t flagOfCase1 = 0;
	uint8_t flagOfCase2 = 0;
	uint32_t removeValue = -1;
	uint8_t exitFlag = 0;   /* this variable store the exit flag */
	
	setUpArr(assignment3,MAX_SIZE_OF_ARR);
	matchLinkedListAndArr(assignment3,linkedList,MAX_SIZE_OF_ARR);

    while(0 == exitFlag)
    {
        system("cls");
        printf("\n\n---------------------MENU-------------------");
        printf("\n Enter 1 : enter value for the element");
        printf("\n Enter 2 : remove the value in array");
        printf("\n Enter 3 : print the array");
        printf("\n Enter 4 : exit");

        printf("\nenter your selection : ");
        
        memset(select,0,sizeof(select));    /* clear array select befor user enter data */
        fflush(stdin);
        fgets(select,sizeof(select),stdin);    /* get data from user */
        system("cls");
        
        if (2 == strlen(select))    /* if input data user entered is right */
        {
            switch(select[0])
            {
                case '1':    /* if select is '1' */
                	printf("\nenter the index : ");
                	flagOfCase1 = getData(&indexOfCase1);
                	if ('n' == flagOfCase1 || indexOfCase1 < 0 || indexOfCase1 > 19 || assignment3[indexOfCase1] != 0xff)
                	{
                		printf("\nfaild!!!!");
                		if ('n' == flagOfCase1)
                		{
                			printf("\nthe data you just entered is invalid!!!");
						}
						else if (indexOfCase1 < 0 || indexOfCase1 > 19)
						{
							printf("\nthe index you must be in range 0 - 19 !!!");
						}
						else if (assignment3[indexOfCase1] != 0xff)
						{
							printf("\nthe index you just entered have exist!!");
						}
					}
					else
					{
						printf("\nenter the value : ");
						flagOfCase1 = getData(&valueOfCase1);
						if ('n' == flagOfCase1 || valueOfCase1 < 0 || valueOfCase1 >100)
						{
							if ('n' == flagOfCase1)
							{
								printf("\nthe data you just entered is invalid!!!");
							}
							else if (valueOfCase1 < 0 || valueOfCase1 > 100)
							{
								printf("\nthe index you must be in range 0 - 100 !!!");
							}
						}
						else
						{
							assignment3[indexOfCase1] = (uint8_t)valueOfCase1;
							printf("\nentered %d into index %d", valueOfCase1, indexOfCase1);
						}
					}
                    printf("\n");
                    system("pause");
                    break;    
                case '2':    /* if select is '2' */
                	printf("\nenter the value you want to remove : ");
                	flagOfCase2 = getData(&removeValue);
                	if ('n' == flagOfCase2 || removeValue < 0 || removeValue > 100)
                	{
                		printf("\nFAILD!!!!");
                		if ('n' == flagOfCase2)
                		{
                			printf("\nthe data you just entered is invalid!!!");
						}
						else if ( removeValue < 0 || removeValue > 100)
						{
							printf("\nthe remove value must be in range 0 - 100 !!!");
						}
					}
					else
					{
						for (uint8_t count = 0; count < 20; count++)
						{
							if (removeValue == assignment3[count])
							{
								assignment3[count] = 0xff;
								printf("\nremoved the value %d", removeValue);
								flagOfCase2 = 1;
							}
						}
						if(1 != flagOfCase2)
						{
							printf("\nhave no value %d in array", removeValue);
						}
					}
                    printf("\n");
                    system("pause");
                    break;
                case '3':    /* if select is '3' */
                    
                    printf("\n");
                    system("pause");
                    break;
                case '4':    /* if select is '4' */
                    exitFlag = 1;
                    printf("\nEXIT!!!!!!!");
                    printf("\n");
                    system("pause");
                    break;
                default :    /* if select is not in menu */
                    printf("\nnot find your request!!!!!");
                    printf("\n");
                    system("pause");
            }
        }
        else    /* if input data user entered is wrong */
        {
            printf("\nnot find your request!!!!!");
            printf("\n");
            system("pause");
        }
    }
	
	return 0;
}

