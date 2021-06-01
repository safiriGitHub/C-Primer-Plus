/* rain.c -- 计算每年的总降水量、年平均降水量和5年中每月的平均降 水量 */ 

#include <stdio.h>

#define MONTHS 12 
#define YEARS 5

int main(void)
{
    const float rain[YEARS][MONTHS] = 
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 }, 
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 }, 
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 }, 
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 }, 
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };

    int year, month;
    float subtot, total;
    printf(" YEAR RAINFALL (inches)\n");
    
    for (year = 0, total = 0; year < YEARS; year++)
    {
        //每一年， 各月的降水量总和
        for (month = 0, subtot = 0; month < MONTHS; month++)
            subtot += rain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot; //5年总降水量
    }
    
    printf("年均降水量%.1f\n", total/YEARS);
    printf("月均降水量:\n\n");
    printf("一月 二月 三月 四月 五月 六月 七月 八月 九月 十月 十一月 十二月 \n");
    for (month = 0; month < MONTHS; month ++) 
    {
        //每个月，5年的总降水量
        for (year = 0, subtot = 0; year < YEARS; year++)
        {
            subtot += rain[year][month];
        }
        printf("%4.1f ", subtot / YEARS);
    }
    printf("\n");
    return 0;
}

