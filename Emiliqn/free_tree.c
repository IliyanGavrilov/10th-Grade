#include <stdio.h>
#include <stdlib.h>

struct node_t {

    int value;
    struct node_t *left;
    struct node_t *right;
};



struct node_t *newNode(int item)
{
    struct node_t *temp = (struct node_t*)malloc(sizeof(struct node_t));
    temp->value = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
struct node_t *insert(struct node_t *node, int value)
{
    if(node == NULL)
    {
        return newNode(value);
    }
 
    if (value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = insert(node->right, value);
    }
 
    return node;
}

void deleteTree(struct node_t* root) 
{
    if (root == NULL)
    {
    	 return;
    }
  
    deleteTree(root->left);
    deleteTree(root->right);
    
    free(root);
} 


void print(struct node_t* root, int level) 
{
    if(root == NULL)
    {
  	   return;
    }

    printf("[%d] %d", level, root->value);

    if(root->left != NULL || root->right != NULL) 
    {
    	  print(root->left, level + 1);
    	  print(root->right, level + 1);
    
    }  
}


int main()
{
    	struct node_t *root = NULL;
    
    	root = insert(root, 50);
    
    	insert(root, 30);
    	insert(root, 20);
    	insert(root, 40);
    	insert(root, 70);
    	insert(root, 60);
    	insert(root, 80);
    	insert(root, 10);
 
   	print(root,0);
 
    	deleteTree(root);
    	root = NULL;
    
    
    	return 0;
}

