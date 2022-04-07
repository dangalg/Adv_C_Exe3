#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

char menu();

void main() {
	int num;
	Stack S;
	init(&S, 5);

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
			isPalindrome(&S);
			break;
		case '4':
			retainOddAndOppisetEven(&S);
			break;
		case '0':
			printf("\n Exit ");
			system("pause");
			return;
		default:
			printf("\n Wrong. Pls try again");
		}// switch 
	}// while 

	destroy(&S);

}// main 

char menu()
{
	printf("\n\t MAIN MENU:\
\n 1. Add element to stack \
\n 2. Delete element from the stack\
\n 3. Display stack \
\n 4. sum stack Odds and oppiset evens locations \
\n 0. Exit \n\
\n Your choice: ");
	fseek(stdin, SEEK_END, 0);
	char c = getchar();
	return(c);
}