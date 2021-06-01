/*使用指针表示法*/

#include <stdio.h>
#define MONTHS 12

int main(void) 
{
    int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int index;

    for (index = 0; index < MONTHS; index++)
        printf("%2d月有%2d天\n", index + 1, *(days+index)); //1
    return 0;
}

/*1
days是数组首元素的地址，days + index是元素days[index]的地 址，
而*(days + index)则是该元素的值，相当于days[index]
*/
