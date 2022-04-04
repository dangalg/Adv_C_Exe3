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
	intNode* tmp = q->tail;
	intNode* next = NULL;
		while (tmp != NULL)
		{
			next = tmp->next;
			free(tmp);
		    tmp = next;
	    }
		q->head = NULL;
}

void enqueue(Queue* q, unsigned int data)
{
	// add element to tail of queue
	intNode* p = (intNode*)malloc(sizeof(intNode));
	if (!p) { printf("memory allocation failed"); exit(1); }

	// set element data 
	p->data = data; 
	p->next = NULL;

	if (!isEmptyQueue(q)) {
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
	if (isEmptyQueue(q))
	{
		printf ("Cannot dequeue an empty queue!");
		return 0;
	}
	int temp = q->head->data;
	intNode* p = q->head;
	q->head = q->head->next;
	if (q->head == NULL) //if queue gets empty
		q->tail = NULL;  //both front and rear NULL
	free(p);
	return temp;
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
	if (isEmptyQueue(q) == 1)
	{
		printf("\n");
		printf("There is no queue to rotate.");
	}
	else
	{
		intNode* temp = q->head;
		intNode* last = q->tail;
		last = q->head;
		temp = q->tail;
			return last;
	}
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