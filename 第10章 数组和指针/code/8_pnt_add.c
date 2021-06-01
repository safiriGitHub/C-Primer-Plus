/* pnt_add.c -- 指针地址 */

#include <stdio.h>
#define SIZE 4

int main(void)
{
    short dates[SIZE];
    short *pti;
    short index;
    
    double bills[SIZE];
    double *ptf;

    pti = dates; //把数组地址赋值给指针
    ptf = bills;
    printf("%23s    %15s\n", "short", "double");
    for (index = 0; index < SIZE; index++) 
        printf("pointers + %d: %10p  %10p\n", index, pti + index, ptf + index);
    return 0;
}

/*
ex:
                  short             double
pointers + 0: 0x7ffee944c5a0  0x7ffee944c580
pointers + 1: 0x7ffee944c5a2  0x7ffee944c588
pointers + 2: 0x7ffee944c5a4  0x7ffee944c590
pointers + 3: 0x7ffee944c5a6  0x7ffee944c598

short类型占用2字节，double类型占 用8字节
在C中，指针加1指的是增加一个存储单元
*/



