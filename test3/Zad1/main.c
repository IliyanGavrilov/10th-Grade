#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct garage_t
{
    int arr[100];
    char name[20];
    int price;
};

void enter_garage(struct garage_t* garages, int size, int size_g)
{
    struct garage_t *tmp = malloc(sizeof(garages)*(size_g+1));
    struct garage_t *new_garage = malloc(sizeof(garages));

    printf("Name = ");
    scanf("%s", new_garage->name);

    for(int i = 0; i < size; i++)
    {
        printf("\nPlate(0001 - 9999) = ");
        scanf("%d", &new_garage->arr[i]);

    }
    for(int i = 0; i < size;i++)
    {
        for(int j = 0; j < 100; j++)
        {
            tmp[i].arr[j] = garages[i].arr[j];
        }
        strcpy(tmp[i].name, garages[i].name);
        tmp[i].price = garages[i].price;
    }
    free(garages);
    garages = tmp;
}

struct garage_t* find_garage(struct garage_t* garages,int size, short* numbers, int numbers_size, int size_g)
{
    for(int i = 0;i<size_g;i++)
    {
        int yes=0;
        for(int j = 0;j<size;j++)
        {
            for(int k = 0;k<numbers_size;k++)
            {
                if(garages[i].arr[j] == numbers[k])
                {
                    yes++;
                }
            }
        }
        if(yes==numbers_size)
        {
            return &garages[i];
        }
    }
    return NULL;
}

int main()
{
    int size;
    int size_g=0;
    short numbers[] = {1234, 5678, 1235};
    int numbers_size = 3;

    printf("How many cars? ");
    scanf("%d", &size);

    struct garage_t *arr = malloc(sizeof(struct garage_t));


    enter_garage(arr, size, size_g);
    find_garage(arr, size, numbers, numbers_size, size_g);

    return 0;
}
