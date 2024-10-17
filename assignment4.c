//SLLL_SELECTION_SORT
#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) int temp=a ; a=b; b=temp;
typedef struct node
{
    int data;
    struct node* next;
}node;
node* head=NULL;
node* create_node()
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=0;
    ptr->next=NULL;
    return ptr;
}
void add_last(int data)
{
    node* ptr=create_node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
    }
    else 
    {
        node* trav=head;
        while(trav->next!=NULL)
        {
            trav=trav->next;
        }
        trav->next=ptr;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty!!!!!");
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
    printf("\n");
}
void selection_sort()
{
    node *i,*j;
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j->next!=NULL;j=j->next)
        {
            if(i->data > j->data)
            {
            swap(i->data,j->data);
            }
        }
    }
}
int main()
{
    add_last(40);
    add_last(20);
    add_last(50);
    add_last(90);
    add_last(30);
    add_last(80);
    display();
    selection_sort();
    display();
    return 0;
}