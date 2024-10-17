#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node* next;
}node;

node *head = NULL;
node *tail = NULL;

node* create_node()
{
   node* new_node = (node*)malloc(sizeof(node));
   if(new_node == NULL)
   {
    printf("Malloc Failed !\n");
   }
   else
   {
    new_node->data = 0;
    new_node->next = NULL;
    new_node->prev = NULL;
   }
   return new_node;
}

void add_first(int data)
{
    // 1. create
    struct node* new_node = create_node();

    new_node->data = data;

    // attach
    //a. if list is empty
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        // create a forward link between newnode and 1st node
        new_node->next = head;

        // create a backward link between first node and new node
        head->prev = new_node;

        // update the head pointer
        head = new_node;
    }
}

void forward_display()
{
    if(head == NULL)
    {
        printf("List is Empty !\n");
    }
    else
    {
        struct node* trav = head;

        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}
void reverse_list()
{
struct node *n1 = head;
struct node *n2 = head->next;
while(n2 != NULL)
{
struct node *n3 = n2->next;
n2->next = n1;
n1 = n2;
n2 = n3;
}
head->next = NULL;
head = n1;
}

int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    add_first(40);
    add_first(50);
    forward_display();
    reverse_list();
    forward_display();
    return 0;
}