// DELETION IN DOUBLY LINKED LIST :

/*ALGORITHM : 

1. Start
2. Declare a structure Node with fields : 
    ~ data (int)
    ~ next (pointer to next Node)
    ~ prev (pointer to previous Node)
3. Declare pointers : head , tail , newNode , temp and a variable count (int)
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
9. 	Menu-driven loop (repeat until user chooses Exit):
		Print Menu options:
    0 → Find Length
    1 → Insert at Beginning
    2 → Insert at End
    3 → Insert at Any Location
    4 → Insert After Any Position
    5 → Insert at Middle
    6 → Exit
	•	Input user choice in z
	•	switch(z) →
	•	Case 0 → call length()
	•	Case 1 → call insertBeg()
	•	Case 2 → call insertEnd()
	•	Case 3 → call insertAtLoc()
	•	Case 4 → call insertAfterPos()
	•	Case 5 → call insertMiddle()
	•	Case 6 → Print exit message
	•	Default → Print “Invalid choice”
10. Call display()

Function display()
1. Set temp = head 
2. if temp == NULL -> Print "Empty Linked List"
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

Function deleteBeg()
1. if head = NULL -> Print Empty List 
2. Set temp = head 
3. head = head->next
4. head->prev = NULL
5. free memory of temp

Function deleteEnd()
1. if head = NULL -> Print "Empty List"
2. Set temp = tail
3. tail->prev->next = NULL
4. tail = tail->prev
5. free memory of temp

Function deleteAtLoc()
1. if head == NULL -> Print "Empty List"
2. declare pos and initialize i=1
3. Input position in pos
4. Call length
5. if pos<1 or pos>count -> Print "Invaid Position" and exit
6. if pos == 1 -> call deleteBeg()
7. Set temp = head
8. while i<pos Repeat the following steps 
    ~ temp = temp->next
    ~ increment i++
9. Set temp->prev->next = temp->next
10. Set temp->next->prev = temp->prev
11. free memory of temp

End
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head, *tail, *newNode, *temp;
int count;

void display() {
    temp = head;
    while (temp != NULL) {
        printf("%d <--> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void length() {
    count = 0;
    temp = head;
    while (temp != 0) {
        count++;
        temp = temp->next;
    }
    printf("Lenght of Linked List : %d\n", count);
}

void deleteBeg() {
    if (head == NULL) {
        printf("Linked List is Empty\n");
        return;
    }
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("Linked List is Empty\n");
        return;
    } else {
        temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(temp);
    }
}

void deleteAtLoc() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    int pos, i = 1;
    printf("Enter Position : ");
    scanf("%d", &pos);

    length();  // Calculate current length
    if (pos < 1 || pos > count) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    temp = head;
    // The logic here was incorrect. This correctly finds the node *before* the target.
    while (i < pos) {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    head = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory Allocation Failed\n");
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

    printf("\nInitial list created:\n");
    display();
    printf("\n");

    int f;
    printf("--- Deletion Menu ---\n");
    printf("1. Delete From Beginning\n");
    printf("2. Delete from End\n");
    printf("3. Delete from specified Position\n");
    printf("Enter your choice: ");
    scanf("%d", &f);

    switch (f) {
        case 1:
            deleteBeg();
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            deleteAtLoc();
            break;
        default:
            printf("Invalid Input\n");
            break;
    }

    printf("\nList after deletion:\n");
    display();

    return 0;
}