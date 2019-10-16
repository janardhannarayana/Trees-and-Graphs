#include <stdio.h>
#include <stdlib.h>

typedef struct bst BST;

struct bst {
    int data;
    BST *left;
    BST *right;
};

BST *root = NULL;


void in_order_traversal(BST *root)
{
    if (root) {
	in_order_traversal(root->left);
	printf("%d\t",root->data);
	in_order_traversal(root->right);
    }
}

void insert_data(int data)
{
    BST *node  = malloc(sizeof(BST));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    if (root) {
	BST *temp = root;
	
    } else {
	root = node;
    }
    
    return;
}

int main()
{
    insert_data(5);
    in_order_traversal(root);
    insert_data(1);
    insert_data(2);
    insert_data(3);
    in_order_traversal(root);
}
