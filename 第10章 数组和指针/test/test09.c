/* 
9.编写一个程序，初始化一个double类型的3×5二维数组，使用一个处理 
变长数组的函数将其拷贝至另一个二维数组中。还要编写一个以变长数组为 
形参的函数以显示两个数组的内容。这两个函数应该能处理任意N×M数组 
（如果编译器不支持变长数组，就使用传统C函数处理N×5的数组）。
 */

#include <stdio.h>

void copy(int row, int col, double s[row][col], double t[row][col]);
void print(int row, int col, double s[row][col]);
int main(void)
{
    double s[3][5] = {{1.1,1.2,1.3,1.4,1.5},
                        {2.1,2.2,2.3,2.4,2.5},
                        {3.1,3.2,3.3,3.4,3.5}};
    double t[3][5];
    print(3, 5, s);
    copy(3, 5, s, t);
    print(3, 5, t);
    return 0;
}

void copy(int row, int col, double s[row][col], double t[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            t[i][j] = s[i][j];
        }
    }
}
void print(int row, int col, double s[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%lf ", s[i][j]);
        }
        printf("\n");
    }
    
}