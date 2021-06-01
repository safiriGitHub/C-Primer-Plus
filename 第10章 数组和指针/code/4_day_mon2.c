/* day_mon2.c -- 让编译器计算元素个数*/

#include <stdio.h>
int main(void)
{
    const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31}; //1
    int index;
    for (index = 0; index < sizeof(days) / sizeof(days[0])/*2*/; index++)
        printf("%2d月有%2d天。\n", index+1, days[index]);
    return 0;
}

//1 编译器会根据初始化列表中的 项数来确定数组的大小。

/*2
sizeof运算符给出它的运算对象的大小（以字节为单 位）。
所以sizeof days是整个数组的大小（以字节为单位），
sizeof day[0]是 数组中一个元素的大小（以字节为单位）。
整个数组的大小除以单个元素的 大小就是数组元素的个数。
*/