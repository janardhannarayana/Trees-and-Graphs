#include <stdio.h>
#include <stdlib.h>

typedef struct bst BST;
typedef struct stack STACK;

struct bst {
    int data;
    BST *left;
    BST *right;
};

struct stack {
    BST *node;
    STACK *next;
};

BST *root = NULL;
STACK *first = NULL;

void push(BST *node)
{
    STACK *temp = first;

    STACK *t_node = malloc(sizeof(STACK));

    t_node->node = node;
    t_node->next = NULL;
    
    if (first == NULL) {
	first = t_node;
    } else {
	while (temp->next != NULL) {
	    temp = temp->next;
	}
	temp->next = t_node;
    }	
}

void pop(BST **node)
{
    STACK *temp = first;
    STACK *prev = NULL;

    if (first) {
	while (temp->next != NULL) {
	    prev = temp;
	    temp = temp->next;
	}
	if (first->next != NULL)
	    prev->next = NULL;
	else
	    first = NULL;
	*node = temp->node;
	free(temp);
    }
}

void in_order_traversal(BST *root)
{
    if (root) {
	in_order_traversal(root->left);
	printf("%d\t",root->data);
	in_order_traversal(root->right);
    }
}

void in_order_traversal_non(BST *root)
{
    BST *temp = root;
    BST *curr = root;
    int end = 0;

    if (temp == NULL) {
	printf("No nodes available\n");
    } else {
	while(!end) {
	    if (temp != NULL) {
		push(temp);
		temp = temp->left;
	    } else {
		if (first != NULL) {
		    pop(&temp);
		    printf("%d\t",temp->data);
		    temp = temp->right;
		} else {
		    end = 1;
		}
	    }
	}
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
    printf("\n");
    in_order_traversal_non(root);
    printf("\n");
    insert_data(1);
    insert_data(12);
    insert_data(2);
    insert_data(9);
    insert_data(3);
    insert_data(11);
    insert_data(4);
    insert_data(100);
    insert_data(0);
    in_order_traversal(root);
    printf("\n");
    in_order_traversal_non(root);
    printf("\n");
    pre_order_traversal(root);
    printf("\n");
    post_order_traversal(root);
    printf("\n");
}
