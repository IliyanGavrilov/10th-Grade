#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_punctuation(char str[])
{
    int count=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='.' || str[i] == ',' || str[i] == '-')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char str[] = {"he--o"};
    char str2[] = {"my n,m,"};
    char str3[] = {".s p-t,r"};

    printf("%d\n", count_punctuation(str));
    printf("%d\n", count_punctuation(str2));
    printf("%d\n", count_punctuation(str3));

    return 0;
}
