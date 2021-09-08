/* 
7.编写一个程序，初始化一个double类型的二维数组，使用编程练习2中 
的一个拷贝函数把该数组中的数据拷贝至另一个二维数组中（因为二维数组 
是数组的数组，所以可以使用处理一维数组的拷贝函数来处理数组中的每个 
子数组）。
 */

#include <stdio.h>

void copy_arr(double target[], double source[], int row);
void copy_ptr(double *target, double *source, int row);
void printf_2d_arr(int row, int col, double a[][col]);
void copy_2d_arr(int row, int col, double target[row][col], double source[row][col]);

int main(void)
{
    double s[3][3] = {{1.1,1.2,1.3},{2.1,2.2,2.3},{3.1,3.2,3.3}};
    double t[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t[i][j] = s[i][j];
        }
    }
    printf_2d_arr(3, 3, t);
    
    double s2[3][3] = {{1.1,1.2,1.3},{2.1,2.2,2.3},{3.1,3.2,3.3}};
    double t2[3][3];
    copy_2d_arr(3, 3, t2, s2);
    printf_2d_arr(3, 3, t2);


    
    return 0;
}

void copy_arr(double target[], double source[], int row)
{
    for (int i = 0; i < row; i++)
        target[i] = source[i];
}
void copy_ptr(double *target, double *source, int row)
{
    for (int i = 0; i < row; i++)
        *(target+i) = *(source+i);
}

void copy_2d_arr(int row, int col, double target[row][col], double source[row][col])
{
    for (int i = 0; i < row; i++)
    {
        copy_arr(target[i], source[i], col);
    }
}

void copy_2d_arr(int row, int col, double (*target)[col], double (*source)[col])
{
    for (int i = 0; i < row; i++)
        copy_arr(target[i], source[i], col);
}

void printf_2d_arr(int row, int col, double a[][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%5.2lf", a[i][j]);
        }
        printf("\n");
    }
}

