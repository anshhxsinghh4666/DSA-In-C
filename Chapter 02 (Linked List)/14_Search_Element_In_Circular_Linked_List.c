// SEARCH ELEMENT IN CIRCULAR LINKED LIST :

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head, *temp, *newNode;

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
void search() {
    temp = head;
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    int target, count = 0;
    bool found = false;
    printf("Enter Target : ");
    scanf("%d", &target);
    while (temp->next != head) {
        if (target == temp->data) {
            printf("Element Found At Index %d", count);
            found = true;
        }
        temp = temp->next;
        count++;
    }
    if (found == false) {
        printf("Element Not Found\n");
    }
}

int main() {
    int n;
    printf("Enter Numebr of Elements : ");
    scanf("%d", &n);
    head = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory Allocation Failed \n");
        }
        printf("Enter Data : ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }

    display();
    search();
}