#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N=0;

struct poem_t
{
    char title[51];
    char author[21];
    char text[201];
};

struct poem_t* enter_poem()
{
    printf("Enter number of poems: ");
    scanf("%d", &N);
    struct poem_t *p = (struct poem_t*)malloc(sizeof(*p)*N);
    for(int i=0;i<N;i++)
    {
        printf("Enter Title: ");
        scanf("%s", p[i].title);
        printf("Enter Author: ");
        scanf("%s", p[i].author);
        printf("Enter Text: ");
        scanf("%s", p[i].text);
    }
    return p;
}

struct poem_t find_longest(struct poem_t* poems, int length)
{
    int min=0;
    for(int i=1;i<length;i++)
    {
        if(strlen(poems[min].text)>strlen(poems[i].text))
        {
            min=i;
        }
        else if(strlen(poems[min].text)==strlen(poems[i].text))
        {
            if(strlen(poems[min].title)>strlen(poems[i].title))
            {
                min=i;
            }
        }
    }
    return poems[min];
}

int main()
{
    struct poem_t *poems = enter_poem();

    struct poem_t result = find_longest(poems,N);

    printf("Title = %s\n",result.title);
    printf("Author = %s\n",result.author);
    printf("Text = %s\n",result.text);

    return 0;
}
