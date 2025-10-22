// CIRCULAR LINKED LIST :

/*
ALGORITHM 

1. Start
2. Declare a structure Node with fields : 
    ~ data (int)
    ~ next (pointer to next Node)
    ~ prev (pointer to previous Node)
3. Declare pointers : head = NULL , temp , newNode
4. Declare Int n
5. Input Number of elements from user in n
6. Loop for i=0 to n-1
    ~ Allocate memory to newNode using malloc
    ~ Check : If memory Allocation failed -> print error and exit
    ~ Input Data in newNode->data
    ~ Set newNode->next = NULL
    ~ if head == NULL
        Set head = temp = newNode
        Set newNode->next = head
    ~ else 
        Set tail->next = newNode
        Set newNode->prev = tail
        Set temp = newNode
        Set temp->next = head

Function display()
1. if head == NULL -> Print "Empty list" and exit
2. Set temp = head
3. Do-while loop 
    ~ print temp->data
    ~ update temp = temp->next
    ~ Repeat while temp!=head

End

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL, *newNode, *temp;

void display() {
    if (head == NULL) {
        printf("Circular Linked List: Empty List\n");
        return;
    }
    temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);

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
            newNode->next = head;
        } else {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;  // For Circular Linked List just add this line in Singly Linked List Code.
        }
    }

    display();

    return 0;
}