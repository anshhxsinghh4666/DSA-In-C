// SEARCH ELEMENT IN DOUBLY LINKED LIST : 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Ndoe *next;
};

struct Node *head, *newNode, *temp;

int main(){
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);
    head = NULL;

    for(int i=0; i<n; i++){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if(newNode == NULL){
            printf("Memory Allocation Failed \n");
            return 1;
        }
        printf("Enter Data : ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL){
            head = temp = newNode;
        }
        else{
            newNode->prev = head;
        }
    }

    // Reverfiy doubly ll code from video and clear confusion between head , tail and temp pointer 
}