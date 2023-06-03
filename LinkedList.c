#include "LinkedList.h"

#define MAX_LENGTH_OF_ARR 15U    /* the limit of data length that user can enter */


void setUpArr(uint8_t arr[],uint32_t numOfArr)
{
	for (uint32_t i = 0; i < numOfArr; i++)
	{
		arr[i] = 0xff;
	}
}

void matchLinkedListAndArr(uint8_t arr[],MyIntNode linkedList[],uint32_t numOfArr)
{
	for (uint8_t i = 0; i < numOfArr; i++)
	{
		linkedList[i].value = &arr[i];
		linkedList[i].index = i;
		if (i == 19)
		{
			linkedList[i].nextNode = NULL;
		}
		else
		{
			linkedList[i].nextNode = &linkedList[i+1];
		}
	}
}

void printLinkedList(MyIntNode linkedList[], uint8_t numOfArr)
{	
	for(uint8_t count = 0; count < 20; count++)
	{
		printf("\nindex =  %d,the element number %d = %d",linkedList[count].index, count+1, *(linkedList[count].value));
	}
}

void sortAscending(MyIntNode linkedList[], uint32_t numOfArr)
{
	for (uint32_t count1 = 0; count1 < numOfArr -1; count1++)
	{
		for (uint32_t count2=count1+1; count2 < numOfArr; count2++)
		{
			if (*(linkedList[count1].value) > *(linkedList[count2].value))
			{
				MyIntNode temp = linkedList[count1];
				linkedList[count1] = linkedList[count2];
				linkedList[count2] = temp;
			}
		}
	}
}

