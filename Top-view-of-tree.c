

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/
struct que_node {
    struct node *node;
    int dist;
    struct que_node *next;
};

struct vertical_list {
    int dist;
    struct node *tree_node;
    struct vertical_list *next;
};

struct vertical_list *list = NULL;

struct que_node *level = NULL;

int least = 0;
int highest = 0;

struct que_node *allocate_level_node (struct node *tree_node, int dist)
{
    struct que_node *temp = NULL;

    temp = malloc(sizeof(struct que_node));

    temp->node = tree_node;
    temp->dist = dist;
    temp->next = NULL;

    return temp;
}
void enqueue(struct node *tree_node, int dist)
{
    if (least > dist){
        least = dist;
    }
    if (highest < dist) {
        highest = dist;    
    }
    if (level == NULL) {
        level = allocate_level_node(tree_node, dist);
        return;
    } else {
        struct que_node *temp = allocate_level_node(tree_node, dist);
        temp->next = level;
        level = temp;
        return;
    }
}

struct que_node *dequeue()
{
    struct que_node *curr = level;
    struct que_node *prev = NULL;

    if (curr && curr->next == NULL) {
        level = NULL;
        return curr;
    }
    while(curr->next) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    return curr;
}

int isQueue(void *q)
{
    return (q ? 1 : 0);
}
void add_to_vertical_list(struct node *tree_node, int dist)
{
    struct vertical_list *temp = list;
    struct vertical_list *new = list;
    int add = 1;

    if (list == NULL){
        temp = malloc(sizeof(struct vertical_list));
        temp->dist = dist;
        temp->tree_node = tree_node;
        temp->next = NULL;
        list = temp;
    } else{
        while(temp->next) {
            if (temp->dist == dist)  {
                add = 0;
                break;
            }
            temp = temp->next;
        }
        if (add) {
            new = malloc(sizeof(struct vertical_list));
            new->dist = dist;
            new->tree_node = tree_node;
            new->next = NULL;
            temp->next = new;
        }
    }
}
void verticalView( struct node *root)
{
    int dist_l = 0;
    int dist_r = 0;
    struct que_node *temp;
    
    enqueue(root, 0);

    while(isQueue((void *)level)) {
        temp = dequeue();

        add_to_vertical_list(temp->node, temp->dist);

        if (temp->node->left){
            dist_l = temp->dist - 1;
            enqueue(temp->node->left, dist_l);
        }
        if (temp->node->right) {
            dist_r = temp->dist + 1;
            enqueue(temp->node->right, dist_r);
        }
        //free(temp);
    }
}
void topView( struct node *root) {
    int dist = 0;
    verticalView(root);

    for (dist = least; dist <= highest; dist++) {
        struct vertical_list *temp = list;
        while(temp) {
            if (temp->dist == dist){
                printf("%d ", temp->tree_node->data);
                break;
            }
            temp = temp->next;
        }
    }
}

