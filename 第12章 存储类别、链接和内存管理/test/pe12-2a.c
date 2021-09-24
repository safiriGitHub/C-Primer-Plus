
#include "pe12-2a.h" 
#include <stdio.h>

static int sel_mode;
static float kilometers = 0.0;
static float fuel_consumed = 0.0;
void set_mode(int mode)
{
    sel_mode = mode;
}

void get_info()
{
    if (sel_mode == 0) //以升/100 公里来计算。
    {
        printf("Enter distance traveled in kilometers:");
        scanf("%f", &kilometers);
        printf("Enter fuel consumed in liters:");
        scanf("%f", &fuel_consumed);
        if (kilometers <= 0 || fuel_consumed <= 0)
        {
            printf("输入数据有误");
            get_info();
        }
    }
    else if (sel_mode == 1) //以英里/加仑来计算油耗；
    {
        printf("Enter distance traveled in miles:");
        scanf("%f", &kilometers);
        printf("Enter fuel consumed in gallons:");
        scanf("%f", &fuel_consumed);
        if (kilometers <= 0 || fuel_consumed <= 0)
        {
            printf("输入数据有误");
            get_info();
        }
    }
    
}

void show_info()
{
    if (sel_mode == 0)
        printf("Fuel consumption is %.2f liters per 100 km. \n", fuel_consumed/kilometers*100);
    else if (sel_mode == 1)
        printf("Fuel consumption is %.2f liters per 100 km. \n", kilometers/fuel_consumed);
}