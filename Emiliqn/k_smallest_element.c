#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_t
{  
    struct node_t* left; 
    struct node_t* right;
    int data;
};

struct node_t* newNode(int data)
{
    	struct node_t* temp = (struct node_t*)malloc(sizeof(struct node_t));
 
    	temp->data = data;
    	temp->left = NULL;
    	temp->right = NULL;
 
    	return temp;
}

struct stack_node_t
{
    struct node_t* node;
    struct stack_node_t *prev;
};

struct stack_t
{
    struct stack_node_t *head;
    struct stack_node_t *tail;
    int size;
};


struct node_t* s_pop(struct stack_t* stack)
{
    struct node_t* node = NULL;
    
    if(stack->tail != NULL)
    {
        node = stack->tail->node;
        struct stack_node_t* prev = stack->tail->prev;
        free(stack->tail);
        stack->tail = prev;
        if(stack->tail == NULL)
        {
            stack->head = NULL;
        }
        stack->size--;
    }

    return node;
}

void s_push(struct stack_t* stack, struct node_t* t_node)
{

    struct stack_node_t *new_s_node = malloc(sizeof(struct stack_node_t));
    new_s_node->prev = NULL;
    new_s_node->node = t_node;
    
    stack->size++;
    if(stack->head == NULL)
    {
        stack->tail = stack->head = new_s_node;
        return;
    }
    new_s_node->prev =  stack->tail;
    stack->tail = new_s_node;
}


int k_smallest_element(struct node_t *root, int k) 
{ 
    struct stack_t stk = {NULL, NULL, 0};

    struct node_t *current = root; 
  
    while( current != NULL ) 
    { 
        s_push(&stk, current);
        current = current->left; 
    } 
  
 
    while( stk.size > 0 ) 
    { 
        current = s_pop(&stk);
        if( --k == 0 ) 
        {
            break; 
        } 
  
        if( current->right ) 
        { 
            current = current->right; 
            while( current ) 
            { 
                s_push(&stk, current);
                current = current->left; 
            } 

        } 
    } 
    if(k != 0)
    {
        puts("Wrong parameters");
        return 0;
    }

    /* node_t having k-th element or NULL node_t */
    return current->data; 
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
	struct node_t* root = newNode(1);
	
    	root->left = newNode(2);
    	root->right = newNode(4);
    	root->left->left = newNode(3);
    	root->right->right = newNode(6);
    	root->left->left->left = newNode(8);
    	root->left->left->right = newNode(9);
 
 	print(root, 0);
    	
    	printf("\n %d ", k_smallest_element(root, 2));
    	return 0;
}

