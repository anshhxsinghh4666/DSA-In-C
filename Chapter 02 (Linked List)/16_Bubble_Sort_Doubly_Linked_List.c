// BUBBLE SORT OF DOUBLY LINKED LIST :

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Declare global pointers
struct Node *head = NULL, *tail = NULL, *newNode;

// Function to display the list
void display() {
    struct Node *temp = head;
    printf("Doubly Linked List: ");
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Bubble sort by swapping data
void BubbleSort() {
    if (head == NULL)
        return;

    int swapped;
    struct Node *ptr;
    struct Node *last = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                // Swap the data
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;  // Reduce the range for next pass
    } while (swapped);
}

int main() {
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    // Create the doubly linked list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter Data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("\nOriginal List:\n");
    display();

    BubbleSort();

    printf("\nSorted List (Bubble Sort):\n");
    display();

    return 0;
}