// DOUBLY LINKED LIST :

/*
ALGORITHM : 

1. Start
2. Declare a structure Node with fields : 
    ~ data (int)
    ~ next (pointer to next Node)
    ~ prev (pointer to previous Node)
3. Declare pointers : head , tail , newNode
4. Declare Int n
5. Input Number of elements from user in n
7. Initialize head = NULL
8. Loop for i=0 to n-1
    ~ Allocate memory to newNode using malloc
    ~ Check : If memory Allocation failed -> print error and exit
    ~ Input Data in newNode->data
    ~ Set newNode->next = NULL
    ~ Set newNode->prev = NULL
    ~ if head == NULL
        Set head = tail = newNode
    ~ else 
        Set tail->next = newNode
        Set newNode->prev = tail
        tail = newNode
9. Call display()
10. End

Function display()
1. Set tail = head 
2. if tail == NULL -> Print "Empty Linked List"
3. While tail!=NULL repeat the following steps
    ~print tail->data
    Update tail = tail->next
4. print "NULL"

End
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head, *tail, *newNode;

void display() {
    tail = head;
    printf("Linked List : \n");
    if (tail == NULL) {
        printf("Linked List is Empty\n");
    }
    while (tail != NULL) {
        printf("%d <--> ", tail->data);
        tail = tail->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    head = NULL;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
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

    display();

    return 0;
}