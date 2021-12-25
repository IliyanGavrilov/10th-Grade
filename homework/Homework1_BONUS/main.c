#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TOPICS_SIZE 10
#define MAX_LENGTH 255

const char *topics[TOPICS_SIZE] = {"animations", "animals", "cars", "cities", "games",
"history", "landscapes", "movies", "space", "sports"};

int rand_indexes[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct puzzle_t
{
    int pieces;
    int topic_index;
    char topic[MAX_LENGTH];
    char title[MAX_LENGTH];
};

struct node_t
{
    struct puzzle_t puzzle;
    struct node_t *next;
};

struct puzzle_t create()
{
    struct puzzle_t puzzle;
    int random;
    do
    {
        random = rand()%TOPICS_SIZE;
    }
    while(rand_indexes[random]);

    rand_indexes[random] = 1;
    puzzle.topic_index = random;
    strcpy(puzzle.topic, topics[random]);

    return puzzle;
}

void fill_puzzle_params(struct puzzle_t *puzzle)
{
    printf("Puzzle Topic = %s\n", puzzle->topic);
    printf("What is the title of the puzzle? \n");
    scanf(" %[^\n]%*c", puzzle->title);
    printf("How many pieces should the puzzle have? \n");
    scanf("%d", &puzzle->pieces);
}

void bubbleSort(struct node_t *start)
{
    int swapped;
    struct node_t *ptr;
    struct node_t *ptr2 = NULL;
    do
    {
        swapped = 0;
        ptr = start;

        while (ptr->next != ptr2)
        {
            if (strcmp(ptr->puzzle.topic, ptr->next->puzzle.topic) > 0)
            {
                struct puzzle_t temp = ptr->puzzle;
                ptr->puzzle = ptr->next->puzzle;
                ptr->next->puzzle = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        ptr2 = ptr;
    }
    while (swapped);
}

void show_puzzles(struct node_t *head)
{
    while(head != NULL)
    {
        printf("%d %s %s\n", head->puzzle.pieces, head->puzzle.topic, head->puzzle.title);
        head=head->next;
    }
}

int main()
{
    srand(time(0));
    int used_topics[TOPICS_SIZE];
    for(int i=0;i<TOPICS_SIZE;i++)
    {
        used_topics[i] = 0;
    }
    struct node_t *head = (struct node_t*)malloc(sizeof(struct node_t));
    head->puzzle = create();
    head->next = NULL;
    used_topics[head->puzzle.topic_index] = 1;
    struct node_t *current = head;
    for(int i=0;i<TOPICS_SIZE-1;i++)
    {
        struct node_t *nextptr = (struct node_t*)malloc(sizeof(struct node_t));
        nextptr->puzzle = create();
        if(used_topics[nextptr->puzzle.topic_index] == 1)
        {
            break;
        }
        used_topics[nextptr->puzzle.topic_index] = 1;
        nextptr->next = NULL;
        current->next = nextptr;
        current = nextptr;
    }

    struct node_t *ptr = head;
    while(ptr!=NULL)
    {
        fill_puzzle_params(&ptr->puzzle);
        ptr = ptr->next;
    }

    bubbleSort(head);

    show_puzzles(head);

    while(head != NULL)
    {
        head=head->next;
        free(head);
    }

    return 0;
}
