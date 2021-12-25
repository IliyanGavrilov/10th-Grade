#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {

    	struct node* left;
    	struct node* right;
    	int data;
};


struct node* newNode(int data)
{
    	struct node* temp = (struct node*)malloc(sizeof(struct node));
 
    	temp->data = data;
    	temp->left = NULL;
    	temp->right = NULL;
 
    	return temp;
}

int min(int num1, int num2)
{
    if(num1 < num2)
    {
        return num1;
    }
    return num2;
}

int max(int num1, int num2)
{
    if(num1 > num2)
    {
        return num1;
    }
    return num2;
}

struct node* lowest_common_ancestor(struct node* n1, struct node *n2, struct node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    int min_data = min(n1->data, n2->data);
    int max_data = max(n1->data, n2->data);

    if(root->data > min_data && root->data < max_data)
    {
        return root;
    }
    // if both x and y are smaller than root, LCA exists in left subtree
	else if (root->data > max_data)
    {
		return lowest_common_ancestor(n1, n2, root->left);
    }
	// if both x and y are greater than root, LCA exists in right subtree
	else  if (root->data < min_data)
    {
		return lowest_common_ancestor(n1, n2, root->right);
    }
    
    return root;
}


void print(struct node* root, int level) 
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
	struct node* root = newNode(1);
	
    	root->left = newNode(2);
    	root->right = newNode(4);
    	root->left->left = newNode(3);
    	root->right->right = newNode(6);
    	root->left->left->left = newNode(8);
    	root->left->left->right = newNode(9);
 
    	print(root, 0);
    	
    	lowest_common_ancestor(root->left->left->right, root->right->right, root);
    	return 0;
}
