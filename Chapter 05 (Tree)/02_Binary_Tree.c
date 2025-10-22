// BINARY TREE : Each Node should contain atmost 2 children

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *create() {
    int x;
    struct Node *newNode;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter Data (-1 for NO Node) : ");
    scanf("%d", &x);
    if (x == -1) {
        return 0;
    }
    newNode->data = x;
    printf("Enter Left child of %d : ", x);
    newNode->left = create();
    printf("Enter Right child of %d : ", x);
    newNode->right = create();

    return newNode;
}

int main() {
    struct Node *root;
    root = NULL;
    root = create();
}