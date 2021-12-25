#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t{
    int value;
    struct node_t *next;
};

struct list_t{
    int size;
    struct node_t *head;
};

int size(struct list_t list){
    return list.size;
}

int is_empty(struct list_t list){
    return list.size == 0 || list.head == NULL;
}

void insert(struct list_t *list, int new_element_value){
    struct node_t  *new_element = malloc(sizeof(struct node_t));
    new_element->value = new_element_value;
    new_element->next = NULL;

    if(list->head != NULL){
        new_element->next = list->head;
    }

    list->head = new_element;
    list->size++;
}

void remove_first(struct list_t *list){
    struct node_t *old_head = list->head;
    list->head = old_head->next;

    free(old_head);
    old_head = NULL;
    list->size--;
}

void init_list(struct list_t *list){
    list->size = 0;
    list->head = NULL;
}

void destroy_list(struct list_t *list){
    while(list->head->next != NULL){
        remove_first(list);
    }

    list->size = 0;
    free(list->head);
    list->head = NULL;
}
void print_list(struct list_t *list)
{
    struct node_t *tmp_element = list->head;
    while(tmp_element->next != NULL)
    {
        printf("%d\n", tmp_element->value);
        tmp_element = tmp_element->next;
    }
    // Print last element
    printf("%d\n", tmp_element->value);
}

struct node_t get_by_value(struct list_t *list)
{

}

int main(){
    struct list_t my_list;


    init_list(&my_list);
    printf("%d\n",size(my_list));
    insert(&my_list,5);
    printf("%d\n",size(my_list));
    insert(&my_list,6);
    insert(&my_list,7);
    insert(&my_list,8);
    printf("%d\n",size(my_list));
    remove_first(&my_list);
    printf("after remove :%d\n",size(my_list));
    print_list(&my_list);
    destroy_list(&my_list);
    //printf("%d\n",size(my_list));

    return 0;
}

