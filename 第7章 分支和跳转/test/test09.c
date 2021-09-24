/* 9.编写一个程序，只接受正整数输入，然后显示所有小于或等于该数的素数。 */

#include <stdio.h>
#include <stdbool.h>

void cu(unsigned int num);

int main(void)
{   
    unsigned int num;

    printf("输入一个正整数：");
    while (scanf("%u", &num) == 1)
    {
        cu(num);
        printf("输入一个正整数：");
    }
    

    return 0;
}

void cu(unsigned int num)
{
    if (2 > num)
    {
        printf("请输入大于2的数");
    }
    else
    {
        for (int i = 2; i <= num; i++)
        {
            bool is_prime = true;
            for (int k = 2; k <= i/2; k++)
            {
                if (i%k == 0)
                {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime)
            {
                printf("%d\n", i);
            }
        }
    }
}