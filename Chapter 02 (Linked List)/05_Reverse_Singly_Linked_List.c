// REVERSE A LINKED LIST : Reverse the Links , don't swap start and end values .


/* 
ALGORITHM : 

1. Start
2. Declare a structure Node with fields : 
    ~ data (int)
    ~ next (pointer to next Node)
3. Declare pointers : head , temp , newNode
4. Declare Int n
5. Input Number of elements from user in n
6. Initialize head = NULL
7. Loop for i=0 to n-1
    ~ Allocate memory to newNode using malloc
    ~ Check : If memory Allocation failed -> print error and exit
    ~ Input Data in newNode->data
    ~ Set newNode->next = NULL
    ~ if head == NULL
        Set head = temp = newNode
    ~ else 
        Set temp->next = newNode
        Set temp = newNode
8. Call reverse()
9. call display()
10. End

Function display()
1. Set temp = head 
2. if temp == NULL -> Empty List
3. else 
    ~ Repeat steps till temp != NULL
        print temp->data
        Update temp = temp->next
4. Print "NULL"

Function reverse()
1. Declare pointer preNode = NULL, nextNode , currentNode
2. Set currentNode = nextNode = head;
3. Repeat steps till currentNode!=0
    ~nextNode = currentNode->next
    currentNode->next = preNode
    preNode = currentNode
    currentNode = nextNode
4. Update head = preNode

*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head, *newNode, *temp;

void display() {
    temp = head;
    printf("Linked List : \n");
    if (temp == NULL) {
        printf("Linked List is Empty\n");
    }
    else{
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    printf("NULL\n");
    }
}

void reverse() {
    struct Node *preNode = NULL, *nextNode, *currentNode;
    currentNode = nextNode = head;

    while (currentNode != 0) {
        nextNode = currentNode->next;  // store next
        currentNode->next = preNode;  // reverse link
        preNode = currentNode;  // move preNode
        currentNode = nextNode;  // move currentNode
    }

    head = preNode;
}

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    head = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter Data : ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Reversed Linked list : \n");
    reverse();
    display();

    return 0;
}
