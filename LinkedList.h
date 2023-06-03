#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdint.h>
#include <stdio.h>
#include "CheckInput.h"

struct intNode{
	uint8_t index;
	uint8_t *value;
	struct intNode *nextNode;
};
typedef struct intNode MyIntNode;

void setUpArr(uint8_t arr[],uint32_t numOfArr);
void matchLinkedListAndArr(uint8_t arr[],MyIntNode linkedList[],uint32_t numOfArr);
void printLinkedList(MyIntNode linkedList[], uint8_t numOfArr);
void sortAscending(MyIntNode linkedList[], uint32_t numOffArr);

#endif    /* _LINKEDLIST_H_ */

