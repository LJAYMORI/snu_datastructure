#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

typedef struct node
{
    int val;
    struct node * parents;
    struct node * left;
    struct node * right;
    int height;
} node_t;

node_t * find(node_t *root, int val)
{

}

int height(node_t * root)
{

}

void adjust_height(node_t *root)
{

}

node_t *rotate_right(node_t *root)
{

}

node_t *rotate_left(node_t *root)
{

}

node_t *make_node(int val, node_t *parent)
{

}

node_t *balance(node_t *root)
{

}

node_t *insert(node_t *root, int val)
{

}

void print_tree_indent(node_t *node, int indent)
{

}

void print_tree(node_t *node)
{

}

int main(void)
{

    return 0;
}