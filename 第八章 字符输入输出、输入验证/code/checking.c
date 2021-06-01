// 输入验证

#include <stdio.h>
#include <stdbool.h>

// 验证输入是一个整数
long get_long(void);
// 验证范围的上下限是否有效
bool bad_limits(long begin, long end, long low, long hight);
// 计算a-b之间的整数平方和
double sum_squares(long a, long b);

int main(void) {
    const long MIN = -10000000L; //范围下限
    const long MAX = +10000000L; //范围上限
    long start;                 // 用户指定的范围最小值
    long stop;                  // 用户指定的范围最大值
    double answer;

    printf("这个程序计算给定范围内整数的平方和"
    "(输入0退出)\n"
    "lower limit:");

    start = get_long();
    printf("upper limit: ");
    stop = get_long();
    while (start != 0 || stop != 0)
    {
        if (bad_limits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else
        {
            answer = sum_squares(start, stop);
            printf("%ld-%ld之间整数平方和为%g\n", start, stop, answer);
        }
        printf("再输入一个范围进行计算，\n");
        printf("lower limit: ");
        start = get_long();
        printf("upper limit: ");
        stop = get_long();
    }
    printf("Done.\n");
    return 0;
}

// 验证输入是一个整数
long get_long(void) {
    long input;
    char ch;
    while (scanf("%ld", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch); //处理错误输入
        }
        printf("不是一个整数。\n请输入一个整数，例如25，55，-17等：");
    }
    return input;
}
// 验证范围的上下限是否有效
bool bad_limits(long begin, long end, long low, long hight) {
    bool not_good = false;
    if (begin > end)
    {
        printf("范围开始%ld不能大于范围结束%ld", begin, end);
        not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("小于最小范围%ld了", low);
        not_good = true;
    }
    if (begin > hight || end > hight)
    {
        printf("大于最大范围%ld了", hight);
        not_good = true;
    }
    return not_good;
}
// 计算a-b之间的整数平方和
double sum_squares(long a, long b) {
    double total = 0;
    long i;
    for (i = a; i <= b; i++)
    {
        total += (double)i*(double)i;
    }
    return total;
}