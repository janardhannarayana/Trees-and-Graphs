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

BST *new_node(int data)
{
    BST *temp = malloc(sizeof(BST));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
BST *insert_data(BST *node, int data)
{

    if (node == NULL) {
	return new_node(data);
    }
    
    if (node->data > data) {
	node->left = insert_data(node->left, data);
    } else {
	node->right = insert_data(node->right, data);
    }
}

int main()
{
    insert_data(root, 5);
    in_order_traversal(root);
    insert_data(root, 1);
    insert_data(root, 2);
    insert_data(root, 3);
    in_order_traversal(root);
}
