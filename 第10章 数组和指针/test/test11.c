/* 
11.编写一个程序，声明一个int类型的3×5二维数组，并用合适的值初始 
化它。该程序打印数组中的值，然后各值翻倍（即是原值的2倍），并显示 
出各元素的新值。编写一个函数显示数组的内容，再编写一个函数把各元素 
的值翻倍。这两个函数都以函数名和行数作为参数。
 */

#include <stdio.h>

void show_2d_array(int row, int col, int array[row][col]);
void up_2d_array(int row, int col, int array[row][col]);
int main(void)
{
    int a[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
    show_2d_array(3, 5, a);
    up_2d_array(3, 5, a);
    show_2d_array(3, 5, a);
    return 0;
}

void up_2d_array(int row, int col, int array[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] *= 2; 
        }
    }
}
void show_2d_array(int row, int col, int array[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
