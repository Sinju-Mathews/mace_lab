#include <stdio.h>
#include <conio.h>
#define MAX 5

int list[MAX], link[MAX];
int start = -1, avail = -1, newnode, ptr, item, pos, COUNT = 0;

void initialize() {
    int i;
    for (i = 0; i < MAX - 1; i++) {
	link[i] = i + 1;
    }
    link[MAX - 1] = -1;  // End of the list
    avail = 0;  // First available node index
}

void insertion() {
    int count = 0, c, p;
    if (avail == -1) {
	printf("--list overflow--\n");
	return;
    }

    printf("\n1. Insert at first\n2. Insert at a certain position\n3. Insert at last\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    printf("Enter the element: ");
    scanf("%d", &item);
    if (c==2)
    {
     printf("Enter the position to insert: ");
	    scanf("%d", &pos);
	    if (pos > COUNT + 1 || pos < 1) {
		printf("Invalid position\n");
		return;
	    }
    }

    newnode = avail;
    avail = link[avail];  // Update avail to next free node
    list[newnode] = item;

    switch (c) {
	case 1:  // Insert at first
	    link[newnode] = start;
	    start = newnode;
	    break;
	case 2:  // Insert at a given position
	    if(pos==1)
	    {
	    link[newnode] = start;
	    start = newnode;
	    }
	    else
	    {
	    p = ptr = start;
	    while (count < pos - 1) {
		p = ptr;
		ptr = link[ptr];
		count++;
	    }
	    link[newnode] = ptr;
	    link[p] = newnode;
	    }
	    break;
	case 3:  // Insert at last
	    if (start == -1) {
		start = newnode;
		link[newnode] = -1;
	    } else {
		ptr = start;
		while (link[ptr] != -1) {
		    ptr = link[ptr];
		}
		link[ptr] = newnode;
		link[newnode] = -1;
	    }
	    break;
	default:
	    printf("Wrong input\n");
	    return;
    }
    printf("Element inserted\n");
    COUNT++;
}

void deletion() {
    int count = 0, c, p;
    if (start == -1) {
	printf("---list underflow---\n");
	return;
    }

    printf("\n1. Delete from first\n2. Delete from a certain position\n3. Delete from last\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    if(c==2)
    {
     printf("Enter the position to delete: ");
	    scanf("%d", &pos);
	    if (pos > COUNT || pos < 1) {
		printf("Invalid position\n");
		return;
	    }
    }

    switch (c) {
	case 1:  // Delete first
	    newnode = start;
	    start = link[start];
	    break;
	case 2:  // Delete from given position

	    if(pos==1)
	    {
	    newnode = start;
	    start = link[start];
	    }
	    else
	    {
	    p = ptr = start;
	    while (count < pos - 1) {
		p = ptr;
		ptr = link[ptr];
		count++;
	    }
	    newnode = ptr;
	    link[p] = link[ptr];
	    }
	    break;
	case 3:  // Delete last
	    p = ptr = start;
	    while (link[ptr] != -1) {
		p = ptr;
		ptr = link[ptr];
	    }
	    newnode = ptr;
	    link[p] = -1;
	    break;
	default:
	    printf("Wrong input\n");
	    return;
    }

    item = list[newnode];
    link[newnode] = avail;
    avail = newnode;
    COUNT--;
    printf("Element deleted is %d\n", item);
}

void display() {
    if (start == -1) {
	printf("List is empty\n");
	return;
    }

    ptr = start;
    while (ptr != -1) {
	printf("%d\t", list[ptr]);
	ptr = link[ptr];
    }
    printf("\n");
}

int main() {
    int i, ch, n;

    clrscr();
    initialize();

    printf("Enter the number of elements you want to insert (<= %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX || n < 1) {
	printf("Enter a number between 1 and %d\n", MAX);
	return 1;
    }

    for (i = 0; i < n; i++) {
	printf("Enter element %d: ", i + 1);
	scanf("%d", &item);
	newnode = avail;
	avail = link[avail];
	list[newnode] = item;
	if (start == -1) {
	    start = newnode;
	} else {
	    ptr = start;
	    while (link[ptr] != -1) {
		ptr = link[ptr];
	    }
	    link[ptr] = newnode;
	}
	link[newnode] = -1;
	COUNT++;
    }

    display();

    do {
	printf("\n1. Insertion\t2. Deletion\t3. Display\t4. Count of elements\t5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);
	switch (ch) {
	    case 1:
		insertion();
		break;
	    case 2:
		deletion();
		break;
	    case 3:
		display();
		break;
	    case 4:
		printf("Count of elements: %d\n", COUNT);
		break;
	    case 5:
		printf("_____EXIT_____\n");
		break;
	    default:
		printf("Wrong input\n");
	}
    } while (ch != 5);

    getch();
    return 0;
}
