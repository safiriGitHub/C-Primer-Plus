/* 3.编写一个程序，读取整数直到用户输入 0。输入结束后，程序应报告 
用户输入的偶数（不包括 0）个数、这些偶数的平均值、输入的奇数个数及 
其奇数的平均值。 */

#include <stdio.h>

int main(void)
{
    int num = 0;
    int odd_sum = 0;
    int even_sum = 0;
    int odd_count = 0;
    int even_count = 0;

    printf("输入整数数字：");
    while (scanf("%d", &num) == 1)
    {
        if (num == 0)
            break;
        if (num % 2 == 0)
        {
            even_count++;
            even_sum += num;
        }
        else
        {
            odd_count++;
            odd_sum += num;
        }
    }
    printf("偶数个数%d,偶数平均数%g\n", even_count, 1.0*even_sum/even_count);
    printf("奇数个数%d,奇数平均数%g\n", odd_count, 1.0*odd_sum/odd_count);
    
    return 0;
}
