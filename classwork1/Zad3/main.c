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

int main()
{
    char str1[] = "ab";
    char str2[] = "a";

    printf("%d", str_cmp(str1,str2));

    return 0;
}
