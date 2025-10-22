// SEARCH ELEMENT IN SINGLY LINKED LIST

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head, *newNode, *temp;

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

void search() {
    int target, count = 0;
    bool found = false;
    printf("Enter Target : ");
    scanf("%d", &target);
    temp = head;
    while (temp != NULL) {
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
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    head = NULL;

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
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    search();

    return 0;
}