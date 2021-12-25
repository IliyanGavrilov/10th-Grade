#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5

struct node_t
{
    int counter;
    int array[MAX_SIZE];
    struct node_t *next;
};

struct list_t
{
	struct node_t *head;
	int size;
};

void print_list(struct list_t* list)
{
	struct node_t *curr = list->head;
	int j = 1;
	printf("size = %d\n", list->size);

    while (curr != NULL)
    {
        for (int i=0; i < MAX_SIZE; i++)
        {
            printf("[%d] %d\n", j++, curr->array[i]);
        }
        curr = curr->next;
    }
}

void push_front(struct list_t* list)
{
	struct node_t *new_node = (struct node_t*)malloc(sizeof(struct node_t));

	for(int i = 0;i < MAX_SIZE; i++)
	{
		printf("Number[%d] = ", i);
		scanf("%d",&new_node->array[i]);
	}

	new_node->next = list->head;
	list->head = new_node;
	list->size++;
}

void push_back(struct list_t* list)
{

    struct node_t *new_node = (struct node_t*)malloc(sizeof(struct node_t));
    struct node_t *last = list->head;

    for(int i = 0;i < MAX_SIZE; i++)
	{
		printf("Number[%d] = ", i);
		scanf("%d",&new_node->array[i]);
	}

    new_node->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    list->size++;
}

void pop_front(struct list_t* list)
{
  	if(list->size == 0)
  	{
    		return;
  	}

  	if(list->size == 1)
  	{
    		free(list->head);
    		list->head = NULL;
    		list->size--;
    		return;
  	}

  	struct node_t* new_node = list->head->next;
  	free(list->head);
  	list->head = new_node;
  	list->size--;
}


void pop_back(struct list_t* list)
{

  	if(list->size < 2)
  	{
    		pop_front(list);
    		return;
  	}

  	struct node_t* new_tail = list->head;

  	for(int i = 2; i < list->size; i++)
  	{
    		new_tail = new_tail->next;
  	}

  	free(new_tail->next);
  	new_tail->next = NULL;
  	list->size--;
}

int main()
{
	struct list_t my_list = {NULL, 0};

	push_front(&my_list);
	push_back(&my_list);
	push_front(&my_list);

	print_list(&my_list);
	puts("\n");

	pop_front(&my_list);
	pop_back(&my_list);

	print_list(&my_list);

	return 0;
}
