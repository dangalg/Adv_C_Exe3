﻿#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/***************** Queue ADT Implementation *****************/
int findMinimumInQueue(Queue* q);
void printQueue(const Queue* q);
int getLastValueFromListByIndex(int length, Queue* fromQueue, Queue* toQueue, int index);

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

// להוציא את כולם לתור עזר חוץ מהאחרון, לשמור את האחרון ולשים אותו ראשון בתור חדש
void rotateQueue(Queue* q)
{
	// add your code here
	if (isEmptyQueue(q))
	{
		printf("\n");
		printf("There is no queue to rotate.");
	}
	else
	{
		Queue tmpQueue;
		initQueue(&tmpQueue);
		int lastValue = 0;

		// get last value from list
		while (!isEmptyQueue(q))
		{
			int val = dequeue(q);
			lastValue = val;

			// dont return last value to list
			if (!isEmptyQueue(q))
			{
				enqueue(&tmpQueue, val);
			}
		}

		// insert last value first
		enqueue(q, lastValue);

		// return values to q
		while (!isEmptyQueue(&tmpQueue))
		{
			int val = dequeue(&tmpQueue);
			enqueue(q, val);
		}
	}
}

void cutAndReplace(Queue* q)
{
	if (q == NULL)
	{
		return;
	}

	// create helper stacks
	Queue firstHalfQueue;
	Queue secondHalfQueue;
	Queue tempQueue;
	initQueue(&firstHalfQueue);
	initQueue(&secondHalfQueue);
	initQueue(&tempQueue);

	// get queue length
	int length = 0, val = 0, sum = 0, average = 0;

	while (!isEmptyQueue(q))
	{
		val = dequeue(q);
		// add 1 to length
		length++;

		// add to sum
		sum += val;

		// save value in storage
		enqueue(&secondHalfQueue, val);
	}

	// if length is odd, get the average and add it to the end
	if (length % 2 != 0)
	{
		// get average
		average = sum / length;

		// add average to end of queue
		enqueue(&secondHalfQueue, average);

		// add 1 to length
		length++;
	}

	// split to two queues
	// after this first half of queue will be in firstHalfQueue, second half will be in secondHalfQueue queue
	for (int i = 0; i < length/2; i++)
	{
		enqueue(&firstHalfQueue, dequeue(&secondHalfQueue));
	}

	// flip secondHalfQueue queue
	// in order to flip it we will move it back and forth between secondHalfQueue and tempQueue and save the last value back to q everytime
	int transferDirection = 1;
	int indexToTake = (length / 2) - 1;
	for (int i = 0; i < length/2; i++)
	{
		if (transferDirection == 1)
		{
			enqueue(q, getLastValueFromListByIndex(length, &secondHalfQueue, &tempQueue, indexToTake));
		}
		else
		{
			enqueue(q, getLastValueFromListByIndex(length, &tempQueue, &secondHalfQueue, indexToTake));
		}
		transferDirection *= -1;
		indexToTake--;
	}

	// add first half back to end of queue
	for (int i = 0; i < length / 2; i++)
	{
		enqueue(q, dequeue(&firstHalfQueue));
	}

	destroyQueue(&firstHalfQueue);
	destroyQueue(&secondHalfQueue);
	destroyQueue(&tempQueue);
}

  
void sortKidsFirst(Queue* q)
{
	if (isEmptyQueue(q))
	{
		printf("\n");
		printf("There is no queue please init one.");
		return;
	}
	else
	{
		int val;
		Queue tmpQueue;
		initQueue(&tmpQueue);
		while (!isEmptyQueue(q))
		{
			val = findMinimumInQueue(q);
			enqueue(&tmpQueue, val);
		}
		while (!isEmptyQueue(&tmpQueue))
		{
			enqueue(q, dequeue(&tmpQueue));
		}
	}
}

void printQueue(const Queue* q)
{
	Queue tmpQueue;
	initQueue(&tmpQueue);
	int val;
	while (!isEmptyQueue(q))
	{
		val = dequeue(q);
		enqueue(&tmpQueue, val);
		printf("%d", val);
	}

	while (!isEmptyQueue(&tmpQueue))
	{
		val = dequeue(&tmpQueue);
		enqueue(q, val);
	}

	destroyQueue(&tmpQueue);
}


int findMinimumInQueue(Queue* q)
{
	int min = dequeue(q);
	int val = 0;
	Queue tmpQueue;
	initQueue(&tmpQueue);
	while (!isEmptyQueue(q))
	{
	    val = dequeue(q);
		if(min > val)
		{
			enqueue(&tmpQueue, min);
			min = val;
		}
		else
		{
			enqueue(&tmpQueue, val);
		}
	}
	while (!isEmptyQueue(&tmpQueue))
	{
		enqueue(q,dequeue(&tmpQueue));
	}
	return min;
}

int getLastValueFromListByIndex(int length, Queue* fromQueue, Queue* toQueue, int index)
{
	int val, res = 0;
	for (int j = 0; j < (length / 2); j++)
	{
		val = dequeue(fromQueue);
		if (j == index)
		{
			res = val;
		}
		enqueue(toQueue, val);
	}
	return res;
}