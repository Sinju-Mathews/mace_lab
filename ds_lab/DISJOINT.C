#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int parent[MAX]; // Array to store parent of each element
int rank[MAX];   // Array to store rank of each element

// Function to initialize disjoint sets
void createSet(int n) {
    int i;
    for (i = 0; i < n; i++) {
        parent[i] = i; // Each element is its own parent initially
        rank[i] = 0;   // Initial rank is 0
    }
    printf("Disjoint sets created with %d elements.\n", n);
}

// Function to find the representative of a set
int findSet(int x) {
    if (parent[x] != x) {
        parent[x] = findSet(parent[x]); // Path compression
    }
    return parent[x];
}

// Function to perform union of two sets
void unionSets(int x, int y) {
    int rootX = findSet(x);
    int rootY = findSet(y);

    if (rootX != rootY) {
        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        printf("Union performed on elements %d and %d.\n", x, y);
    } else {
        printf("Elements %d and %d are already in the same set.\n", x, y);
    }
}

// Menu-driven program
int main() {
    int n, choice, x, y;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Number of elements exceeds the maximum allowed (%d).\n", MAX);
        return 1;
    }

    createSet(n);

    do {
        printf("\nMenu:\n");
        printf("1. Find Set\n");
        printf("2. Union Sets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to find its set: ");
                scanf("%d", &x);
                if (x < 0 || x >= n) {
                    printf("Invalid element. Please enter a number between 0 and %d.\n", n - 1);
                } else {
                    printf("Representative of element %d is %d.\n", x, findSet(x));
                }
                break;

            case 2:
                printf("Enter two elements to perform union: ");
                scanf("%d %d", &x, &y);
                if (x < 0 || x >= n || y < 0 || y >= n) {
                    printf("Invalid elements. Please enter numbers between 0 and %d.\n", n - 1);
                } else {
                    unionSets(x, y);
                }
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
