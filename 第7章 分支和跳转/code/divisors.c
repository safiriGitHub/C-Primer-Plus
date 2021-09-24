// divisors.c -- 使用嵌套if语句提示一个数的约数

#include <stdio.h>
#include <stdbool.h>

int main (void) {
    unsigned long num; //待测试的数
    unsigned long div; //可能得约数
    bool isPrime;       // 素数标记

    printf("请输入一个数字进行分析：");
    printf("输入q退出\n");
    while (scanf("%lu", &num) == 1)
    {
        for (div = 2, isPrime = true; (div * div) <= num; div++)
        {
            if (num % div == 0)
            {
                if ((div * div) != num)
                    printf("%lu的约数有 %lu 和 %lu\n", num, div, num/div);
                else 
                    printf("%lu的约数有 %lu\n", num, div);
                
                isPrime = false; //不是素数
            }
        }
        if (isPrime)
            printf("%lu是素数\n", num);
        printf("请输入一个数字进行分析：");
        printf("输入q退出\n");
    }
    printf("bye bye\n");
    return 0;
}
