#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct package_t
{
    char sender_adress[16];
    char receiver_adress[16];
    char content[257];
    int length;
};

int validate(struct package_t* package)
{
    int c_size=strlen(package->content);
    for(int i=0;i<c_size;i++)
    {
        if(!(package->content[i] == ' ' ||
          (package->content[i] >= '0' && package->content[i] <= '9') ||
           (package->content[i] >= 'a' && package->content[i] <= 'z')))
        {
            return 0;
        }
    }
    if(package->length <= 0)
    {
        return 0;
    }
    else if(!strcmp(package->sender_adress, "0.0.0.0") ||
            !strcmp(package->receiver_adress, "0.0.0.0") )
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
    struct package_t package = {"1.0.0.0", "0.0.0.0.1", "aabbss5 ", 1};

    printf("%d", validate(&package));

    return 0;
}
