/* day_mon1.c -- 打印每个月的天数*/

#include <stdio.h>
#define MONTHS 12

int main(void)
{
    // 创建只读数组，应该用const声明和初始化数组
    const int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;
    for (index = 0; index < MONTHS; index++)
    {
        printf("%2d月有%2d天。\n", index+1, days[index]);
    }
    return 0;
}