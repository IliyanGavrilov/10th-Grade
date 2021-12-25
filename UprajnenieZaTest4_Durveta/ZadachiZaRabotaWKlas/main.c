#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t
{
    int data;
    struct node_t *left;
    struct node_t *right;
};

void add_leaf(struct node_t *root, int data)
{
    struct node_t *new_node = malloc(sizeof(struct node_t));
    struct node_t *current = root;

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    while(1)
    {
        if(current->data < data)
        {
            if(current->left == NULL)
            {
                current->left = new_node;
                return;
            }
            else
            {
                current = current->left;
            }
        }
        else if(current->data > data)
        {
            if(current->right = NULL)
            {
                current->right = new_node;
                return;
            }
            else
            {
                current = current->right;
            }
        }
        else
        {
            return;
        }
    }
}

void print(struct node_t *root)
{
    if(root == NULL)
    {
        return;
    }

    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

int main()
{
    struct node_t root = {NULL, NULL, 5};

    add_leaf(&root, 2);
    add_leaf(&root, 21);
    add_leaf(&root, 5);
    add_leaf(&root, 7);

    print(&root);

    return 0;
}
