/* 
4.两数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数 
的平均值，最后取计算结果的倒数。编写一个函数，接受两个double类型的 
参数，返回这两个参数的调和平均数。
 */

#include <stdio.h>

double tiaohe(double a, double b);

int main(void)
{
    printf("%lf\n", tiaohe(2.0, 2.0));
    printf("%lf\n", tiaohe(2.0, 3.0));
    printf("%lf\n", tiaohe(2.0, 4.0));
    return 0;
}

double tiaohe(double a, double b)
{
    double da = 0.0;
    double db = 0.0;
    double sum = 0.0;
    double result = 0.0;

    if (a == 0)
        da = 0.0;
    else if (b == 0)
        db = 0.0;
    else
    {
        da = 1/a;
        db = 1/b;
    }
    sum = (da + db) / 2.0;
    result = 1 / sum;
    return result;
}


