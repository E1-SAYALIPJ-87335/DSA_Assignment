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

void add_first(int data);
node* create_node();
void forward_display();
node *linear_search(int key);
int main()
{
    add_first(40);
    add_first(35);
    add_first(20);
    add_first(30);
    add_first(40);
    add_first(60);
    forward_display();

    node *result ;
    result = linear_search(40);

    if(result == NULL)
    {
        printf("key not found !");
    }
    else
    {
        printf("key found !!");
    }
    
   
    return 0;
}

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

node *linear_search(int key)
{
    node *trav = head;
    while(trav != NULL)
    {
        if(trav->data == key)
        {
            return trav;
        }
        trav = trav->next;
    }

    return NULL;

}


