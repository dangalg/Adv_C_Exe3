#include "Stack.h"
#include <stdio.h>
/***************** Stack ADT Implementation *****************/
charNode* addToHead(charNode* head, charNode* toAdd);
void removeHead(charNode** head);
void printStack(const Stack* s);

void initStack(Stack* s)
{
	// add your code here
	s->head = NULL;
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
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL) {
		printf("push: memory allocation problem\n");
		return;
	}
	newnode->data = data;
	s->head= addToHead(s->head, newnode);
}

//pushing the chars inside the stack.
charNode* addToHead(charNode* head, charNode* toAdd)
{
	toAdd->next = head;
	head = toAdd;
	return head;
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
	return (!(s->head));
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	if (sentence == NULL)
	{
		return;
	}

	// add your code here
	Stack* tmpStack = (Stack*)malloc(sizeof(Stack));
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

	destroyStack(tmpStack);
	free(tmpStack);
}

int isPalindrome(Stack* s)
{
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
	if (n < 0)
	{
		return;
	}

	if (s == NULL)
	{
		return;
	}

	Stack* tmpStack = (Stack*)malloc(sizeof(Stack));
	initStack(tmpStack);
	int counter = 0;

	// push all chars to temp stack
	while (s->head != NULL)
	{
		counter++;
		push(tmpStack, pop(s));
	}

	// there are less items in the stack than n so return items to stack and return
	if (counter < n)
	{
		while (tmpStack->head != NULL)
		{
			counter++;
			push(s, pop(s));
		}
		destroyStack(tmpStack);
		return;
	}

	Stack* sideStack = (Stack*)malloc(sizeof(Stack));
	initStack(sideStack);

	// insert first n items into side stack 
	for (int i = 0; i < n; i++)
	{
		push(sideStack, pop(tmpStack));
	}

	// insert the rest back into original stack
	while (tmpStack->head != NULL)
	{
		push(s, pop(tmpStack));
	}

	// insert n items back into tmp stack to flip them
	while (sideStack->head != NULL)
	{
		push(tmpStack, pop(sideStack));
	}
	
	// return them back to original stack
	while (tmpStack->head != NULL)
	{
		push(s, pop(tmpStack));
	}

	destroyStack(tmpStack);
	destroyStack(sideStack);
	free(tmpStack);
	free(sideStack);

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