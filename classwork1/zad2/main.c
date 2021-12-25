#include <stdio.h>
#include <stdlib.h>

void avrg(float *arr, int size, float *avrg_arr)
{
    for(int i=0;i<size;i++)
    {
        *avrg_arr+=*(arr+i);
    }
    *avrg_arr=*avrg_arr/size;

}

int main()
{
    float arr[] = {1.0,2.0,3.0,4.0};
    float a=0;

    avrg(arr,4,&a);
    printf("%.2f", a);

    return 0;
}
