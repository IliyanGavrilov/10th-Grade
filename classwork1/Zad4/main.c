#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *arr)
{
    int j=1;
    int size=strlen(arr);
    char a;
    for(int i=0;i<size/2;i++)
    {
        a=arr[i];
        arr[i]=arr[size-j];
        arr[size-j]=a;
        j++;
    }
    for(int i=0;i<size;i++)
    {
        printf("%c", arr[i]);
    }

}

int main()
{
    char str[] = "asd"; //dsa

    reverse(str);

    return 0;
}
