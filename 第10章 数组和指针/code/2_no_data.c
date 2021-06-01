/* no_data.c -- 未初始化数组*/

#include <stdio.h>
#define SIZE 4

int main(void)
{
    int no_data[SIZE]; //未初始化数组
    printf("%2s%14s\n", "i", "no_data[i]");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%2d%14d\n", i, no_data[i]); 
        // 使用数组前必须先初始化它。在使用数组元素之前， 必须先给它们赋初值。
        // 编译器使用的值是内存相应位置上的现有值
    }
    return 0;
}