/*3.编写一个程序，提示用户输入天数，然后将其转换成周数和天数。
例 如，用户输入18，则转换成2周4天。以下面的格式显示结果： 
18 days are 2 weeks, 4 days. 
通过while循环让用户重复输入天数，当用户输入一个非正值时（如0 或-20），循环结束。*/

#include <stdio.h>

#define DAY_TO_WEEK 7
int main(void)
{
    int temp;
    int day;
    int week;
    printf("Enter the number of days(<= 0 to quit):");
    scanf("%d", &temp);
    while (0 < temp)
    {
        week = temp / DAY_TO_WEEK;
        day = temp % DAY_TO_WEEK;
        printf("%d days are %d weeks, %d days\n", temp, week, day);
        printf("Enter the number of days(<= 0 to quit):");
        scanf("%d", &temp);
    }
    

}