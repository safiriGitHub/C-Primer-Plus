/* 9.修改练习8，使用一个函数返回计算的结果。 */
#include <stdio.h>

double caculate(double a, double b);

int main(void)
{
    double a, b;
    printf("输入两个数，以逗号间隔 :");
    while (scanf("%lf,%lf", &a, &b) != 0)
    {
        printf("(%g-%g)/(%g*%g) is %.3f\n", a, b, a, b, caculate(a, b));
        printf("输入两个数，以逗号间隔 :");
    }
    
    return 0;
}

double caculate(double a, double b)
{
    return (a-b)/(a*b);
}