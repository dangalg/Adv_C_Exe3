#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

int menu();
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
		case 1:
			printf("Enter stack data: ");
			fseek(stdin, 0, SEEK_END);
			scanf_s("%c", &letter);
			push(&S, letter);
			break;
		case 2:
			if (!isEmptyStack(&S))
			{
				printf("\n Poped %d", pop(&S));
			}
			else
			{
				printf("\ncannot pop from empty Stack!\n");
			}
			break;
		case 3:
			printStack(&S);
			printf("\n");
			break;
		case 4:
			push(&S, 'D');
			push(&S, 'E');
			push(&S, 'F');
			push(&S, 'A');
			push(&S, 'B');
			push(&S, 'C');
			printf("Normal Stack:\n");
			printStack(&S);
			printf("\n");
			rotateStack(&S, 3);
			printf("Rotated 3 Stack:\n");
			printStack(&S);
			printf("\n");
			destroyStack(&S);
			initStack(&S);
			break;
		case 5:
			printf("Normal sentence:\n");
			printf("#meR#embe#siht r# practice\n");
			printf("flipped hash sentence:\n");
			flipBetweenHashes("#meR#embe#siht r# practice");
			break;
		case 6:
			push(&S, 'M');
			push(&S, 'A');
			push(&S, 'D');
			push(&S, 'R');
			push(&S, 'M');
			printStack(&S);
			printf("\n");
			if (isPalindrome(&S))
			{
				printf("This is a Palindrome");
			}
			else
			{
				printf("This is not a Palindrome");
			}
			destroyStack(&S);
			initStack(&S);
			break;
		case 7:
			printf("Enter queue data: ");
			scanf_s("%d", &val);
			enqueue(&Q, val);
			break;
		case 8:
			if (!isEmptyQueue(&Q))
			{
				printf("\n Dequeued %d", dequeue(&Q));
			}
			else
			{
				printf("\ncannot dequeue from empty Stack!\n");
			}
			break;
		case 9:
			printQueue(&Q);
			break;
		case 10:
			enqueue(&Q, 6);
			enqueue(&Q, 5);
			enqueue(&Q, 4);
			enqueue(&Q, 3);
			enqueue(&Q, 2);
			enqueue(&Q, 1);
			printf("Normal Queue:\n");
			printQueue(&Q);
			printf("\n");
			rotateQueue(&Q);
			printf("Rotated Queue:\n");
			printQueue(&Q);
			printf("\n");
			destroyQueue(&Q);
			initQueue(&Q);
			break;
		case 11:
			enqueue(&Q, 6);
			enqueue(&Q, 5);
			enqueue(&Q, 2);
			enqueue(&Q, 3);
			enqueue(&Q, 1);
			enqueue(&Q, 9);
			printf("Normal Queue:\n");
			printQueue(&Q);
			printf("\n");
			cutAndReplace(&Q);
			printf("Cut And Replaced Queue:\n");
			printQueue(&Q);
			printf("\n");
			destroyQueue(&Q);
			initQueue(&Q);
			break;
		case 12:
			enqueue(&Q, 6);
			enqueue(&Q, 1);
			enqueue(&Q, 5);
			enqueue(&Q, 2);
			enqueue(&Q, 3);
			enqueue(&Q, 1);
			enqueue(&Q, 9);
			printf("Normal Queue:\n");
			printQueue(&Q);
			printf("\n");
			sortKidsFirst(&Q);
			printf("Sort Kids First Queue:\n");
			printQueue(&Q);
			printf("\n");
			destroyQueue(&Q);
			initQueue(&Q);
			break;
		case 0:
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

int menu()
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
	int res = 0;
	scanf("%d", &res);
	return(res);
}
