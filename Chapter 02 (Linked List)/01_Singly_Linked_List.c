// SINGLY LINKED LIST :

/*

ALGORITHM : 

1. Start 
2. Declare a structure Node with fields : 
    ~ data (int)
    ~ next (pointer to next Node)
3. Decalre pointers : head, newNode, temp (Global)
4. Declare int n
5. Input Number of elements from user into n
6. Initialize head = NULL
7. Loop from i=0 to i = n-1. Repeat the Following steps : 
    ~ Create a new Node using malloc (Dynamic Memory Allocation)
    ~ Check : If Memory Allocation Failed -> print error and exit 
    ~ Input data into newNode->data 
    ~ Set newNode->next = NULL
    ~ if head == NULL
        -> Set head = newNode = temp
    ~ else 
        -> Set temp->next = newNode
        -> Set temp = newNode
8. Set temp = head
9. While temp!=NULL repeat following steps 
    ~ print temp->data
    ~ Update temp = temp->next
10. print newline
11. End
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *newNode, *temp;

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    head = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct node *) malloc(sizeof(struct node));
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

    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}