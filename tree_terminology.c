/*
 * tree_terminology.c
 *
 * Written on Monday,  6 January 2020.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree BST;
struct tree{
    int data;
    BST *left;
    BST *right;
};

BST *root = NULL;

BST *insert_node(int data, BST *node)
{
    if (node) {
	if (node->data > data)
	    node->left = insert_node(data,node->left);
	else
	    node->right = insert_node(data,node->right);
	return node;
    } else {
	BST *temp = malloc(sizeof(BST));
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	if (root == NULL)
	    root = temp;
	return temp;
    }
}

void find_the_parent(data)
{
    BST *temp = root;

}

void in_order_traversal(BST *node)
{
    if (node) {
	in_order_traversal(node->left);
	printf("%d->",node->data);
	in_order_traversal(node->right);
    }
}

int main()
{
    insert_node(5, root);
    insert_node(10, root);
    insert_node(1, root);
    insert_node(9, root);
    insert_node(12, root);
    insert_node(7, root);
    in_order_traversal(root);
    printf("\n");
}
