#include <stdlib.h>
#include <stdio.h>

struct node_t {
  int value;
  struct node_t* next;
  struct node_t* prev;
};

struct list_t {
  struct node_t* head;
  struct node_t* tail;
  int size;
};

struct problem
{
    char title[50];
    int points;
    int time;
};

void push_front(struct list_t* list, int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  new_node->prev = NULL;
  if(list->head != NULL) {
    list->head->prev = new_node;
  } else {
    list->tail = new_node;
  }
  new_node->next = list->head;

  list->head = new_node;

  list->size++;

}


void print_list(struct list_t* list) {
  struct node_t* curr = list->head;
  int counter = 1;
  printf("Size = %d\n", list->size);

  while(curr != NULL) {
    printf("[%d] %d\n", counter++, curr->value);
    curr = curr->next;
  }
}

int sum_times(struct list_t* tasks, unsigned int under_time)
{
    struct node_t* curr=list->head;

	for(int sum=0;curr!=NULL;curr=curr->next)
    {
		if(curr->time<under_time)
        {
			sum=sum+curr->time;
		}
	}

	return sum;
}

int main()
{


    return 0;
}
