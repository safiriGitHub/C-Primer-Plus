/* 
1.设计一个函数min(x, y)，返回两个double类型值的较小值。在一个简单 
的驱动程序中测试该函数。 
 */

#include <stdio.h>

double min(double, double);

int main(void)
{
    printf("%lf\n", min(5,5));
    printf("%lf\n", min(5,6));
    printf("%lf\n", min(4,5));

    return 0;
}

double min(double x, double y)
{
    if (x < y)
        return x;
    else 
        return y;
}