#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car_t
{
    char brand[16];
    char model[21];
    int horse_power;
};

struct car_t create_car()
{
    struct car_t vehicle;
    printf("Car Brand= ");
    scanf("%s", vehicle.brand);
    printf("Car Model= ");
    scanf("%s", vehicle.model);
    printf("Car Horse Power= \n");
    int hp;
    scanf("%d", &hp);
    vehicle.horse_power=hp;

    return vehicle;
}

int is_special(struct car_t car)
{

    if(car.model=="ambulance" || car.horse_power>500)
    {
        return 1;
    }
    return 0;
}

int main()
{
    struct car_t input_car = create_car();

    //printf("%d\n", create_car());
    printf("%d\n", is_special(input_car));

    return 0;
}
