// INSERTION IN CIRCULAR LINKED LIST :

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int pos, count = 0, i = 1;
struct node *head, *newNode, *temp;

void length() {
    count = 0;
    if (head == NULL) {  // ✅ FIXED: handle empty list safely
        printf("List is Empty \n");
        return;
    }

    temp = head;
    do {  // ✅ FIXED: correct traversal in circular list
        count++;
        temp = temp->next;
    } while (temp != head);

    printf("Length of Linked List : %d\n", count);
}

void display() {
    printf("Circular Linked List : \n");
    if (head == NULL) {  // ✅ FIXED: handle empty list safely
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

void insertBeg() {
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newNode->data);

    if (head == NULL) {  // ✅ FIXED: handle empty list
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    display();
}

void insertEnd() {
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newNode->data);

    if (head == NULL) {  // ✅ FIXED: handle empty list
        head = newNode;
        newNode->next = head;
    } else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    display();
}

void insertAtLoc() {
    length();
    if (head == NULL)
        return;  // ✅ FIXED: avoid insert when list is empty

    printf("Enter Position : ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
    } else if (pos == 1) {
        insertBeg();
    } else {
        newNode = (struct node *) malloc(sizeof(struct node));
        temp = head;
        i = 1;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        printf("Enter Data : ");
        scanf("%d", &newNode->data);
        newNode->next = temp->next;
        temp->next = newNode;

        display();
    }
}

// ✅ Insert at Middle
void insertMiddle() {
    length();
    if (head == NULL) {
        printf("List is empty, inserting at beginning.\n");
        insertBeg();
        return;
    }
    int mid;
    if (count % 2 == 0)
        mid = count / 2;
    else
        mid = (count / 2) + 1;

    newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    temp = head;
    i = 1;
    while (i < mid) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    display();
}

int main() {
    head = NULL;
    int z;
    printf("Enter Number of Elements : ");
    scanf("%d", &z);

    for (int i = 0; i < z; i++) {
        newNode = (struct node *) malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter Data : ");
        scanf("%d", &newNode->data);

        if (head == NULL) {  // ✅ FIXED: first node points to itself
            head = temp = newNode;
            newNode->next = head;
        } else {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;
        }
    }
    display();

    int choice;
    do {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("0. Find Length\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Location\n");
        printf("4. Insert at Middle\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 0: length(); break;
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: insertAtLoc(); break;
            case 4: insertMiddle(); break;
            case 5: printf("Exiting Program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}