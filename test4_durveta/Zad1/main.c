#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t
{
	int value;
	struct node_t *left;
	struct node_t *right;
};

struct node_t new_node(int value)
{
    struct node_t *new_node = malloc(sizeof(struct node_t));

    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return (*new_node);
}

void inorder_traverse(struct node_t *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder_traverse(root->left);
    printf("%d ", root->value);
    inorder_traverse(root->right);
}

int check_BST(struct node_t *root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1;
}

int main()
{
    struct node_t *root = {0, NULL, NULL};

    *root->left = new_node(6);
    *root->right = new_node(7);
    *root->left->left = new_node(8);
    *root->left->right = new_node(9);

    inorder_traverse(root);

    return 0;
}
