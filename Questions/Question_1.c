// Design an algorithm or C program to create a linked list using the following node data:
// 5 → 10 → 15 → 20 → 25 and then insert a new node with the value 30 at the third
// position of the list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head, *temp, *newNode;
int count = 0;

void create(int n, int arr[]) {
    head = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory Allocation failed \n");
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

void display() {
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void length() {
    count = 0;
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
}

void insertAtLoc(int pos, int value) {
    length();
    if (pos > count + 1 || pos < 1) {
        printf("Invalid Position\n");
        return;
    }

    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    temp = head;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    } else {
        int i = 1;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    create(n, arr);
    display();
    insertAtLoc(3, 30);
    display();

    return 0;
}