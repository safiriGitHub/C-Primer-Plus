/* some_data.c -- 部分初始化数组*/ 
#include <stdio.h>
#define SIZE 4

int main(void) 
{
    int some_data[SIZE] = {1492, 1066};
    int i;
    printf("%2s%14s\n", "i", "some_data[i]");
    for (i = 0; i < SIZE; i++)
    {
        printf("%2d%14d\n", i, some_data[i]);
    }
    return 0;
}
/*
 i  some_data[i]
 0          1492
 1          1066
 2             0
 3             0
*/
//当初始化列表中的值少于数组元素个数 时，编译器会把剩余的元素都初始化为0。
//如果初始化列表的项数多于数组元素个数，编译器可没那么仁慈，它会 毫不留情地将其视为错误