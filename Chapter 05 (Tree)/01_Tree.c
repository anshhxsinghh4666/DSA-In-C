/* TREE IMPLEMENTATIONS : 

      A
     / \
    B   C
   / \   \
  D   E   F

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *create() {  // Return type is struct Node because it will return pointer to Node
    int x;
    struct Node *newNode;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter Data (-1 for No Node) : ");
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
// NOTE : Copy of Each variables will be made for each function call (Recursion)

int main() {
    struct Node *root;
    root = NULL;
    root = create();

    return 0;
}