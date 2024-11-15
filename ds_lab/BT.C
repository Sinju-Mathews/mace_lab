#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_SIZE 25

struct node {
    int info;
    struct node *left, *right;
};
typedef struct node NODE;

NODE *root = NULL;
NODE *newnode, *temp = NULL, *last = NULL, *itemnode = NULL, *queue[MAX_SIZE];
int front = 0, rear = 0;

void creation(int item) {
    newnode = (NODE *)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->info = item;
    newnode->left = NULL;
    newnode->right = NULL;
}

void insertion() {
    int item;
    printf("Enter the element to be inserted: ");
    scanf("%d", &item);
    creation(item);

    if (root == NULL) {
        root = newnode;
        printf("%d was inserted\n", item);
        return;
    }

    // Level-order insertion (using a queue)
    front = 0;
    rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        temp = queue[front++];
        if (temp->left != NULL) {
            if (rear < MAX_SIZE) {
                queue[rear++] = temp->left;
            } else {
                printf("Queue overflow\n");
                return;
            }
        } else {
            temp->left = newnode;
            printf("%d was inserted\n", item);
            return;
        }
        if (temp->right != NULL) {
            if (rear < MAX_SIZE) {
                queue[rear++] = temp->right;
            } else {
                printf("Queue overflow\n");
                return;
            }
        } else {
            temp->right = newnode;
            printf("%d was inserted\n", item);
            return;
        }
    }
}

void deletion() {
    int item;
    if (root == NULL) {
        printf("Empty Tree\n");
        return;
    }
    printf("Enter the item to delete: ");
    scanf("%d", &item);

    // Tree with only one node
    if (root->left == NULL && root->right == NULL) {
        if (root->info == item) {
            free(root);
            root = NULL;
            printf("%d was deleted\n", item);
        } else {
            printf("%d not present\n", item);
        }
        return;
    }

    // Level-order traversal to find item and deepest node
    temp = NULL;
    last = NULL;
    itemnode = NULL;
    front = 0;
    rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];
        if (temp->info == item) {
            itemnode = temp;
        }
        if (temp->left != NULL) {
            last = temp;
            if (rear < MAX_SIZE) queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            last = temp;
            if (rear < MAX_SIZE) queue[rear++] = temp->right;
        }
    }

    // If item is found
    if (itemnode != NULL) {
        itemnode->info = temp->info; // Replace with the deepest node's info

        // Free the last node and update its parent
        if (last->right == temp) {
            free(last->right);
            last->right = NULL;
        } else {
            free(last->left);
            last->left = NULL;
        }
        printf("%d was deleted\n", item);
    } else {
        printf("%d not found\n", item);
    }
}

void inorder(NODE *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d\t", root->info);
    inorder(root->right);
}

void preorder(NODE *root) {
    if (root == NULL) return;
    printf("%d\t", root->info);
    preorder(root->left);
    preorder(root->right);
}

void postorder(NODE *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->info);
}

int main() {
    int ch;
	clrscr();
    printf("\n1. Insert\n2. Delete\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\n");

    do {
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        printf("\n");

        switch (ch) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    preorder(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL) {
                    printf("Tree is empty\n");
                } else {
                    postorder(root);
                    printf("\n");
                }
                break;
            case 6:
                printf("---EXIT---\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 6);

    getch(); 
    return 0;
}
