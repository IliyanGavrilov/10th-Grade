#include <stdio.h>
#include <stdlib.h>

int size(char str[])
{
    int size=0;
    for(int i=0;str[i]!='\0';i++)
    {
        size++;
    }
    return size;
}

int str_cmp(char *str1,char *str2)
{
    if(size(str1)>size(str2))
    {
        return 1;
    }
    else if(size(str1)==size(str2))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

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
}

int palindrome(char *arr)
{
    int size=strlen(arr);
    char arr2[size/2+1];
    int j=;
    for(int i=0;i<size/2+1;i++)
    {
        arr2[j]=arr[j];
        j++;
    }
    for(int i=0;i<size/2;i++)
    {
        printf("%c", arr2[i]);
    }

}

int main()
{
    char arr[] = "asa";

    printf("%d", palindrome(arr));

    return 0;
}
