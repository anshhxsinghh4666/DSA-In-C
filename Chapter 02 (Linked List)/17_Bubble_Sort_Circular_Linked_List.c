// BUBBLE SORT OF CIRCULAR LINKED LIST : 


#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Global pointers
struct Node *head = NULL, *newNode, *temp;

// Display the circular linked list
void display() {
    if (head == NULL) {
        printf("Circular Linked List: Empty List\n");
        return;
    }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Bubble sort by swapping data
void BubbleSort() {
    if (head == NULL || head->next == head)
        return;  // Empty or single node

    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr && ptr1->next != head) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int tempData = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tempData;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;  // Last sorted node
    } while (swapped);
}

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    // Create the circular linked list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory Allocation Failed \n");
            return 1;
        }
        printf("Enter Data : ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
            newNode->next = head; // Circular linking
        } else {
            temp->next = newNode;
            temp = newNode;
            temp->next = head; // Maintain circular link
        }
    }

    printf("\nOriginal List:\n");
    display();

    BubbleSort();

    printf("\nSorted List (Bubble Sort):\n");
    display();

    return 0;
}