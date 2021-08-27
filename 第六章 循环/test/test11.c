/* 11.编写一个程序，在数组中读入8个整数，然后按倒序打印这8个整 数。 */

#include <stdio.h>

int main(void)
{
    int array[8];
    printf("请输入8个整数：");
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", array[i]);
    }
    

    return 0;
}