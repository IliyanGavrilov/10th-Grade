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

void push_back(struct list_t* list, int value) {
  if(!list->head) {
    push_front(list, value);
    return;
  }

  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  new_node->next = NULL;
  new_node->prev = list->tail;

  list->tail->next = new_node;
  list->tail = new_node;

  list->size++;
}

void print_list(struct list_t* list) {
  struct node_t* curr = list->head;
  int counter = 1;
  printf("size == %d\n", list->size);

  while(curr != NULL) {
    printf("[%d] %d\n", counter++, curr->value);
    curr = curr->next;
  }
}

void insert_middle(struct list_t* list, int value) {
  struct node_t* new_node = malloc(sizeof(struct node_t));
  new_node->value = value;

  struct node_t* curr = list->head;
  int counter = 1;
  // s == 6; c = 0; i = 1
  // s == 6; c = 1; i = 2
  // s == 6; c = 2; i = 3
  // s == 6; c = 3; i = 4
  // s == 6; c = 4; i = 5
  while(counter < list->size / 2) {
    curr = curr->next;
    counter++;
  }
  //printf("%d %d\n", counter, curr->value);
  new_node->prev = curr;
  new_node->next = curr->next;

  curr->next->prev = new_node;
  curr->next = new_node;

  list->size++;
}

void pop_front(struct list_t* list) {
  if(!list->head) { // list->size == 0
    return;
  }

  if(!list->head->next) { // list->size == 1
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    list->size--;
    return;
  }

  list->head = list->head->next;
  free(list->head->prev);
  list->head->prev = NULL;
  list->size--;
}

void pop_back(struct list_t* list) {
  if(list->size < 2) {
    pop_front(list);
    return;
  }

  struct node_t* curr = list->tail;

  curr->prev->next = NULL;
  list->tail = curr->prev;
  free(curr);
  list->size--;
}

void swap_nodes(struct node_t* left, struct node_t* right) {
  struct node_t* next = right->next;

  if(left->prev != NULL)
    left->prev->next = right;

  right->next = left;
  right->prev = left->prev;
  left->next = next;
  left->prev = right;

  if(next != NULL)
    next->prev = left;
}


void filter_list(struct list_t *list, int number)
{
  struct node_t *current = list->head;
  while(current != NULL)
  {
    if(current->value < number)
    {
        if(current->next != NULL)
        {
          current->next->prev = current->prev;
        }
        else
        {
          list->tail = current->prev;
        }

        if(current->prev != NULL)
        {
          current->prev->next = current->next;
        }
        else
        {
          list->head = current->next;
        }

        struct node_t *tmp = current;

        current = current->next;
        free(tmp);
        list->size--;
    }
    else
    {
          current = current->next;

    }
  }

}


void insert_at(struct list_t *list, int pos, int number)
{

  struct node_t *new = malloc(sizeof(struct node_t));
  new->value = number;
  int counter;
  struct node_t *current = list->head;
  for(counter = 0; counter < pos && current->next != NULL; counter++ )
  {
    current = current->next;
  }


  struct node_t *next = current->next;

  current->next = new;
  new->prev = current;
  new->next = next;

  if(next != NULL)
  {
    next->prev = new;
  }
  else
  {
    list->tail = new;
  }


  list->size++;


}

void push_middle(struct list_t* list, int value)
{
    if(list->size <= 1)
    {
        push_front(list, value);
        return;
    }

    struct node_t* new_node = malloc(sizeof(struct node_t));
    new_node->value = value;

    struct node_t* curr = list->head;
    int i = 1;

    if(list->size % 2 == 0)
    {
        while(i < list->size / 2)
        {
            curr = curr->next;
            i++;
        }

        new_node->prev = curr;
        new_node->next = curr->next;

        curr->next->prev = new_node;
        curr->next = new_node;

        list->size++;
    }
    else
    {
        while(i < list->size / 2)
        {
            curr = curr->next;
            i++;
        }
        curr = curr->next;
        new_node->prev = curr;
        new_node->next = curr->next;

        curr->next->prev = new_node;
        curr->next = new_node;

        list->size++;
    }

}

int pop_middle(struct list_t* list)
{
    struct node_t* curr = list->head;

    if(list->size == 0)
    {
        return 0;
    }

    if(list->size == 1)
        {
            int value = curr->value;
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->size--;

            return value;
        }

    if(list->size == 2)
        {
            curr=curr->next;
            int value = curr->value;
            curr=curr->prev;
            list->tail = curr;
            free(curr->next);
            curr->next = NULL;
            list->size--;

            return value;
        }

    int i = 1;
    while(i < list->size / 2)
        {
            curr = curr->next;
            i++;
        }
    curr = curr->next;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    list->size--;

    int value = curr->value;
    free(curr);
    return value;
}

int pop_middle_improved(struct list_t* list, int* result)
{
    struct node_t* curr = list->head;

    if(list->size == 0)
    {
        return 0;
    }

    if(list->size == 1)
        {
            *result = curr->value;
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->size--;

            return 1;
        }

    if(list->size == 2)
        {
            curr=curr->next;
            *result = curr->value;
            curr=curr->prev;
            list->tail = curr;
            free(curr->next);
            curr->next = NULL;
            list->size--;

            return 1;
        }

    int i = 1;
    while(i < list->size / 2)
        {
            curr = curr->next;
            i++;
        }
    curr = curr->next;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    list->size--;

    *result = curr->value;
    free(curr);
    return 1;
}

int main()
{
    struct list_t my_list = {NULL, NULL, 0};


    push_front(&my_list, 1);
    push_front(&my_list, 2);
    push_back(&my_list, 4);
    /*push_front(&my_list, 103);

    push_back(&my_list, 12);

    insert_middle(&my_list, 18);*/
    print_list(&my_list);
    puts("\n");

    /*pop_front(&my_list);
    pop_back(&my_list);
    pop_back(&my_list);*/
    /*sort_list(&my_list);

    print_list(&my_list);*/
    insert_at(&my_list, 0, 3);
    //filter_list(&my_list, 9);

    printf("Pop_Middle Value = %d\n", pop_middle(&my_list));
    print_list(&my_list);

    return 0;
}
