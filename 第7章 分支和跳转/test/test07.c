/* 7.编写一个程序，提示用户输入一周工作的小时数，然后打印工资总 
额、税金和净收入。做如下假设： 
a.基本工资 = 1000美元/小时 
b.加班（超过40小时） = 1.5倍的时间 
c.税率： 前300美元为15% 
续150美元为20% 
余下的为25% 
用#define定义符号常量。不用在意是否符合当前的税法。
*/

#include <stdio.h>

#define SALARY 1000
#define OVER_SALARY 1.5*SALARY
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25

int main(void)
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
        salary_sum = SALARY*40 + OVER_SALARY*(work_hour-40);
    }
    else
    {
        salary_sum = SALARY*work_hour;
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
    

    printf("一周工作%d小时,总工资为%d$,扣税%.2f$,税后工资%.2f$", 
        work_hour, salary_sum, rate_sum, salary_sum-rate_sum);
    return 0;
}