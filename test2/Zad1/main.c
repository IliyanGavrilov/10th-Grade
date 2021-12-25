#include <stdio.h>
#include <stdlib.h>

unsigned int find_longest(char data[], int length)
{
    int result=0;
    int j=1;
    for(int i=0;i<length;i++)
    {
        if(data[i]==data[i+1])
        {
            j++;
        }
        else
        {
            if(j>result)
            {
                result=j;
            }

            j=1;
        }
    }

    return result;
}

int main()
{
    char a[] = "XMAS";
    char a1[] = "XXMMAASS";
    char a2[] = "XMMAAASSSS";
    char a3[] = "MMASSSXXAA";

    printf("%d\n", find_longest(a,4));
    printf("%d\n", find_longest(a1,8));
    printf("%d\n", find_longest(a2,10));
    printf("%d\n", find_longest(a3,10));

    return 0;
}
