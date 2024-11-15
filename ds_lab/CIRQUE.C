#include <stdio.h>
#include <conio.h>
#define MAX 10

int front=-1,rear=-1;

void enqueue(int item, int n, int s[]) {
    if ((rear+1)%n==front)
     {
	printf("\n--insertion failed: queue full--");
     }
     else
      {
	if(front==-1) // Insert first element
	    front=rear=0;
	else
	    rear=(rear + 1)%n;
     s[rear]=item;
    }
}

int dequeue(int n, int s[]) {
    int item;
    if (front==-1)
    {
      printf("\n--queue empty--");
      return 0;
    }
    else
    {
     item = s[front];
     if (front == rear) // Queue has only one element
	front = rear = -1;
     else
	front = (front + 1) % n;
     return item;
    }
}

void display(int n, int s[]) {
    int i;
    if (front==-1) {
	printf("\n--queue empty--");
	return;
    }
    printf("\nQueue elements are: ");
    for (i=front;i!=rear;i=(i+1)%n)
	printf("%d ",s[i]);
    printf("%d ",s[rear]);
}

int main() {
    int c, n, item, s[MAX];
    clrscr();
    printf("Enter the limit (<=%d):\n",MAX);
    scanf("%d", &n);
    if (n > MAX) {
	printf("Limit exceeds maximum size of %d\n", MAX);
	return 1;
    }
    printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
    do {
	printf("\nEnter your choice: ");
	scanf("%d", &c);
	switch (c) {
	    case 1:
		printf("\nEnter the element to be inserted: ");
		scanf("%d", &item);
		enqueue(item, n, s);
		break;
	    case 2:
		item = dequeue(n, s);
		if (item)
		    printf("\nDeleted element: %d\n", item);
		break;
	    case 3:
		display(n, s);
		break;
	    case 4:
		printf("-----exit-----\n");
		break;
	    default:
		printf("Invalid input\n");
	}
    } while (c != 4);
    getch();
    return 0;
}
