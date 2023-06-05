#include "LinkedList.h"

/*******************************************************************************
* Definitions
******************************************************************************/
#define MAX_LENGTH_OF_ARR 15U    /* the limit of data length that user can enter */

static void swap(uint8_t *a, uint8_t *b);

/*******************************************************************************
* implementation
* function setUpArr is used to set value 0xff to each element of array
* parameters : 
				@arr : the array you want to set the value
				@numOfArr : the number of element of array
* return : void
******************************************************************************/
void setUpArr(uint8_t arr[],uint32_t numOfArr)
{
	for (uint32_t i = 0; i < numOfArr; i++)
	{
		arr[i] = 0xff;
	}
}

/*******************************************************************************
* implementation
* function matchLinkedListAndArr is used to match each element of array to each node of
the linked list correcsponding
* parameters : 
				@arr : the array you want to match
				@linkedList : the linked list you want to match to array
				@numOfArr : the number of element of array aslo of linkedList
* return : void
******************************************************************************/
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

/*******************************************************************************
* implementation
* function printLinkedList is used to print the linked list
* parameters : 
				@linkedList : the linkedList you want to print
				@numOfArr : the number of element of linkedList
* return : void
******************************************************************************/
void printLinkedList(MyIntNode linkedList[], uint8_t numOfArr)
{	
	for(uint8_t count = 0; count < 20; count++)
	{
		printf("\nthe element number %d = %d", count, *(linkedList[count].value));
	}
}

static void swap(uint8_t *a, uint8_t *b)
{
	uint8_t temp = *a;
	*a = *b;
	*b = temp;
}

/*******************************************************************************
* implementation
* function sortAscending is used to sort the linked list in ascending order
* parameters : 
				@linkedList : the linkedList you want to sort
				@numOfArr : the number of element of linkedList
* return : void
******************************************************************************/
void sortAscending(MyIntNode *head, uint8_t numOfArr)
{
	int count = 0;
	MyIntNode *temp = head;
	MyIntNode *jump = temp->nextNode;
	uint8_t swapValue = 0;
	uint8_t swapIndex = 0;
	
	for (count = 0; count < numOfArr; count++)
	{
		jump = temp->nextNode;
		while (NULL != jump)
		{
			if (*(temp->value) > *(jump->value))
			{
				swap(temp->value, jump->value);
				swap(&(temp->index), &(jump->index));
				//jump = NULL;	
			}
			jump = jump->nextNode;
		}
		temp = temp->nextNode;
	}
}

/*******************************************************************************
* implementation
* function printArr is used to print the array
* parameters : 
				@arr : the array you want to print
				@numOfArr : the number of element of array
* return : void
******************************************************************************/
void printArr(uint8_t arr[],uint8_t numOfArr)
{
	for(uint8_t count = 0; count < numOfArr; count++)
	{
		printf("\nthe element number %d = %d", count, arr[count]);
	}
}

uint8_t isElementEnterd(MyIntNode *head,uint8_t findIndex)
{
	uint8_t flagReturn = 'n';
	MyIntNode *temp = head;
	
	while(temp != NULL)
	{
		if (temp->index == findIndex)
		{
			if (*(temp->value) != 0xff)
			{
				flagReturn = 'y';
			}
		}
		temp = temp->nextNode;
	}
	
	return flagReturn;
}

void writeDataToNode(MyIntNode *head, uint8_t index, uint8_t value)
{
	MyIntNode *temp = head;
	
	while(temp != NULL)
	{
		if (temp->index == index)
		{
			*(temp->value) = value;
			temp = NULL;
		}
		else
		{
			temp = temp->nextNode;
		}
	}
}

uint8_t removeData(MyIntNode *head, uint8_t value)
{
	MyIntNode *temp = head;
	uint8_t flagOfRemoveFunc = 'n';
	
	while(temp != NULL)
	{
		if (value == *(temp->value))
		{
			*(temp->value) = 0xff;
			flagOfRemoveFunc = 'y';
			temp = NULL;
		}
		else
		{
			temp = temp->nextNode;
		}
	}
	
	return flagOfRemoveFunc;
}

void printLinkedListInElementOrder(MyIntNode *head,uint8_t number)
{
	int count = 0;
	MyIntNode *temp = head;
	
	for (count = 0; count < number; count++)
	{
		temp = head;
		while(NULL != temp)
		{
			if(count == temp->index)
			{
				printf("\nindex = %d, value = %d", temp->index, *(temp->value));
				temp = NULL;
			}
			else
			{
				temp = temp->nextNode;
			}
		}
	}
}

void printLinkedListInAscendingOrder(MyIntNode *head)
{
	MyIntNode *temp = head;
	while(temp != NULL)
	{
		printf("\n index : %d , value = %d", temp->index, *(temp->value));
		temp = temp->nextNode;
	}
}

