// REVERSSE DOUBLY LINKED LIST :

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

/*
NOTE : Alternate value to declare struct node and head , tail etc.. : 
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}*head, *tail;
*/

struct Node *head, *tail, *newNode, *temp;

void display() {
    temp = head;
    while (temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void reverse() {  // Exhange the value of next pointer and prev pointer in a Node.
    struct Node *currentNode, *nextNode;

    if (head == NULL) {
        printf("Empty List \n");
    } else {
        currentNode = head;
        while (currentNode != NULL) {
            nextNode = currentNode->next;
            currentNode->next = currentNode->prev;
            currentNode->prev = nextNode;
            currentNode = nextNode;
        }
        currentNode = head;
        head = tail;
        tail = currentNode;
    }
}

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory Allocation Failed\n");
            return 1;
        }
        printf("Enter Data : ");
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
    reverse();
    display();

    return 0;
}