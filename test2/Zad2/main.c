#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mouse_t
{
    char brand[16];
    char model[16];
    char description[257];
    int price;
};

int validate(struct mouse_t* mouse)
{
    int c_size=strlen(mouse->description);
    for(int i=0;i<c_size;i++)
    {
        if(!(mouse->description[i] == ' ' ||
          (mouse->description[i] >= '0' && mouse->description[i] <= '9') ||
           (mouse->description[i] >= 'a' && mouse->description[i] <= 'z')))
        {
            return 0;
        }
    }
    if(mouse->price <= 0)
    {
        return 0;
    }
    else if(!strcmp(mouse->brand, "") ||
            !strcmp(mouse->model, "") )
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

int main()
{
    struct mouse_t mouse = {"Logitech", "G Pro", "gaming mouse", 120};

    printf("%d", validate(&mouse));

    return 0;
}
