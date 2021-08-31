/* 8.修改练习7的假设a，让程序可以给出一个供选择的工资等级菜单。使 
用switch完成工资等级选择。运行程序后，显示的菜单应该类似这样：
 ***************************************************************** 
 Enter the number corresponding to the desired pay rate or action: 
 1) $8.75/hr 2) $9.33/hr 
 3) $10.00/hr 4) $11.20/hr
5) quit 
***************************************************************** 
如果选择 1～4 其中的一个数字，程序应该询问用户工作的小时数。程 
序要通过循环运行，除非用户输入 5。如果输入 1～5 以外的数字，程序应 
提醒用户输入正确的选项，然后再重复显示菜单提示用户输入。使用#define 
创建符号常量表示各工资等级和税率。 */

#include <stdio.h>
#include <stdbool.h>

int caculate_salaty(double salary_hour);

int main(void)
{
    int selected = 0;
    double salary_hour = 0.0;
    bool quit = false;
    do
    {
        printf("Enter the number corresponding to the desired pay rate or action: \n");
        printf("1) $8.75/hr 2) $9.33/hr \n"
        "3) $10.00/hr 4) $11.20/hr \n"
        "5) quit\n");
        scanf("%d", &selected);
        switch (selected)
        {
        case 1:
            salary_hour = 8.75;
            break;
        case 2:
            salary_hour = 9.33;
            break;
        case 3:
            salary_hour = 10.00;
            break;
        case 4:
            salary_hour = 11.20;
            break;
        case 5:
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