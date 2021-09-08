/* 
4.编写一个函数，返回储存在double类型数组中最大值的下标，并在一 个简单的程序中测试该函数。
 */
#include <stdio.h>

int max_arr_i(double array[], int row);

int main(void)
{

    int max_i = max_arr_i((double []){8.8, 93.2, 2, 3, 335.1 ,2, 3}, 7);
    printf("max_i = %d\n", max_i);
    return 0;
}

int max_arr_i(double array[], int row)
{
    double temp = array[0];
    double max_i = 0;
    for (int i = 1; i < row; i++)
    {
        if (temp < array[i])
        {
            temp = array[i];
            max_i = i;
        }
    }
    return max_i;    
}