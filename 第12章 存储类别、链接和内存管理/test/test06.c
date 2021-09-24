/* 
6.编写一个程序，生成1000个1～10范围内的随机数。不用保存或打印 
这些数字，仅打印每个数出现的次数。用 10 个不同的种子值运行，生成的 
数字出现的次数是否相同？可以使用本章自定义的函数或ANSI C的rand()和 
srand()函数，它们的格式相同。这是一个测试特定随机数生成器随机性的方 法。
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10
#define LENGTH 1000

int main(void)
{
    int num[SIZE+1] = {0};
    int num_i;

    for (int i = 1; i <= 10; i++)
    {
        srand((unsigned int)time(0));
        // srand(i);

        for (int k = 0; k < LENGTH; k++)
        {
            num_i = rand()%10 + 1;
            num[num_i]++;
        }
        printf("No.%d生成的数字出现的次数:---------\n", i);
        for (int j = 1; j <= SIZE; j++)
        {
            printf("%d -- %d次\n", j, num[j]);
        }
    }
    
    return 0;
}