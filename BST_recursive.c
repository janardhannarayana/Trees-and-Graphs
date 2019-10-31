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

void pre_order_traversal(BST *root)
{
    if (root) {
	printf("%d\t",root->data);
	pre_order_traversal(root->left);
	pre_order_traversal(root->right);
    }
}

void post_order_traversal(BST *root)
{
    if (root) {
	post_order_traversal(root->left);
	post_order_traversal(root->right);
	printf("%d\t",root->data);
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

    if (root == NULL) {
	root = new_node(data);
	return root;
    }
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
    printf("\n");
    insert_data(root, 1);
    insert_data(root, 12);
    insert_data(root, 2);
    insert_data(root, 9);
    insert_data(root, 3);
    insert_data(root, 11);
    insert_data(root, 4);
    insert_data(root, 100);
    in_order_traversal(root);
    printf("\n");    
    pre_order_traversal(root);
    printf("\n");
    post_order_traversal(root);
    printf("\n");
}
