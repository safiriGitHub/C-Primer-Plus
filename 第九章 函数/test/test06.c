
/* 
6.编写并测试一个函数，该函数以3个double变量的地址作为参数，把最 
小值放入第1个变量，中间值放入第2个变量，最大值放入第3个变量。
 */
#include <stdio.h>

void test(double *i, double *j, double *k);

int main(void)
{
    double i = 55;
    double j = 33;
    double k = 21;
    test(&i, &k, &j);
    printf("%lf,%lf,%lf", i, k, j);
    return 0;
}

void test(double *i, double *j, double *k)
{ 
    double temp;
    if (*i > *j)
    {
        temp = *i;
        *i = *j;
        *j = temp;
    }
    if (*i > *k)
    {
        temp = *i;
        *i = *k;
        *k = temp;
    }
    if (*j > *k)
    {
        temp = *j;
        *j = *k;
        *k = temp;
    }  
}
