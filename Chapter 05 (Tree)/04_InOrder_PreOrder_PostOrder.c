/*
INORDER PREORDER AND POSTORDER TRAVERSAL

     (4)
    /   \
  (2)   (5)
 / \
(1) (3)

1. PreOrder Traversal (Root, Left, Right)

In PreOrder, you visit the Root node before visiting its children.

Visit the Root.

Recursively visit the Left subtree.

Recursively visit the Right subtree.

Mnemonic: "Root first"

Traversal on our tree:

Visit 4

Go Left -> Visit 2

Go Left -> Visit 1

Go Right -> Visit 3

Go Right -> Visit 5

Result: 4, 2, 1, 3, 5


2. InOrder Traversal (Left, Root, Right)

In InOrder, you visit the Root node in between visiting its left and right children.

Recursively visit the Left subtree.

Visit the Root.

Recursively visit the Right subtree.

Mnemonic: "Root in the middle"

Note: For a Binary Search Tree (like this one), an InOrder traversal always visits the nodes in ascending sorted order.

Traversal on our tree:

Go Left from 4 -> Go Left from 2 -> Visit 1

Visit 2 (root of 1 and 3)

Go Right from 2 -> Visit 3

Visit 4 (root of 2 and 5)

Go Right from 4 -> Visit 5

Result: 1, 2, 3, 4, 5


3. PostOrder Traversal (Left, Right, Root)

In PostOrder, you visit the Root node after visiting its children.

Recursively visit the Left subtree.

Recursively visit the Right subtree.

Visit the Root.

Mnemonic: "Root last"

Note: This is often used when deleting a tree, as you must delete the children before you can delete their parent.

Traversal on our tree:

Go Left from 4 -> Go Left from 2 -> Visit 1

Go Right from 2 -> Visit 3

Visit 2 (root of 1 and 3)

Go Right from 4 -> Visit 5

Visit 4 (root of 2 and 5)

Result: 1, 3, 2, 5, 4

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

void preOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct Node *root;
    root = NULL;
    root = create();

    printf("InOrder : ");
    inOrder(root);
    printf("\n\n");

    printf("PreOrder : ");
    preOrder(root);
    printf("\n\n");

    printf("PostOrder : ");
    postOrder(root);
    printf("\n\n");

    return 0;
}
