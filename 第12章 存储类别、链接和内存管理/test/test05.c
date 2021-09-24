/* 
5.编写一个程序，生成100个1～10范围内的随机数，并以降序排列（可 
以把第11章的排序算法稍加改动，便可用于整数排序，这里仅对整数排 序）。
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
void sort(int array[], int len);

int main(void)
{
    int source[SIZE];
    srand((unsigned int)time(0));
    for (int i = 0; i < SIZE; i++)
        source[i] = rand()%10 + 1;
    puts("before:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%4d", source[i]);
        if ((i+1)%10 == 0)
            putchar('\n');
    }
    printf("\n");
    sort(source, SIZE);
    puts("after:");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%4d", source[i]);
        if ((i+1)%10 == 0)
            putchar('\n');
    }
    printf("\n");
    return 0;
}

void sort(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (array[i] < array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}