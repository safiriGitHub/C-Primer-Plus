/* 
3.编写一个函数，返回储存在int类型数组中的最大值，并在一个简单的 程序中测试该函数。
 */

#include <stdio.h>

int arr_max(int arr[], int row);
int main(void)
{
    int test1[] = {1,2,5,7,21,2,65,3};
    int test1_r = arr_max(test1, sizeof(test1)/sizeof(test1[0]));
    printf("test1_r : %d\n", test1_r);

    int test2_r = arr_max((int[]){1,2,5,7,21,2,65,3}, 8);
    printf("test2_r : %d\n", test2_r);
    return 0;
}

int arr_max(int arr[], int row)
{
    int temp = arr[0];
    for (int i = 1; i < row; i++)
    {
        if (temp < arr[i])
        {
            temp = arr[i];
        }
    }
    return temp;        
}