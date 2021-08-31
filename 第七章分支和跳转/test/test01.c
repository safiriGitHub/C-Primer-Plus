/* 1.编写一个程序读取输入，读到#字符停止，然后报告读取的空格数、 
换行符数和所有其他字符的数量。 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int space_num = 0;
    int eline_num = 0;
    int other_num = 0;
    char ch;
    printf("输入文字，#结束:");
    while ((ch = getchar()) != '#')
    {
        if (!isgraph(ch)) // isgraph除空格之外的可打印字符
        {
            space_num++;
        }else {
            if (ch == '\n')
            {
                eline_num++;
            }
            else {
                other_num++;
            }
        }
    }
    printf("空格符%d个\n换行符%d个\n其他字符%d个\n", space_num, eline_num, other_num);
    return 0;
}