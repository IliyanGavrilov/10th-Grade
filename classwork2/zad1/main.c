#include <stdio.h>
#include <stdlib.h>

struct circle_t
{
    float r;
    float x;
    float y;
};

float circumference(struct circle_t c1)
{
    float c=0;
    c=6.28*c1.r;
    return c;
}

float area(struct circle_t c1)
{
    float s=0;
    s=c1.r*c1.r*3.14;
    return s;
}

void quadrant(struct circle_t c1)
{
    float min=0.000001;
    if(c1.x+c1.r>=min && c1.y+c1.r>=min)
    {
        printf("1\n");
    }
    if(c1.x-c1.r<=-min && c1.y-c1.r<=-min)
    {
        printf("3\n");
    }
    if(c1.x-c1.r<=-min && c1.y+c1.r>=min)
    {
        printf("2\n");
    }
    if(c1.x+c1.r>=min && c1.y-c1.r<=-min)
    {
        printf("4\n");
    }
    /*Sravnqvam krainite tochki s nai-malkata
    vyzmojna tochka ot vseki kvadrant.*/
}

int main()
{
    struct circle_t c1 = {2,0,0};

    printf("%f\n", circumference(c1));
    printf("%f\n", area(c1));
    quadrant(c1);

    return 0;
}
