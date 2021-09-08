/* 
6.编写一个函数，把double类型数组中的数据倒序排列，并在一个简单 的程序中测试该函数。
 */

#include <stdio.h>

void sort_asc(double array[], int row);
int main(void)
{
    double s[] = {3.3, 5.6, 8.2, 1.2, 3.4, 8.8};
    sort_asc(s, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%.2lf,", s[i]);
    }
    
    return 0;
}

void sort_asc(double array[], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i+1; j < row; j++)
        {
            if (array[i] < array[j])
            {
                double temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}