/* 
9.使用递归函数重写编程练习8。
 */

#include <stdio.h>

double power(double n, int p);

int main(void)
{
    double x, xpow;
    int exp;

    while (scanf("%lf %d", &x, &exp) == 2)
    {
        xpow = power(x, exp);
        printf("%.3g to power %d is %.5g\n", x, exp, xpow);
        printf("Enter the next pair of numbers of q to quit.\n");
    }
    return 0;
}

double power(double n, int p)
{
    double pow = 1;
    if (n == 0 && p == 0)
    {
        printf("%g to the power %d is not define, return -1!\n", n, p);
		return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (p == 0)
    {
        return 1;
    }
    if (p > 0)
    {
        return n * power(n, p-1);
    }
    else
    {
        return power(n, p+1)/n;
    }
}
