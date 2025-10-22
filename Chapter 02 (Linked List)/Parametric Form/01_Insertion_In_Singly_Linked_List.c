#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create linked list (parametric)
void create(int n, int arr[]) {
    struct node *newNode, *temp;
    head = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct node *) malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// Function to display list
void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Length of linked list
int length() {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert at beginning (parametric)
void insertBeg(int value) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end (parametric)
void insertEnd(int value) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at given location (parametric)
void insertAtLoc(int pos, int value) {
    int len = length();
    if (pos < 1 || pos > len + 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        insertBeg(value);
        return;
    }

    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = value;

    struct node *temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert at middle (parametric)
void insertMiddle(int value) {
    int len = length();
    int mid;

    if (len % 2 == 0)
        mid = len / 2;
    else
        mid = (len / 2) + 1;

    insertAtLoc(mid + 1, value);  // insert after middle
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    create(n, arr);

    printf("Initial Linked List:\n");
    display();

    int choice, val, pos;
    do {
        printf("\n--- Menu ---\n");
        printf("0. Find Length\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Location\n");
        printf("4. Insert at Middle\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Length: %d\n", length());
                break;
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeg(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtLoc(pos, val);
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                insertMiddle(val);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}