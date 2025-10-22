// BUBBLE SORT SINGLY LINKED LIST : 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newNode, *temp;

void display() {
    temp = head;
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

// Bubble sort the linked list by swapping data
void BubbleSort() {
    if (head == NULL)
        return;

    struct node *i;
    int tempData;
    int swapped;

    do {
        swapped = 0;
        i = head;
        while (i->next != NULL) {
            if (i->data > i->next->data) {
                // Swap the data
                tempData = i->data;
                i->data = i->next->data;
                i->next->data = tempData;
                swapped = 1;
            }
            i = i->next;
        }
    } while (swapped);
}

int main() {
    int n;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct node *) malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter Data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nOriginal List:\n");
    display();

    BubbleSort();

    printf("\nSorted List (Bubble Sort):\n");
    display();

    return 0;
}