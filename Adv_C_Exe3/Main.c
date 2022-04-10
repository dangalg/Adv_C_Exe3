#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

char menu();
void printStack(const Stack* s);

void main() {
	char letter;
	int val;
	Stack S;
	Queue Q;
	initStack(&S);
	initQueue(&Q);

	while (1) {
		switch (menu())
		{
		case '1':
			printf("Enter stack data: ");
			fseek(stdin, 0, SEEK_END);
			scanf_s("%c", &letter);
			push(&S, letter);
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
		case '5':
			flipBetweenHashes("ab");
			break;
		case '6':
			isPalindrome(&S);
			break;
		case '7':
			printf("Enter queue data: ");
			scanf_s("%d", &val);
			enqueue(&Q, val);
			break;
		case '8':
			if (!isEmptyQueue(&Q))
			{
				printf("\n Dequeued %d", dequeue(&Q));
			}
			else
			{
				printf("\ncannot dequeue from empty Stack!\n");
			}
			break;
		case '9':
			printQueue(&Q);
			break;
		case '10':
			rotateQueue(&Q, 1);
			break;
		case '11':
			cutAndReplace(&Q);
			break;
		case '12':
			sortKidsFirst(&Q);
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
\n 1.  Add element to stack \
\n 2.  pop from the stack\
\n 3.  Print stack \
\n 4.  Rotate Stack \
\n 5.  Flip Between Hashes \
\n 6.  Is Palindrome\
\n 7.  Add element to queue \
\n 8.  Dequeue \
\n 9.  Print Queue \
\n 10. Rotate Queue\
\n 11. Cut And Replace \
\n 12. Sort Kids First \
\n 0.  Exit \n\
\n Your choice: ");
	fseek(stdin, SEEK_END, 0);
	char c = getchar();
	return(c);
}
