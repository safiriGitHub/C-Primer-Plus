/* 
5.编写一个函数，返回储存在double类型数组中最大值和最小值的差 值，并在一个简单的程序中测试该函数。
 */

#include <stdio.h>

double max_min_x(double array[], int row);
int main(void)
{
    double mmx = max_min_x((double []){2.2,3.2,3.3,4.5,6.6}, 5);
    printf("mmx = %lf", mmx);
    return 0;
}

double max_min_x(double array[], int row)
{
    double max = array[0];
    double min = array[0];
    for (int i = 1; i < row; i++)
    {
        if (array[i] > max) 
        {
            max = array[i];
        }
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return max - min;    
}