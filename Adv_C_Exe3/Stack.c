#include "Stack.h"
#include <stdio.h>
/***************** Stack ADT Implementation *****************/

void removeHead(charNode** head);
void printStack(const Stack* s);

void initStack(Stack* s)
{
	// add your code here
}

void destroyStack(Stack* s)
{
	// get first object
	charNode* tmp = s->head;
	charNode* next = NULL;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}

	s->head = NULL;
}

void push(Stack* s, char data)
{
	// add your code here
}

char pop(Stack* s)
{
	// add your code here
	char res;
	if (s != NULL) { printf("\nStack is empty"); return NULL; }
	res = s->head->data;
	removeHead(s->head);
	return res;
}

int isEmptyStack(const Stack* s)
{
	// add your code here
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	if (sentence == NULL)
	{
		return;
	}

	// add your code here
	Stack* tmpStack = NULL;
	initStack(tmpStack);

	// counts the amount of hashes
	int hashAmount = 0;

	while (*sentence)
	{
		// catch # and decide what to do
		char tmpChar = *sentence;
		if (tmpChar == "#")
		{
			// increment hash amount
			hashAmount++;

			// after the second has print the temp stack and empty it
			if (hashAmount == 2)
			{
				// reset has amount
				hashAmount = 0;

				// print and destroy temp stack
				printStack(tmpStack);
				destroyStack(tmpStack);
			}
		}
		
		// no hashes just print the char
		if (hashAmount == 0)
		{
			printf("%c", tmpChar);
		}

		// between hashes insert chars to temp stack
		if (hashAmount == 1)
		{
			push(tmpStack, tmpChar);
		}

		sentence++;
	}
}

int isPalindrome(Stack* s)
{
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}

void removeHead(charNode** head)
{
	if (head == NULL)
	{
		return;
	}

	charNode* tmp = (*head)->next;
	free(*head);
	(*head) = tmp;
}

void printStack(const Stack* s)
{
	charNode* tmp = s->head;
	while (tmp != NULL)
	{
		printf("%c", tmp->data);
		tmp = tmp->next;
	}
}