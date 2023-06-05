#include "LinkedList.h"

/*******************************************************************************
* Definitions
******************************************************************************/
#define MAX_SIZE_OF_ARR (20U)    /* max size of array */
#define MAX_LENGTH_OF_SELECT (15U)    /* the limit of data length that user can enter */

int main(void)
{
	uint8_t assignment3[MAX_SIZE_OF_ARR] = {0};	/* the array to store the data from 0 - 100*/
	MyIntNode linkedList[MAX_SIZE_OF_ARR] = {0};	/* the array of node of linked list we will use */
	uint8_t select[MAX_LENGTH_OF_SELECT] = {0};    /* this array store the selection that user entered */
	MyIntNode *head = linkedList;
	uint32_t indexOfCase1 = -1;    /* the variable to store the index that user entered in case 1 */
	uint32_t valueOfCase1 = -1;    /* the variable to store the value that user entered in case 1 */
	uint8_t flagOfCase1 = 0;	/* the flag of case 1 */
	uint8_t flagOfCase2 = 0;	/* the flag of case 2 */
	uint32_t removeValue = -1;    /* the variable to store the value that user want to remove */
	uint8_t exitFlag = 0;   /* this variable store the exit flag */
	
	setUpArr(assignment3,MAX_SIZE_OF_ARR);    /* set all the element of array assignment3 to 0xff */
	matchLinkedListAndArr(assignment3,linkedList,MAX_SIZE_OF_ARR);    /* match the node of linked list with element of assigment3 corresponding */

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
        fflush(stdin);    /* clear cache befor use function fgets */
        fgets(select,sizeof(select),stdin);    /* get data from user */
        system("cls");
        
        if (2 == strlen(select))    /* if selection user entered is right */
        {
            switch(select[0])
            {
                case '1':    /* if select is '1' */
                	printf("\nenter the index : ");
                	flagOfCase1 = getData(&indexOfCase1);    /* get index to add from user */
                	if ('n' == flagOfCase1 || indexOfCase1 < 0 || indexOfCase1 > 19 || 'y' == isElementEnterd(head,indexOfCase1))    /* if index is invalid */
                	{
                		printf("\nfaild!!!!");
                		if ('n' == flagOfCase1)    /* if input data is invalid,have characters that not integer */
                		{
                			printf("\nthe data you just entered is invalid!!!");
						}
						else if (indexOfCase1 < 0 || indexOfCase1 > 19)    /* if index is out of range 0 - 19 */
						{
							printf("\nthe index you must be in range 0 - 19 !!!");
						}
						else if ('y' == isElementEnterd(head,indexOfCase1))    /* if the index have been entered */
						{
							printf("\nthe index you just entered have exist!!");
						}
					}
					else    /* if index is valid */
					{
						printf("\nenter the value : ");
						flagOfCase1 = getData(&valueOfCase1);    /* get the value */
						if ('n' == flagOfCase1 || valueOfCase1 < 0 || valueOfCase1 >100)    /* if value is invalid */
						{
							if ('n' == flagOfCase1)    /* have characters that is not integer */
							{
								printf("\nthe data you just entered is invalid!!!");
							}
							else if (valueOfCase1 < 0 || valueOfCase1 > 100)    /* the value out of range 0 - 100 */
							{
								printf("\nthe index you must be in range 0 - 100 !!!");
							}
						}
						else    /* value is valid */
						{
							writeDataToNode(head, indexOfCase1, valueOfCase1);
							printf("\nentered %d into index %d", valueOfCase1, indexOfCase1);
						}
					}
                    printf("\n");
                    system("pause");
                    break;    
                case '2':    /* if select is '2' */
                	printf("\nenter the value you want to remove : ");
                	flagOfCase2 = getData(&removeValue);    /* get data from user */
                	if ('n' == flagOfCase2 || removeValue < 0 || removeValue > 100)    /* if data is invalid */
                	{
                		printf("\nFAILD!!!!");
                		if ('n' == flagOfCase2)    /* data user entered is invalid,have characters is not integer */
                		{
                			printf("\nthe data you just entered is invalid!!!");
						}
						else if ( removeValue < 0 || removeValue > 100)    /* the value out of range 0 - 100 */
						{
							printf("\nthe remove value must be in range 0 - 100 !!!");
						}
					}
					else    /* if data is valid,browse the array to find that value in array */
					{
						if ('y' == removeData(head,removeValue))
						{
							printf("\nremove the value %d is successfull!!!", removeValue);
						}
						else
						{
							printf("\nnot have the value %d in array!!!", removeValue);
						}
					}
                    printf("\n");
                    system("pause");
                    break;
                case '3':    /* if select is '3' */
                	printf("\nprint array :");
                    printLinkedListInElementOrder(head,MAX_SIZE_OF_ARR);    /* print the array in element order through linked list */
                    sortAscending(head,MAX_SIZE_OF_ARR);    /* sort the linked list in ascending order */
                    printf("\n\n\nprint arr in ascending order :");
                    printLinkedListInAscendingOrder(head);   /* print the linked list in ascending order */
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

