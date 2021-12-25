#include <stdio.h>
#include <stdlib.h>


struct node_t {

  	int data;
  	struct node_t* left;
  	struct node_t* right;
};

void insert(struct node_t* tree, int value) 
{
  	struct node_t* new_node = malloc(sizeof(struct node_t));
  	
  	new_node->data = value;
  	new_node->left = NULL;
  	new_node->right = NULL;

  	struct node_t** branch;
  	if(value > tree->data) 
  	{
    		branch = &tree->right;
  	} else 
  	{
    		branch = &tree->left;
  	}

  	if(*branch == NULL) 
  	{
    		*branch = new_node;
  	} else 
  	{
    		insert(*branch, value);
  	}
}

int max(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    return num2;
}

int height(struct node_t* node)
{
    if (node == NULL)
        return 0;
 
    return 1 + max(height(node->left), height(node->right));
}

int isBalanced(struct node_t* root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
  
    if (root == NULL)
        return -1;
  
    lh = height(root->left);
    rh = height(root->right);
  
    if (abs(lh - rh) <= 1 && isBalanced(root->left) == 0 && isBalanced(root->right) == 0)
        return 0;
  
    return -1;
}



void print(struct node_t* root, int level) 
{
    if(root == NULL)
    {
  	   return;
    }

    printf("[%d] %d", level, root->data);

    if(root->left != NULL || root->right != NULL) 
    {
    	  print(root->left, level + 1);
    	  print(root->right, level + 1);
    
    }  
}



int main() 
{
  	struct node_t n1 = {8, NULL, NULL};

  	insert(&n1, 13);
  	insert(&n1, 5);
  	insert(&n1, 2);
  	insert(&n1, 7);
  	insert(&n1, 3);

  	print(&n1,0);

  	return 0;
}


