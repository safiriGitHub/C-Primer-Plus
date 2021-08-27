/* 17.Chuckie Lucky赢得了100万美元（税后），他把奖金存入年利率8%的 
账户。在每年的最后一天， Chuckie取出10万美元。编写一个程序，计算多 
少年后Chuckie会取完账户的钱？ */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double lucky = 1000000;
    double lucky_reduce = 100000;
    double lucky_grow = 0.08;
    double lucky_num;
    int year = 1;
    printf("year\tlucky_num\t\n");
    
    // lucky_num = lucky * pow((1+lucky_grow), year);
    lucky_num = lucky * (1+lucky_grow);
    while (lucky_num >= 0)
    {
        lucky_num -= lucky_reduce;
        printf("%d\t%.2lf\n", year, lucky_num);
        lucky_num = lucky_num * (1+lucky_grow);
        year++;
    }
    
    return 0;
}
