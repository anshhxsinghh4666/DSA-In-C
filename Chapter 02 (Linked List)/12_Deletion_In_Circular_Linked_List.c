// DELETION IN CIRCULAR LINKED LIST :

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head, *temp, *newNode;
int count;

void display() {
    printf("Circular Linked List : \n");
    if (head == NULL) {
        printf("Empty List \n");
        return;
    }
    temp = head;
    do {  // ✅ FIXED: do-while loop for circular traversal
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

void length() {
    count = 0;
    temp = head;
    if (head == NULL) {
        printf("List is Empty \n");
        return;
    }
    do {
        count++;
    } while (temp != head);
    // printf("Length of Linked List : %d", count);
}

void deleteBeg() {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    struct Node *del = head;
    head = head->next;
    last->next = head;
    free(del);
}

void deleteEnd() {
    if (head == NULL) {
        printf("Empty List \n");
        return;
    }
    // If there is only one Node
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    struct Node *preNode;
    do {
        preNode = temp;
        temp = temp->next;
    } while (temp->next != head);
    preNode->next = head;
    free(temp);
}

void deleteLoc() {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    int pos, i = 1;
    printf("Enter Location : ");
    scanf("%d", &pos);

    length();  // Calculate current length
    if (pos < 1 || pos > count) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    temp = head;
    // The logic here was incorrect. This correctly finds the node *before* the target.
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
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
            return 0;
        }
        printf("Enter Data : ");
        scanf("%d", &newNode->data);

        if (head == NULL) {
            head = temp = newNode;
            newNode->next = head;
        } else {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }

    int choice;
    do {
        printf("\n--- Deletion Menu ---\n");
        printf("1. Delete From Beginning\n");
        printf("2. Delete From End\n");
        printf("3. Delete From Specific Location\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteBeg();
                break;
            case 2:
                deleteEnd();
                break;
            case 3:
                deleteLoc();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 0);
}