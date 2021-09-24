/* 6.编写一个程序打印一个表格，每一行打印一个整数、该数的平方、该 
数的立方。要求用户输入表格的上下限。使用一个for循环。 */

#include <stdio.h>
int main(void)
{
    int start, end;
    printf("输入下限:");
    scanf("%d", &start);
    printf("输入上限:");
    scanf("%d", &end);
    printf("数\t平方\t立方\n");
    for (int i = start; i <= end; i++)
    {
        printf("%-6d\t%-6d\t%-6d\n", i, i*i, i*i*i);
    }
    return 0;
}