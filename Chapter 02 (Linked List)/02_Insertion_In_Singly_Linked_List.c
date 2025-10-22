//  INSERTION IN LINKED LIST

/*
ALGORITHM : 

1. Start 
2. Declare a structure Node with fields : 
    ~ integer data
    ~ next (pointer to next node)
3. Declare Global Variables : 
    ~ pos, count = 0, i = 1 -> Integers 
    ~ head , newNode , temp -> Pointers 
4. Initialize head = NULL 
5. Declare n
6. Input Number of elements in n
7. Loop from i = 0 to n-1 to create n nodes
    ~ Create a newNode using malloc (Dyanmic Memory Allocation)
    ~ Check : If Memory Allocation failed -> print error and exit
    ~ Input Data into newNode->data
    ~ set newNode->next = NULL
    ~ if head == NULL
        -> Set head = temp = newNode
    ~ else
        -> Set temp->next = newNode
        -> Set temp = newNode 
8. set temp = head 
9. While temp!=NULL repeat the following steps :  
    ~ print temp->data
    ~ Update temp = temp->next
10. Menu Loop (repeat until user selects 0 i.e. Exit)
    ~ Display Menu :
        0 -> Find length
        1 -> Insert at beginning
        2 -> Insert at End
        3 -> Insert at Any Location
        4 -> Exit 
    ~ Input Users Choice 
    ~ switch(choice) : 
        Case 0 → Call length()
		Case 1 → Call insertBeg()
		Case 2 → Call insertEnd()
		Case 3 → Call insertAtLoc()
		Case 4 → Exit Program
		Default → Print “Invalid Choice”
11 End

Functions Algorithm 

Function Length()
1. initialize count = 0
2. Set temp = head
3. while(temp!=NULL) repeat the following steps : 
    ~ increment count (count++)
    ~ Move temp = temp->next
4. Print length of Linked List = count

Function insertBeg()
1. Allocate memory to newNode 
2. Input Data into newNode->data
3. Set newNode->next = head;
4. Print "Linked List After Insertion : "
5. Set temp = head 
6. Traverse the list from beginning to end and print each element

Function insertEnd()
1. Allocate Memory to newNode 
2. Input data in newNode->data
3. set newNode = NULL
4. set temp = head
5. Traverse until temp->next = NULL
6. Set temp->next = newNode
7. Print "Linked List After Insertion : "
8. Set temp = head 
9. Traverse the list from beginning to end and print each element

Function insertAtLoc()
1. Call length() to get current Number of Nodes 
2. Input pos 
3. if pos<1 or pos>count+1 -> print "Invalid Position"
4. else if pos == 1 -> call insertbeg()
5. else : 
    ~Allocate memory to newNode 
    ~ Set temp = head and i = 1
    ~ Traverse till i<pos-1 
        Move temp to temp->next
        increment i (i++)
    ~ Input data into newNode->data
    ~ Set newNode->next = temp->next
	~ Set temp->next = newNode
	~ Print “Linked List After Insertion at Position pos”
	~ Traverse list from head and print elements

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int pos, count = 0, i = 1;
struct node *head, *newNode, *temp;

void length() {
    count = 0;    
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Lenght of Linked List : %d\n", count);
}

void insertBeg() {
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    printf("Linked List After Insertion at Beginning : \n");
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertEnd() {
    newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Linked List After Insertion at End : \n");
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void insertAtLoc() {
    length();
    printf("Enter Position : ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
    } else if (pos == 1) {
        insertBeg();
    } else {
        newNode = (struct node *) malloc(sizeof(struct node));
        temp = head;
        i = 1;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        printf("Enter Data : ");
        scanf("%d", &newNode->data);
        newNode->next = temp->next;
        temp->next = newNode;

        printf("Linked List After Insertion at Beginning : \n");
        temp = head;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void insertMiddle() {
    length();
    if (head == NULL) {
        printf("List is empty, inserting at beginning.\n");
        insertBeg();
        return;
    }
    int mid;
    if (count % 2 == 0)
        mid = count / 2;       // Even count
    else
        mid = (count / 2) + 1; // Odd count

    newNode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    temp = head;
    i = 1;
    while (i < mid) {  // Traverse to node just before middle
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Linked List After Insertion at Middle : \n");
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    head = NULL;
    

    for(int i=0; i<n; i++){
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
    printf("Linked List : \n");
    temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");

    int choice;

do {
    printf("\n--- Linked List Menu ---\n");
    printf("0. Find Length of Linked List\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Any Location\n");
    printf("4. Insert at Middle \n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 0:
            length();       // Call length function
            break;
        case 1:
            insertBeg();    // Call insert at beginning
            break;
        case 2:
            insertEnd();    // Call insert at end
            break;
        case 3:
            insertAtLoc();  // Call insert at location
            break;
        case 4 : 
            insertMiddle();
            break;
        case 5:
            printf("Exiting Program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }

} while (choice != 4);

    return 0;
}