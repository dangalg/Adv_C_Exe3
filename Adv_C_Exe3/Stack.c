#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
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


char pop(Stack* s)
{
	// add your code here
	char res;
	if (s->head == NULL) 
	{ 
		return NULL; 
	}
	res = s->head->data;
	removeHead(&s->head);
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

	Stack tmpStack;
	initStack(&tmpStack);

	// counts the amount of hashes
	int hashAmount = 0;

	while (*sentence)
	{
		// catch # and decide what to do
		char tmpChar = *sentence;
		if (tmpChar == '#')
		{
			// increment hash amount
			hashAmount++;

			// after the second hash print the temp stack and empty it
			if (hashAmount == 2)
			{
				// reset has amount
				hashAmount = 0;

				// print and destroy temp stack
				printStack(&tmpStack);
				destroyStack(&tmpStack);
			}
		}
		
		// no hashes just print the char
		else if (hashAmount == 0)
		{
			printf("%c", tmpChar);
		}

		// between hashes insert chars to temp stack
		else if (hashAmount == 1)
		{
			push(&tmpStack, tmpChar);
		}

		sentence++;
	}

	destroyStack(&tmpStack);
}

// להכניס למחסנית עזר, זה יהפוך את הסדר ואז להשוות עם המחסנית המקורית
int isPalindrome(Stack* s)
{
	Stack tmpStack , tmpStack2 , tmpStack3;
	initStack(&tmpStack);
	initStack(&tmpStack2);
	initStack(&tmpStack3);

	int counter=0;

	// get length of stack
	while (!isEmptyStack(s))
	{
		push(&tmpStack, pop(s));
		counter++;
	}

	char middleChar;
	int evenList = 0;

	// if stack is even get half the stack into another stack
	if ((counter % 2) == 0)
	{
		evenList = 1;
		for (int i = 0; i < counter / 2; i++)
		{
			push(&tmpStack2, pop(&tmpStack));
		}
	}
	// if stack is odd save the middle char and get half the stack into another stack
	else
	{
		for (int i = 0; i < counter / 2; i++)
		{
			push(&tmpStack2, pop(&tmpStack));
		}
		middleChar = pop(&tmpStack);
	}

	// compare the two halves, if they are equal it is a palindrome
	int val1, val2 , isPalindrom=1;
	while (!isEmptyStack(&tmpStack))
	{
		val1 = pop(&tmpStack);
		val2 = pop(&tmpStack2);
		if (val1 != val2)
		{
			isPalindrom = 0;
		}

		// return the first half to q
		push(s, val1);
		// save the second half to return to q later
		push(&tmpStack3, val2);
	}

	// push middle char back to q
	if (!evenList)
	{
		push(s, middleChar);
	}
	
	// push the second half back to q
	while (!isEmptyStack(&tmpStack3))
	{
		push(s, pop(&tmpStack3));
	}

	destroyStack(&tmpStack);
	destroyStack(&tmpStack2);
	destroyStack(&tmpStack3);

	return isPalindrom;

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

	Stack tmpStack;
	initStack(&tmpStack);
	int counter = 0;

	// push all chars to temp stack
	char letter;
	while (!isEmptyStack(s))
	{
		letter = pop(s);
		counter++;
		push(&tmpStack, letter);
	}

	// there are less items in the stack than n so return items to stack and return
	if (counter < n)
	{
		while (!isEmptyStack(s))
		{
			letter = pop(s);
			counter++;
			push(s, letter);
		}
		destroyStack(&tmpStack);
		return;
	}

	Stack sideStack;
	initStack(&sideStack);

	// insert first n items into side stack 
	for (int i = 0; i < n; i++)
	{
		push(&sideStack, pop(&tmpStack));
	}

	// insert the rest back into original stack
	while (!isEmptyStack(&tmpStack))
	{
		letter = pop(&tmpStack);
		push(s, letter);
	}

	// insert n items back into tmp stack to flip them
	while (!isEmptyStack(&sideStack))
	{
		letter = pop(&sideStack);
		push(&tmpStack, letter);
	}
	
	// return them back to original stack
	while (!isEmptyStack(&tmpStack))
	{
		letter = pop(&tmpStack);
		push(s, letter);
	}

	destroyStack(&tmpStack);
	destroyStack(&sideStack);

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
	Stack tmpStack;
	initStack(&tmpStack);
	char letter;
	while (!isEmptyStack(s))
	{
		letter = pop(s);
		printf("%c", letter);
		push(&tmpStack, letter);
	}

	while (!isEmptyStack(&tmpStack))
	{
		letter = pop(&tmpStack);
		
		push(s, letter);
	}

	destroyStack(&tmpStack);
}

//pushing the chars inside the stack.
charNode* addToHead(charNode* head, charNode* toAdd)
{
	toAdd->next = head;
	head = toAdd;
	return head;
}