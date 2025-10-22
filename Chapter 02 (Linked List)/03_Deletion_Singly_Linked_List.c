// DELETION FROM LINKED LIST
//  Time Complexity : O(n)

/* 
ALGORITHM : 

1. Start 
2. Declare structure with Node fields 
    ~ Integer Data 
    ~ next (pointer to next node)
3. Declare Global Variables 
    ~ len -> Variables  
    ~ head = NULL , newNode , temp -> Pointers 
4. Declare n
5. Input Number of elements in n
6. Loop from i=0 to n-1 to create n nodes 
    ~ Allocate memory to newNode 
    ~ Check : if Memory Allocation Failed -> print error and exit 
    ~ Input data in newNode->data
    ~ Set newNode->next = NULL
    ~ if head == NULL : 
        Set head = temp = newNode 
    ~ else : 
        Set temp->next = newNode 
        Move temp = newNode
7. Display the Initial List Created by calling display() function
8. Declare variable f
9. Show Deletion Menu : 
    1 -> Delete from beg
    2 -> Delete from End
    3 -> Delete from specific location 
10. User Input choice in f
11. Switch(f) : 
    Case 1 → Call deleteBeg()
	Case 2 → Call deleteEnd()
	Case 3 → Call deleteAtLoc()
	Default → Print “Invalid Input”
12.	Display linked list after deletion using display()
13.	End

*/

#include <stdio.h>
#include <stdlib.h>  // Required for malloc and free

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL, *newNode, *temp;
int len;

void display() {
    temp = head;
    if (temp == NULL) {
        printf("Linked List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void length() {
    temp = head;
    len = 0;
    // This loop was incorrect. It should traverse the whole list.
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
}

void deleteBeg() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    temp = head;
    head = head->next;  // Points Head to the 2nd Node
    free(temp);  // Use free() in C
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }
    // If there is only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    struct Node *preNode;
    while (temp->next != NULL) {  // Traverse till the seocnd last node
        preNode = temp;
        temp = temp->next;
    }
    preNode->next = NULL;
    free(temp);  // Use free() in C
}

void deleteAtLoc() {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    int pos, i = 1;
    printf("Enter Location: ");
    scanf("%d", &pos);

    length();  // Calculate current length
    if (pos < 1 || pos > len) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

int main() {
    int n;
    printf("Enter No. of Elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct Node *) malloc(sizeof(struct Node));  // Use C's malloc
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        printf("Enter Data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
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

// struct Node {
//     int data;
//     struct Node *next;
// };

// struct Node *head = NULL, *newNode, *temp;
// int len;

// void display() {
//     temp = head;
//     printf("Linked List : ");
//     while (temp != 0) {
//         printf("%d", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// void length() {
//     temp = head;
//     len = 0;
//     while (temp->next == NULL) {
//         len++;
//     }
// }

// void deleteBeg() {
//     temp = head;
//     head = head->next;  // Points Head to the 2nd Node
//     free(temp);  // Free the memory allocated to the node we deleted.
//     display();
// }

// void deleteEnd() {
//     temp = head;
//     struct Node *preNode;
//     while (temp->next != NULL) {
//         preNode = temp;
//         temp = temp->next;
//     }
//     if (temp == head) {
//         head = NULL;
//     } else {
//         preNode->next = NULL;
//     }
//     free(temp);
//     display();
// }

// void deleteAtLoc() {
//     temp = head;
//     struct Node *nextNode;
//     int pos, i = 1;
//     printf("Enter Location : ");
//     scanf("%d", &pos);
//     length();
//     if (pos > len) {
//         printf("Invlaid Input");
//         return;
//     }
//     while (i < pos - 1) {
//         temp = temp->next;
//         i++;
//         nextNode = temp->next;
//         temp = nextNode->next;
//         free(nextNode);
//     }
//     display();
// }

// int main() {
//     int n;
//     printf("Enter No. of Elements : ");
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         newNode = (struct Node *) malloc(sizeof(struct Node));
//         if (newNode == NULL) {
//             printf("Memory Allocation Failed \n");
//             return 0;
//         }
//         printf("Enter Data : ");
//         scanf("%d", &newNode->data);
//         newNode->next = NULL;

//         if (head == NULL) {
//             head = temp = newNode;
//         } else {
//             temp->next = newNode;
//             temp = newNode;
//         }
//     }

//     int f;
//     printf("1. Delete From Beginning \n2. Delete from End\n 3. Delete from specified Position");
//     printf("Enter Number : ");
//     scanf("%d", &f);

//     switch (f) {
//         case 1:
//             deleteBeg();
//             break;
//         case 2:
//             deleteEnd();
//             break;
//         case 3:
//             deleteAtLoc();
//             break;
//         default:
//             printf("Invalid Input\n");
//             break;
//     }

//     return 0;
// }