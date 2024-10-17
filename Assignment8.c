#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;

struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void in_order(struct node *trav) {
    if (trav == NULL) {
        return;
    }
    in_order(trav->left);
    printf("%4d", trav->data);
    in_order(trav->right);
}

struct node *add_node(struct node *root, int data) {
    if (root == NULL) {
        return create_node(data); 
    }

    if (data < root->data) {
        root->left = add_node(root->left, data);
    } else {
        root->right = add_node(root->right, data);
    }

    return root;
}

int main() {
    root = add_node(root, 50);
    add_node(root, 25);
    add_node(root, 66);
    add_node(root, 88);
    add_node(root, 20);
    add_node(root, 22);
    add_node(root, 90);
    add_node(root, 50); 
    add_node(root, 80);
    add_node(root, 36);
    printf("\n In Order :\n");
    in_order(root);
    return 0; 
}