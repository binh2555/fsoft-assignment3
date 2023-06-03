#include "LinkedList.h"

#define MAX_SIZE_OF_ARR (20U)
#define MAX_LENGTH_OF_SELECT (15U)

int main(void)
{
	uint8_t assignment3[MAX_SIZE_OF_ARR];
	MyIntNode linkedList[MAX_SIZE_OF_ARR];
	uint32_t inputData = -1;
	uint8_t select[MAX_LENGTH_OF_SELECT] = {0};    /* this array store the selection that user entered */
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
                	inputData = -1;
                	if ('n' == getData(&inputData) || inputData < 0 || inputData > 19)
                	{
                		printf("\nnhap data that bai");
					}
					else
					{
						printf("\nenter the value : ");
						if ('n' == getData(&inputData) || inputData < 0 || inputData >100);
					}
                    printf("\n");
                    system("pause");
                    break;    
                case '2':    /* if select is '2' */
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
            fflush(stdin);
            printf("\n");
            system("pause");
        }
    }
	
	return 0;
}

