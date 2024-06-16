#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *link;
};

void print_data(struct node *head)
{
    if(head==NULL)
    {
    printf("List is empty");
    return;
}
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

}

void add_end(struct node *head,int data)
{
    struct node *ptr,*temp;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr=head;

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

struct node* add_first(struct node *head,int data)

{
    struct node *ptr=head;
    ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=head;

    head=ptr;
    return head;
}

void del_pos(struct node* head,int position)
{
    struct node *current= head;
    struct node *previous= head;

    if(head==NULL)
    {
        printf("The list is empty");
    }
    else if(position==1)
    {
        head=current->link;
        free(current);
        current=NULL;
    }
    else{
        while(position!=1)
        {
            previous=current;
            current=current->link;
            position--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=100;
    head->link=NULL;

    head=add_first(head,5);
    add_end(head,10);
    add_end(head,20);
    int position=3;
    del_pos(head,position);
    print_data(head);
}
