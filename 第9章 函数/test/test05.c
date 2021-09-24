/* 
5.编写并测试一个函数larger_of()，该函数把两个double类型变量的值替 
换为较大的值。例如， larger_of(x, y)会把x和y中较大的值重新赋给两个变 量。
 */

#include <stdio.h>

void larger_of(double *a, double *b);
int main(void)
{
    double a = 2;
    double b = 3;
    larger_of(&a, &b);
    printf("a = %lf, b = %lf", a, b);
    return 0;
}

void larger_of(double *a, double *b)
{
    if (*a > *b)
        *b = *a;
    else
        *a = *b;
}