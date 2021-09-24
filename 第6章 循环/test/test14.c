/* 14.编写一个程序，创建两个包含8个元素的double类型数组，使用循环 
提示用户为第一个数组输入8 个值。第二个数组元素的值设置为第一个数组 
对应元素的累积之和。例如，第二个数组的第 4个元素的值是第一个数组前 
4个元素之和，第二个数组的第5个元素的值是第一个数组前5个元素之和 
（用嵌套循环可以完成，但是利用第二个数组的第5个元素是第二个数组的 
第4个元素与第一个数组的第5个元素之和，只用一个循环就能完成任务，不 
需要使用嵌套循环）。最后，使用循环显示两个数组的内容，第一个数组显 
示成一行，第二个数组显示在第一个数组的下一行，而且每个元素都与第一 
个数组各元素相对应。 */

#include <stdio.h>

int main(void)
{
    double arr1[8], arr2[8];
    double sum;
    printf("输入8个值：");
    for (int i = 0; i < 8; i++)
    {
        scanf("%lf", &arr1[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += arr1[j];
        }
        arr2[i] = sum;
    }
    printf("First array datas:");
    for (int i = 0; i < 8; i++)
    {
        printf("%g ",arr1[i]);
    }
    printf("\nSecond array datas:");
    for (int i = 0; i < 8; i++)
    {
        printf("%g ",arr2[i]);
    }

    return 0;
}