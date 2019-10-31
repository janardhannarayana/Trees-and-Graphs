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

    BST *temp = root;

    if (temp == NULL) {
	printf("No nodes available in the ")
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


void insert_data(int data)
{
    BST *node = malloc(sizeof(BST));
    BST *temp = root;
    
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    
    if (temp == NULL) {
	root = node;
	return;
    }  else {
	while(temp) {
	    if (temp->data > data) {
		if (temp->left) {
		    temp = temp->left;
		} else {
		    temp->left = node;
		    return;
		}
	    } else {
		if (temp->right) {
		    temp = temp->right;
		} else {
		    temp->right = node;
		    return;
		}
	    }
	}
    }
}

int main()
{
    insert_data(5);
    in_order_traversal(root);
    insert_data(1);
    insert_data(12);
    insert_data(2);
    insert_data(9);
    insert_data(3);
    insert_data(11);
    insert_data(4);
    insert_data(100);
    in_order_traversal(root);
    printf("\n");    
    pre_order_traversal(root);
    printf("\n");
    post_order_traversal(root);
    printf("\n");
}
