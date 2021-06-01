// power.c -- 计算数的整数幂

#include <stdio.h>
double power(double n, int p); //前置声明

int main(void) {
    double x, xpow;
    int exp;
    printf("输入一个数字和正整数的幂");
    printf("输入q退出\n");

    while (scanf("%lf,%d", &x, &exp) == 2)
    {
        xpow = power(x, exp); 
        printf("%.3g 的 %d 次方为 %.5g\n", x, exp, xpow);
        printf("输入另一对数据或q退出");
    }
    printf("谢谢使用，再见");
    return 0;
    
}

double power(double n, int p) {
    double pow = 1;
    for (size_t i = 1; i <= p; i++)
    {
        pow *= n;
    }
    return pow;
    
}