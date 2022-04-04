#include "Queue.h"
#include <stdio.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	// add your code here
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	// add your code here
}

void enqueue(Queue* q, unsigned int data)
{
	// add element to tail of queue
	intNode* p = (intNode*)malloc(sizeof(intNode));
	if (!p) { printf("memory allocation failed"); exit(1); }

	// set element data 
	p->data = data; 
	p->next = NULL;

	if (!isEmpty(q)) {
		q->tail->next = p;
	}
	else
	{
		// Otherwise – it becomes first
		q->head = p;
	}

	// update queue tail
	q->tail = p; 
}

unsigned int dequeue(Queue* q)
{
	// add your code here
}

int isEmptyQueue(const Queue* q)
{
	// if list is empty return 1
	if (q->head == NULL)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	// add your code here
}

void cutAndReplace(Queue* q)
{
	if (q == NULL)
	{
		return;
	}


}

void sortKidsFirst(Queue* q)
{
	// add your code here
}