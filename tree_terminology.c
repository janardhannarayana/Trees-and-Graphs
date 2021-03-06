/*
 * tree_terminology.c
 *
 * Written on Monday,  6 January 2020.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree BST;
typedef struct queue QUEUE;

struct tree{
    int data;
    BST *left;
    BST *right;
};

struct queue {
    BST *tree_node;
    QUEUE *next;
};

BST *root = NULL;
QUEUE *first = NULL;

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

BST *find_parent(int data, BST *child, BST *parent)
{
    if (root == NULL) {
	printf("No nodes in tree\n");
	return NULL;
    }
    
    if (child) {
	if (child->data == data) {
	    return parent;
	} else {
	    if (child->data > data)
		find_parent(data, child->left, child);
	    else
		find_parent(data, child->right, child);
	}
    } else {
	return NULL;
    }
}

int find_height(BST *node)
{
    if (node) {
	int lh = 0;
	int rh = 0;

	lh = find_height(node->left);
	rh = find_height(node->right);

	return (((lh > rh) ? lh : rh) + 1);
    } else {
	return -1;
    }
}

void enqueue(BST *tree_node)
{
    if (tree_node) {
	QUEUE *node = malloc(sizeof(QUEUE));
	
	node->tree_node = tree_node;
	node->next = first;
	
	first = node;
    }
}

BST *dequeue()
{
    BST *temp = NULL;
    
    if (first && first->next == NULL) {
	temp = first->tree_node;
	free(first);
	first = NULL;
	return temp;
    }
    
    if (first) {
	QUEUE *curr = first;
	QUEUE *prev = NULL;

	while(curr->next) {
	    prev = curr;
	    curr = curr->next;
	}
	prev->next = NULL;
	temp = curr->tree_node;
	free(curr);
	
	return temp;
    } else {
	return NULL;
    }
}

int isQueue()
{
    return (first ? 1 : 0);
}

void level_order_traversal(BST *root)
{
    BST *temp = NULL;
    enqueue(root);

    while(isQueue()) {
	temp = dequeue();
	printf("temp->data = %d\n",temp->data);
	enqueue(temp->left);
	enqueue(temp->right);
    }
}

int main()
{
    int lheight = 0;
    int rheight = 0;
    
    BST *parent = NULL;
    insert_node(100, root);
    insert_node(1, root);
    insert_node(200, root);
    insert_node(20, root);
    insert_node(10, root);
    insert_node(12, root);
    insert_node(11, root);
    insert_node(30, root);
    insert_node(2, root);
    insert_node(15, root);
    
    in_traverse(root);
    printf("\n");
    parent = find_parent(15, root, root);
    if (parent)
	printf("parent = %d\n",parent->data);
    printf("%d\n",find_height(root));
    level_order_traversal(root);
}

