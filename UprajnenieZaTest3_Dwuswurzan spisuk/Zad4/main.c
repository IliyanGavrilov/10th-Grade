#include <stdlib.h>
#include <stdio.h>

struct node_t {
  int value;
  struct node_t* next;
};

struct list_t {
  struct node_t* head;
  int size;
};

void push(struct list_t* list, int value)
{
    struct node_t* new_node = malloc(sizeof(struct node_t));
    struct node_t* curr = list->head;

    new_node->value = value;

    if(list->size == 0)
    {
        list->head = new_node;
        new_node->next = NULL;
        list->size++;
        return;
    }

    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_node;
    new_node->next = NULL;
    list->size++;
}

void pop(struct list_t* list)
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

    list->head = list->head->next;
    list->size--;
}

void print_list(struct list_t* list)
{
    struct node_t* curr = list->head;
    int counter = 1;
    printf("size == %d\n", list->size);

    while(curr != NULL)
    {
        printf("[%d] %d\n", counter++, curr->value);
        curr = curr->next;
    }
}

int main()
{
    struct list_t my_list = {NULL, 0};

    push(&my_list, 1);
    push(&my_list, 2);
    push(&my_list, 3);
    push(&my_list, 4);
    print_list(&my_list);
    pop(&my_list);
    print_list(&my_list);
    puts("\n");

    return 0;
}
