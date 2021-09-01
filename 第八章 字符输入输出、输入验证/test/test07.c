/* 
7.修改第7章的编程练习8，用字符代替数字标记菜单的选项。用q代替5 
作为结束输入的标记。
 */

#include <stdio.h>

#include <stdio.h>
#include <stdbool.h>

int caculate_salaty(double salary_hour);

int main(void)
{
    char selected;
    double salary_hour = 0.0;
    bool quit = false;
    do
    {
        printf("Enter the number corresponding to the desired pay rate or action: \n");
        printf("a) $8.75/hr b) $9.33/hr \n"
        "c) $10.00/hr d) $11.20/hr \n"
        "e) quit\n");
        scanf("%c", &selected);
        switch (selected)
        {
        case 'a':
        case 'A':
            salary_hour = 8.75;
            break;
        case 'b':
        case 'B':
            salary_hour = 9.33;
            break;
        case 'c':
        case 'C':
            salary_hour = 10.00;
            break;
        case 'd':
        case 'D':
            salary_hour = 11.20;
            break;
        case 'e':
        case 'E':
            printf("退出");
            quit = true;
            break;
        default:
            printf("提醒用户输入正确的选项，然后再重复显示菜单提示用户输入\n");
            break;
        }
        if (!quit && salary_hour > 0)
        {
            caculate_salaty(salary_hour);
        }
    } while (!quit);
    
    
    return 0;
}

// #define SALARY 1000
// #define OVER_SALARY 1.5*SALARY
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25

int caculate_salaty(double salary_hour)
{
    int work_hour = 0;
    
    printf("输入一周工作的小时数：");
    scanf("%d", &work_hour);
    if (work_hour <= 0)
    {
        printf("工作时长小于等于0了，不对");
        return 0;
    }
    
    int salary_sum = 0;
    if (work_hour > 40)
    {
        salary_sum = salary_hour*40 + 1.5*salary_hour*(work_hour-40);
    }
    else
    {
        salary_sum = salary_hour*work_hour;
    }
    
    double rate_sum = 0.0;
    if (salary_sum <= 300)
    {
        rate_sum = salary_sum*RATE1;
    }
    else if (salary_sum > 300 && salary_sum <= 450)
    {
        rate_sum = 300*RATE1 + (salary_sum-300)*RATE2;
    }
    else if (salary_sum > 450)
    {
        rate_sum = 300*RATE1 + (450-300)*RATE2 + (salary_sum-450)*RATE3;
    }
    

    printf("一周工作%d小时,总工资为%d$,扣税%.2f$,税后工资%.2f$\n", 
        work_hour, salary_sum, rate_sum, salary_sum-rate_sum);
    return 1;
}
