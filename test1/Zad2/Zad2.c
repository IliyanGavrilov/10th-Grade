#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float avrg_min_max(int numbers[], int count)
{
    int max=numbers[0];
    int min=numbers[0];
    float avr=0;

    for(int i=0;i<count;i++)
    {
        if(max<numbers[i])
        {
            max=numbers[i];
        }
        if(min>numbers[i])
        {
            min=numbers[i];
        }
    }

    avr=(min+max)/2;

    return avr;
}

int main()
{
    int numbers[] = {-4, 9, 1, 10, 7, 5};
    int count=strlen(numbers);

    printf("%.2f", avrg_min_max(numbers,count));

    return 0;
}
