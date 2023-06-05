#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdint.h>
#include <stdio.h>
#include "CheckInput.h"

/*******************************************************************************
* Definitions
******************************************************************************/
struct intNode{
	uint8_t index;
	uint8_t *value;
	struct intNode *nextNode;
};
typedef struct intNode MyIntNode;

/*******************************************************************************
* API
******************************************************************************/

/*******************************************************************************
* implementation
* function setUpArr is used to set value 0xff to each element of array
* parameters : 
				@arr : the array you want to set the value
				@numOfArr : the number of element of array
* return : void
******************************************************************************/
void setUpArr(uint8_t arr[],uint32_t numOfArr);

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
void matchLinkedListAndArr(uint8_t arr[],MyIntNode linkedList[],uint32_t numOfArr);

/*******************************************************************************
* implementation
* function printLinkedList is used to print the linked list
* parameters : 
				@linkedList : the linkedList you want to print
				@numOfArr : the number of element of linkedList
* return : void
******************************************************************************/
void printLinkedList(MyIntNode linkedList[], uint8_t numOfArr);

/*******************************************************************************
* implementation
* function sortAscending is used to sort the linked list in ascending order
* parameters : 
				@linkedList : the linkedList you want to sort
				@numOfArr : the number of element of linkedList
* return : void
******************************************************************************/
void sortAscending(MyIntNode *head, uint8_t numOfArr);

/*******************************************************************************
* implementation
* function printArr is used to print the array
* parameters : 
				@arr : the array you want to print
				@numOfArr : the number of element of array
* return : void
******************************************************************************/
void printArr(uint8_t arr[],uint8_t numOfArr);

uint8_t isElementEnterd(MyIntNode *head,uint8_t findIndex);
void writeDataToNode(MyIntNode *head, uint8_t index, uint8_t value);
uint8_t removeData(MyIntNode *head, uint8_t value);
void printLinkedListInAscendingOrder(MyIntNode *head);
void printLinkedListInElementOrder(MyIntNode *head,uint8_t number);

#endif    /* _LINKEDLIST_H_ */

