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

	// create helper stacks
	Queue firstHalfQueue;
	Queue secondHalfQueue;
	Queue tempQueue;
	initQueue(&firstHalfQueue);
	initQueue(&secondHalfQueue);
	initQueue(&tempQueue);

	// get queue length
	int length = 0, val = 0, sum = 0, average = 0;

	while (val = dequeue(q))
	{
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
	int indexToTake = length - 1;
	for (int i = 0; i < length/2; i++)
	{
		if (transferDirection == 1)
		{
			for (int j = 0; j < (length / 2); j++)
			{
				val = dequeue(&secondHalfQueue);
				if (j == indexToTake)
				{
					enqueue(q, val);
				}
				enqueue(&tempQueue, val);
			}
		}
		else
		{
			for (int j = 0; j < (length / 2); j++)
			{
				val = dequeue(&tempQueue);
				if (j == indexToTake)
				{
					enqueue(q, val);
				}
				enqueue(&secondHalfQueue, val);
			}
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
	// add your code here
}