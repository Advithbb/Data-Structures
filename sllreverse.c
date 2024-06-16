#include <stdio.h>
#include<stdlib.h>
 
 struct node {
   int data;
   struct node *link;
 };
 void print_data(struct node *head)
 {
   if(head==NULL){
      printf("Linked List is Empty");
      return;
   }
   struct node *ptr=head;
   while (ptr!=NULL){
      printf("%d ",ptr->data);
      ptr=ptr->link;
   }
 }


    void add_end(struct  node *head,int data)
 {
   struct node *ptr,*temp;
   ptr=head;
   temp=malloc(sizeof(struct node));
   temp->data=data;
   temp->link=NULL;
   while (ptr->link!=NULL)
   
   {
      ptr=ptr->link;
   }
   ptr->link=temp;
   
 }

 struct node* reverse( struct node *head)
 {
    struct node *prev=NULL;
    struct node *next=NULL;

    while(head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
 }


  int main()
 {

   

   struct node *head=malloc(sizeof(struct node));
   head->data=10;
   head->link=NULL;

   add_end(head,20);
   add_end(head,30);
   printf("Before reverse: ");
   print_data(head);

   

   printf("\nReversed Linked List: ");
   head=reverse(head);

   print_data(head);

    return 0;
 }