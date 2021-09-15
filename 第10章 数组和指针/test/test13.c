/* 
13.编写一个程序，提示用户输入3组数，每组数包含5个double类型的数 
（假设用户都正确地响应，不会输入非数值数据）。该程序应完成下列任务。
a.把用户输入的数据储存在3×5的数组中 
b.计算每组（5个）数据的平均值 
c.计算所有数据的平均值 
d.找出这15个数据中的最大值 
e.打印结果

每个任务都要用单独的函数来完成（使用传统C处理数组的方式）。完 
成任务b，要编写一个计算并返回一维数组平均值的函数，利用循环调用该 
函数3次。对于处理其他任务的函数，应该把整个数组作为参数，完成任务c 
和d的函数应把结果返回主调函数。
 */

#include <stdio.h>

void input(double a[][5], int row);
void show_2d_array(int row, int col, double array[row][col]);
void row_average(int row, int col, double array[row][col]);

int main(void)
{
    double a[3][5];
    input(a, 3);
    show_2d_array(3, 5, a);
    row_average(3, 5, a);
    return 0;
}

void input(double a[][5], int row)
{
    printf("请输入3组数，每组五个数：\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("输入第%d组%d列:\n", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
}
void show_2d_array(int row, int col, double array[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%lf ", array[i][j]);
        }
        printf("\n");
    }
}

void row_average(int row, int col, double array[row][col])
{
    double all_sum = 0;
    double max = array[0][0];
    for (int i = 0; i < row; i++)
    {
        double sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += array[i][j];
            if (max < array[i][j])
                max = array[i][j];
        }
        printf("第%d组平均数：%lf", i, sum/col);
        all_sum += sum;
    }
    printf("所有数据的平均数：%lf\n", all_sum/(col*row));
    printf("最大值%lf", max);
}