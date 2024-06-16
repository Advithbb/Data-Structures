#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void printMiddle(const Node* head){
    if(head == NULL){
        printf("the list is empty");
        return;
    }
    const Node* slow = head;
    const Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("the middle element is: %d \n ",slow->data);
}

int main()
{
    Node* head = malloc(sizeof(Node));
    Node* second = malloc(sizeof(Node));
    Node* third = malloc(sizeof(Node));
    
    head->data=15;
    second->data=25;
    third->data=30;
    
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    printMiddle(head);
    
    
    free(head);
    free(second);
    free(third);
}