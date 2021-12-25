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

int countPathsWithsum(struct node* leaf, int targetSum, int currentSum)
{
    	if(leaf == NULL) 
    	{
    		return 0;
    	}

    	currentSum += leaf->data;
    	int paths_count = 0;
    	if(currentSum == targetSum)
    	{
        	paths_count++;
    	}
    	else
    	{
        	paths_count += countPathsWithsum(leaf->left, targetSum, currentSum);
        	paths_count += countPathsWithsum(leaf->right, targetSum, currentSum);
    	}
    	return paths_count;
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
    	root->left->left = newNode(4);
    	root->right->right = newNode(6);
    	root->left->left->left = newNode(8);
    	root->left->left->right = newNode(7);
 
    	print(root, 0);
    	
    	printf("\n %d ", countPathsWithsum(root, 4, 0));
    	return 0;
}
