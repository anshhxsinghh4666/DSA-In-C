/* IMPLEMENTATION OF QUEUE USING LINKED LIST : Using Dyanamic Memory Allocation


 front                                rear
   |                                   |
   v                                   v
+------+    +------+    +------+    +------+
| 10   | -> | 20   | -> | 30   | -> | 40   |
+------+    +------+    +------+    +------+
      ^____________________________________|
                 circular link

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;
struct Node *newNode;

void enqueue(int x) {
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
    } else {
        struct Node *temp;
        temp = front;
        while (temp->next != front) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void dequeue() {
    struct Node *temp;
    temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
    } else if (front == rear) {  // Last element is deleted
        front = rear = NULL;
        free(temp);
    } else {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek() {
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty]\n");
    } else {
        printf("%d\n", front->data);
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