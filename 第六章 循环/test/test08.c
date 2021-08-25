/* 8.编写一个程序，要求用户输入两个浮点数，并打印两数之差除以两数 
乘积的结果。在用户输入非数字之前，程序应循环处理用户输入的每对值。 */

#include <stdio.h>

int main(void)
{
    double a, b;
    printf("输入两个数，以逗号间隔 :");
    while (scanf("%lf,%lf", &a, &b) != 0)
    {
        printf("(%g-%g)/(%g*%g) is %.3f", a, b, a, b, (a-b)/(a*b));
        printf("输入两个数，以逗号间隔 :");
    }
    

    return 0;
}