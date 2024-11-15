#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

typedef struct node NODE;
NODE *top = NULL, *nnode, *temp;
int c = 0, item;

void push() {
    nnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter the Element: ");
    scanf("%d", &item);
    nnode->info = item;
    nnode->next = NULL;

    if (top == NULL) {
	top = nnode;
    } else {
	nnode->next = top;
	top = nnode;
    }
    c++;
}

void pop() {
    if (top == NULL) {
	printf("Empty Stack\n");
    } else {
	printf("Popped element is %d\n", top->info);
	top = top->next;
	c--;
    }
}

void display() {
    temp = top;
    if (temp == NULL) {
	printf("Empty Stack\n");
    } else {
	while (temp != NULL) {
	    printf("%d ", temp->info);
	    temp = temp->next;
	}
	printf("COUNT: %d\n", c);
    }
}

void main() {
    int ch;
    clrscr();
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    do {
	printf("\nEnter Choice: ");
	scanf("%d", &ch);
	switch (ch) {
	    case 1:
		push();
		break;
	    case 2:
		pop();
		break;
	    case 3:
		display();
		break;
	    case 4:
		printf("Exit\n");
		break;
	    default:
		printf("Invalid Choice\n");
	}
    } while (ch != 4);
    getch();
}
