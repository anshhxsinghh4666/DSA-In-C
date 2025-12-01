/* IMPLEMENTATIONS OF CIRCULAR QUEUE USING ARRAYS : Using static memory allocation

A Circular Queue is a queue in which the last position connects back to the first position, forming a circle.
This allows the queue to reuse empty spaces created by deletions, which is not possible in a linear queue.
It still follows FIFO (First In First Out).

+-----+-----+-----+-----+-----+
| 10  | 20  | 30  | 40  | 50  |
+-----+-----+-----+-----+-----+
   ^                       |
   |_______________________|
         Circular Link

*/

#include <stdio.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if ((rear + 1) % N == front) {  // Rear == Front
        printf("OverFlow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % N;  // Rear comes back to start of queue and enqueue at empty space if avaialble
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
        front = (front + 1) % N;  // When front reaches the end it will circle back to start of the array
    }
}

void display() {
    int i = front;
    printf("Display : ");
    if (front == -1 && rear == -1) {
        printf("Empty List\n");
    } else {
        while (i != rear) {
            printf("%d", queue[i]);
            i = (i + 1) % N;
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
