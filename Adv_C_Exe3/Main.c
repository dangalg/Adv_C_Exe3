#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

char menu();
void printStack(const Stack* s);

void main() {
	int num;
	Stack S;
	Queue Q;
	initStack(&S);
	initQueue(&Q);

	while (1) {
		switch (menu())
		{
		case '1':
			printf("Enter the data: ");
			scanf_s("%d", &num);
			push(&S, num);
			break;
		case '2':
			if (!isEmptyStack(&S))
			{
				printf("\n Poped %d", pop(&S));
			}
			else
			{
				printf("\ncannot pop from empty Stack!\n");
			}
			break;
		case '3':
			printStack(&S);
			break;
		case '4':
			rotateStack(&S, 1);
			break;
		case '0':
			printf("\n Exit ");
			system("pause");
			return;
		default:
			printf("\n Wrong. Pls try again");
		}// switch 
	}// while 

	destroyStack(&S);
	destroyQueue(&Q);

}// main 

char menu()
{
	printf("\n\t MAIN MENU:\
\n 1. Add element to stack \
\n 2. Delete element from the stack\
\n 3. Display stack \
\n 4. Rotate Stack \
\n 0. Exit \n\
\n Your choice: ");
	fseek(stdin, SEEK_END, 0);
	char c = getchar();
	return(c);
}
