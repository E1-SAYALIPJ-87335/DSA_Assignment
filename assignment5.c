// DLLL MID FIND
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* head=NULL;
node* create_node()
{
    node* ptr=(node*)malloc(sizeof(node));
    ptr->data=0;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
}
void add_first(int data)
{
    node* ptr=create_node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        ptr->next=head;
        // ptr->prev=head->prev;
        // head->prev->next=ptr;
        head->prev=ptr;
        head=ptr;   
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty!!!1");
    }
    else
    {
    node* trav=head;
    while(trav!=NULL)
    {
        printf("->%d",trav->data);
        trav=trav->next;
    }
    }
}
node* find_mid()
{
    node* slow=head;
    node* fast=head;
    
    do
    {
        slow=slow->next;
        fast=fast->next->next;

        if(fast==head)
        break;
    }
    while(fast->next!=head);
    return slow;
    
}
int main()
{
    add_first(20);
    add_first(80);
    add_first(40);
    add_first(60);
    add_first(10);
    display();
    node *res=find_mid();
    printf("%d",res->data);

    return 0;
}