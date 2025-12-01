// IMPLEMENTATION OF QUEUE USING LINKED LIST : Using Dyanamic Memory Allocation

/*
ALGORITHM : Enqueue Operation (Linked List Queue)
Step 1: Create a new node using dynamic memory allocation
  • newNode = malloc(sizeof(struct Node))
  • Set newNode→data = x
  • Set newNode→next = NULL
Step 2: Check if head == NULL and tail == NULL
  • If TRUE:
    - Set head = newNode
    - Set tail = newNode
Step 3: Else
  • Set tail→next = newNode
  • Set tail = newNode
Step 4: End

ALGORITHM : Dequeue Operation (Linked List Queue)
Step 1: Check if head == NULL and tail == NULL
  • If TRUE → print "Queue is Empty" and stop
Step 2: Else
  • Set temp = head
  • Print temp→data
  • Move head to head→next
  • Free temp
Step 3: End
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *newNode;

void enqueue(int x) {
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL && tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void display() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
    } else {
        struct Node *temp;
        temp = head;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void dequeue() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
    } else {
        struct Node *temp;
        temp = head;
        printf("Dequeue : %d\n", temp->data);
        head = head->next;
        free(temp);
    }
}

void peek() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty]\n");
    } else {
        printf("%d\n", head->data);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    peek();
    display();
    dequeue();
    peek();
    dequeue();
    peek();
    dequeue();
    display();

    return 0;
}