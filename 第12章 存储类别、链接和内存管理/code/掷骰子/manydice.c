/* manydice.c -- 多次掷骰子的模拟程序 */
/* 与 diceroll.c 一起编译*/

#include <stdio.h>
#include <stdlib.h> //为库函数srand()提供原型
#include <time.h>   //为time() 提供原型
#include "diceroll.h" // 为roll_n_dice() 提供原型, 为 roll_count 变量提供声明

int main(void)
{
    int dice, roll;
    int sides;
    int status;

    srand((unsigned int)time(0)); // 随机种子 所以大多数情况下，即使输入相同也很难得到相同的输出。
    printf("输入每个骰子的面数，0表示停止。\n");
    while (scanf("%d", &sides) == 1 && sides > 0)
    {
        printf("要掷骰子多少次？\n");
        if ((status = scanf("%d", &dice)) != 1)
        {
            if (status == EOF)
                break; //退出循环
            else
            {
                printf("您应该输入一个整数。");
                printf(" 让我们重新开始\n");
                while (getchar() != '\n')
                    continue; /* 处理错误的输入 */
                printf("输入每个骰子的面数，0表示停止。\n");
                continue; /* 进入循环的下一轮迭代 */
            }
        }
        roll = roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sided dice.\n", roll, dice, sides);
        printf("输入每个骰子的面数，0表示停止。\n");
    }
    printf("The rollem() function was called %d times.\n", roll_count); /* 使用外部变量 */
    printf("GOOD FORTUNE TO YOU!\n"); 
    return 0;
}