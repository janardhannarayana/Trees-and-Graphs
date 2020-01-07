/**
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

void insert_node(int data, BST *node)
{
    if (node) {
	if (node->data > data)
	    insert_node(data,node->left);
	else
	    insert_node(data,node->right);
    }
}

int main()
{
    
}
