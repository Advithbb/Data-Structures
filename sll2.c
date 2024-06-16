#include <stdio.h>
#include <stdlib.h>

// Define struct node
struct node {
    int data;
    struct node *link;
};

// Function to print data of linked list
void print_data(struct node *head) {
    if (head == NULL) {
        printf("Linked List is Empty");
        return;
    }
    
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

void add_end(struct node *head,int data)
{
    struct node *ptr, *temp;
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

struct node* del_last(struct node *head)
{
    if(head==NULL)
    
        printf("The list is empty");
    
    else if (head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {

        struct node *temp=head;
        struct node *temp2=head;

        while(temp->link!=NULL)
        {
            temp2=temp;
            temp=temp->link;
        };
        temp2->link=NULL;
        free(temp);
        temp=NULL;        
        
    }
        return head;

    
}

int main() {
    // Initialize head node
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    
   
    

    // Call function to print the linked list
    add_end(head,20);
    add_end(head,30);

   head=del_last(head);

    print_data(head);

    return 0;
}
