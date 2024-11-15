#include <stdio.h>
#include <conio.h>

#define MAX 10
int list[MAX], prev[MAX], next[MAX];
int start = -1, last = -1, avail = 0, newnode, ptr, item, pos, COUNT = 0;

void initialize() {
    int i;
    for (i = 0; i < MAX - 1; i++) {
	next[i] = i + 1;
    }
    next[i] = -1;
    avail = 0;
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
    if (c == 2) {
	printf("Enter the position to insert: ");
	scanf("%d", &pos);
	if (pos > COUNT + 1 || pos < 1) {
	    printf("Invalid position\n");
	    return;
	}
    }

    printf("Enter the element: ");
    scanf("%d", &item);


    newnode = avail;
    avail = next[avail];
    if (avail != -1) {
	prev[avail] = -1;
    }
    list[newnode] = item;
    next[newnode] = -1;
    prev[newnode] = -1;

    switch (c) {
	case 1:  // Insert at first
	    if (start == -1) {
		start = last = newnode;
	    } else {
		next[newnode] = start;
		prev[start] = newnode;
		start = newnode;
	    }
	    break;
	case 2:  // Insert at a given position
	    if (pos == 1) {
		if (start == -1) {
		    start = last = newnode;
		} else {
		    next[newnode] = start;
		    prev[start] = newnode;
		    start = newnode;
		}
	    } else if (pos == COUNT + 1) {
		if (last == -1) {
		    start = last = newnode;
		} else {
		    next[last] = newnode;
		    prev[newnode] = last;
		    last = newnode;
		}
	    } else {
		p = ptr = start;
		while (count < pos - 1) {
		    p = ptr;
		    ptr = next[ptr];
		    count++;
		}
		next[newnode] = ptr;
		prev[newnode] = p;
		next[p] = newnode;
		prev[ptr] = newnode;
	    }
	    break;
	case 3:  // Insert at last
	    if (last == -1) {
		start = last = newnode;
	    } else {
		next[last] = newnode;
		prev[newnode] = last;
		last = newnode;
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
    if (c == 2) {
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
	    start = next[start];
	    if (start == -1) {
		last = -1;
	    } else {
		prev[start] = -1;
	    }
	    break;
	case 2:  // Delete from a given position
	if(pos==1)
	   {
	    newnode = start;
	    start = next[start];
	    if (start == -1) {
		last = -1;
	    } else {
		prev[start] = -1;
	    }
	   }
	   else if(pos==COUNT)
	   {
	    newnode = last;
	    last = prev[last];
	    if (last == -1) {
		start = -1;
	    } else {
		next[last] = -1;
	    }
	   }
	   else
	   {
	    p = ptr = start;
	    while (count < pos - 1) {
		p = ptr;
		ptr = next[ptr];
		count++;
	    }
	    newnode = ptr;
	    next[p] = next[ptr];
	    if (next[ptr] != -1) {
		prev[next[ptr]] = p;
	    } else {
		last = p;
	    }
	    }
	    break;
	case 3:  // Delete last
	    newnode = last;
	    last = prev[last];
	    if (last == -1) {
		start = -1;
	    } else {
		next[last] = -1;
	    }
	    break;
	default:
	    printf("Wrong input\n");
	    return;
    }

    item = list[newnode];
    next[newnode] = avail;
    prev[newnode] = -1;
    avail = newnode;
    COUNT--;
    printf("Element deleted is %d\n", item);
}

void display() {
    if (start == -1) {
	printf("List is empty\n");
	return;
    }

    printf("\nIn normal order: ");
    ptr = start;
    while (ptr != -1) {
	printf("%d\t", list[ptr]);
	ptr = next[ptr];
    }

    printf("\nIn reverse order: ");
    ptr = last;
    while (ptr != -1) {
	printf("%d\t", list[ptr]);
	ptr = prev[ptr];
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
	avail = next[avail];
	list[newnode] = item;
	next[newnode]=-1;
	prev[newnode]=-1;

	if (start == -1) {
	    start = last = newnode;
	} else {
	    next[last] = newnode;
	    prev[newnode] = last;
	    last = newnode;
	}
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
