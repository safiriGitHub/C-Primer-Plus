/*designate.c -- 使用指定初始化器*/

#include <stdio.h>
#define MONTHS 12

int main(void)
{
    int days[MONTHS] = { 31, 28, [4] = 31, 30, 31, [1] = 29}; //1
    for (short i = 0; i < MONTHS; i++)
    {
        printf("%2d  %d\n", i + 1, days[i]);
    }
    return 0;
}
/*
1  31
 2  29
 3  0
 4  0
 5  31
 6  30
 7  31
 8  0
 9  0
10  0
*/
/*1
[4] = 31,30,31，在days[4]被初 始化为31后，days[5]和days[6]将分别被初始化为30和31

再次初 始化指定的元素，那么最后的初始化将会取代之前的初始化
[1] = 29  days[1]28被修改为了29
*/

