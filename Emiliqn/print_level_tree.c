#include <stdio.h>
#include <stdlib.h>

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
 
void PrintLeafNodes(struct node* root, int level)
{
    	if (root == NULL)
    	{
        	return;
        }
 
    	if (level == 1) 
    	{
        	if (root->left == NULL && root->right == NULL)
        	{
            		printf("%d ", root->data );
            	}
    	}
    	else if (level > 1) 
    	{
        	PrintLeafNodes(root->left, level - 1);
        	PrintLeafNodes(root->right, level - 1);
    	}
}
 
int main()
{
    	struct node* root = newNode(1);
    	root->left = newNode(2);
    	root->right = newNode(3);
    	root->left->left = newNode(6);
    	root->right->right = newNode(4);
    	root->left->left->left = newNode(8);
    	root->left->left->right = newNode(7);
 
    	int level = 4;
 
    	PrintLeafNodes(root, level);
 
    	return 0;
}
