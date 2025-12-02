// INSERTION IN DOUBLY LINKED LIST :

// NOTE : Edit code so that it can run for empty list .....

/*
ALGORITHM : 

1. Start
2. Declare a structure Node with fields : 
    ~ data (int)
    ~ next (pointer to next Node)
    ~ prev (pointer to previous Node)
3. Declare Global Variables : head , tail , newNode , *temp (Pointers)
                                count , pos (int) 
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
9. Menu driven Loop (repeat till user chooses Exit)
    ~ Print Menu options : 
    0 -> Find Length 
    1 -> Insert at beginning
    2 -> Insert at end 
    3 -> Insert at any location 
    4 -> Insert after a position
    5 -> Insert at middle 
    6 -> Exit

    ~ Input user choice in z 
    ~ switch(z) : 
        Case 0 → call length()
		Case 1 → call insertBeg()
		Case 2 → call insertEnd()
		Case 3 → call insertAtLoc()
		Case 4 → call insertAfterPos()
        Case 5 → call insertMiddle()
		Case 6 → Print exit message
		Default → Print “Invalid choice”
10. End

Function display()
1. Set tail = head 
2. if tail == NULL -> Print "Empty Linked List"
3. While tail!=NULL repeat the following steps
    ~print tail->data
    Update tail = tail->next
4. print "NULL"

Function length()
1. if head = NULL -> Print "Empty List"
2. Initialize count = 0
3. temp = head 
4. while temp!=NULL Repeat the following steps 
    ~ increment count (count++)
    ~ Update temp = temp->next
5. Print Length

Function insertBeg()
1. Allocate Memory to newNode
2. Check : if newNode==NULL -> print error and exit
3. Input data in newNode->data
4. Set newNode->next = NULL and newNode->prev = NULL
5. if head == NULL  
    ~ Set head = tail = newNode
6. else 
    ~ newNode->next = head
    ~ head->prev = newNode
    ~ head = newNode
7. Call display()

Function insertEnd()
1. Allocate Memory to newNode
2. Check : if newNode==NULL -> print error and exit
3. Input data in newNode->data
4. Set newNode->next = NULL and newNode->prev = NULL
5. if head == NULL  
    ~ Set head = tail = newNode
6. else 
    ~ tail->next = newNode
    ~ newNode->prev = tail
    ~ tail = newNode
7. Call display()

Function insertAtLoc()
1. Call length()
2. Input position in pos
3. if pos<1 or pos>count+1 -> Print "Invalid Position"
4. if pos == 1 -> call insertBeg()
5. if head==NULL -> Print "Empty List"
6. Allocate Memory to newNode
7. check : if newNode==NULL -> print error and exit
8. Input data in newNode->data
9. Set temp = head
10 Initialize i = 1
11 while (i<pos-1 && temp != NULL) Repeat the following steps 
    ~ temp = temp->next
    ~ increment i++
12. Update Pointers : 
    ~ newNode->next = temp->next
    ~ newNode->prev = temp
    ~ if(temp->next!=NULL)
        temp->next->prev = newNode
    ~ else 
        tail = newNode
        temp->next = newNode
11. Call display()

Function insertAfterPos()
1. Call length()
2. Input position in pos 
3. if pos<1 or pos>count+1 -> Print "Invalid Position"
4. else 
    ~ Allocate Memory to newNode 
    ~ check 
    ~ Input data in newNode->data 
    ~ Set temp = head 
    ~ initialize i = 1 
    ~ while i<pos Repeat the following steps
        temp = temp->next
        Increment i++
    ~ Update Pointers 
        newNode->prev = temp
        newNode->next = temp->next
        temp->next = newNode
        newNode->next->prev = newNode
    ~ Call display() 

Function insertMiddle()
1. Call length
2. if head == NULL -> Print "Empty List" , Call insertBeg()
3. Declare int mid 
4. Compute Middle Position 
    ~ if even -> mid = count/2
    ~ if odd -> mid = (count/2) + 1
5. Allocate Memory to newNode 
6. Input data in newNode->data
7. Set temp = head 
8. Initialize i = 1
9. while i < mid Repeat the following steps
    ~ temp = temp->next
    ~ i++
10. Update pointers : 
    ~ newNode->next = temp->next
    ~ newNode->prev = temp
    ~ if temp->next != NULL
        temp->next->prev = newNode
    ~ else  
        tail = newNode
        temp->next = newNode
        

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

int count, pos;
struct Node *head, *tail, *newNode, *temp;

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

void length() {
    if (head == NULL) {
        printf("Empty List \n");
    }
    count = 0;
    temp = head;
    while (temp != 0) {
        count++;
        temp = temp->next;
    }
    printf("Lenght of Linked List : %d\n", count);
}

void insertBeg() {
    newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        return;
    }
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {  // Empty list
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Linked List After Insertion at Beginning : ");
    display();
}

void insertEnd() {
    newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed \n");
        return;
    }
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {  // Empty list
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Linked List After Insertion at End : ");
    display();
}

void insertAtLoc() {
    length();
    printf("Enter Position : ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {  // First position
        insertBeg();
        return;
    }
    if (head == NULL) {  // List empty but pos != 1
        printf("Empty list. Cannot insert at position %d\n", pos);
        return;
    }

    newNode = (struct Node *) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed \n");
        return;
    }
    printf("Enter Data : ");
    scanf("%d", &newNode->data);

    temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid Position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    } else {
        tail = newNode;
    }
    temp->next = newNode;

    display();
}

void insertAfterPos() {
    // NOTE : If user enter pos=2 it doesn't mean insertion at 2 , it means insertion after 2 pos
    // Example : 1 2 3 4 5 , now to insert 11 at pos 2 then LL : 1 2 11 3 4 5
    length();
    printf("Enter Position : ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1) {
        printf("Invalid Position\n");
    } else {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory Allocation Failed \n");
            return;
        }

        printf("Enter Data : ");
        scanf("%d", &newNode->data);
        temp = head;
        int i = 1;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
        display();
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
        mid = count / 2;  // For even count, insert after first half
    else
        mid = (count / 2) + 1;  // For odd count, insert after exact middle

    newNode = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter Data : ");
    scanf("%d", &newNode->data);

    temp = head;
    int i = 1;
    while (i < mid) {
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;  // If inserted at end, update tail
    temp->next = newNode;
    printf("Linked List After Insertion at Middle : ");
    display();
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
            head = tail = newNode;  // Check in youtube video that head = tail = newNode is valid or not ..?
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    int z;
    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("0. Find Length of Linked List\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Location\n");
        printf("4. Insert After Any Location\n");
        printf("5. Insert at Middle\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &z);

        switch (z) {
            case 0:
                length();
                break;
            case 1:
                insertBeg();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertAtLoc();
                break;
            case 4:
                insertAfterPos();
                break;
            case 5:
                insertMiddle();
                break;
            case 6:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (z != 6);

    return 0;
}