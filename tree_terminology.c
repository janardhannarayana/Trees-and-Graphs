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

BST *allocate_node(int data)
{
    BST *node = malloc(sizeof(BST));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_node(int data, BST *node)
{
    if (root == NULL) {
	root = allocate_node(data);
    }
    if (node) {
	if (node->data > data) {
	    if (node->left)
		insert_node(data, node->left);
	    else
		node->left = allocate_node(data);
	} else {
	    if (node->right)
		insert_node(data, node->right);
	    else
		node->right = allocate_node(data);
	}
    }
}

void in_traverse(BST *node)
{
    if (node) {
	in_traverse(node->left);
	printf("%d\t",node->data);
	in_traverse(node->right);
    }
}

void find_parent(int data, BST *child, BST *parent)
{
    if (root == NULL) {
	printf("No nodes in tree\n");
	return;
    }  
}

int main()
{
    insert_node(100, root);
    insert_node(1, root);
    insert_node(200, root);
    insert_node(20, root);
    insert_node(10, root);
    insert_node(11, root);
    insert_node(30, root);
    insert_node(2, root);
    in_traverse(root);
}

