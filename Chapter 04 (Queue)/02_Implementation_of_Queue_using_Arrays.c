// IMPLEMENTATIONS OF QUEUE USING ARRAYS : Using static memory allocation

/*
ALGORITHM : Enqueue Operation (for Linear Queue)
Step 1: Check if rear == N − 1
  • If TRUE → print "Overflow" and stop
Step 2: Else if front == −1 and rear == −1
  • Set front = 0
  • Set rear = 0
  • Insert x at queue[rear]
Step 3: Else
  • Increase rear by 1
  • Insert x at queue[rear]
Step 4: End

ALGORITHM : Dequeue Operation (for Linear Queue)
Step 1: Check if front == −1 and rear == −1
  • If TRUE → print "Underflow" and stop
Step 2: Else if front == rear
  • Set front = −1
  • Set rear = −1
  • (Queue becomes empty)
Step 3: Else
  • Print queue[front]
  • Increase front by 1
Step 4: End
*/

#include <stdio.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == N - 1) {
        printf("OverFlow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("UnderFlow\n");
    } else if (front == rear) {
        front = rear = -1;
    } else {
        printf("Dequeue : %d\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    printf("Display : ");
    if (front == -1 && rear == -1) {
        printf("Empty List\n");
    } else {
        for (i = front; i < rear + 1; i++) {
            printf("%d \t ", queue[i]);
        }
    }
    printf("\n");
}

void peek() {
    if (front == 1 && rear == -1) {
        printf("Empty Queue\n");
    } else {
        printf("Peek : %d\n", queue[front]);
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
