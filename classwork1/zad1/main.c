#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum(int *arr, int size, int *sum_of_arr)
{
    for(int i=0;i<size;i++)
    {
        *sum_of_arr+=*(arr+i);
    }
}

int main()
{
    int arr[] = {1,2,3,4}; //10
    int s=0;

    sum(arr,4,&s);
    printf("%d", s);

    return 0;
}
