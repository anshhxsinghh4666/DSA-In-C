#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Create linked list from array (parametric)
void create(int n, int arr[]) {
    struct Node *newNode, *temp;
    head = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// Display linked list
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Find length
int length() {
    int len = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Delete from beginning
void deleteBeg() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    if (head->next == NULL) { // only one node
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Delete from specific location (parametric)
void deleteAtLoc(int pos) {
    int len = length();
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    if (pos < 1 || pos > len) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    create(n, arr);

    printf("\nInitial list:\n");
    display();

    int choice, pos;
    printf("\n--- Deletion Menu ---\n");
    printf("1. Delete from Beginning\n");
    printf("2. Delete from End\n");
    printf("3. Delete from Specific Position\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deleteBeg();
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtLoc(pos);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
    }

    printf("\nList after deletion:\n");
    display();

    return 0;
}