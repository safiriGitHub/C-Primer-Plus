/* 4.使用if else语句编写一个程序读取输入，读到#停止。用感叹号替换句 
号，用两个感叹号替换原来的感叹号，最后报告进行了多少次替换。 */

#include <stdio.h>

int main(void)
{
    int count = 0;
    char ch;
    while ((ch = getchar()) != '#')
    {
        if (ch == '!')
        {
            printf("!!");
            count++;
        }
        else if (ch == '.')
        {
            printf("!");
            count++;
        }
        else
            printf("%c", ch);
    }
    printf("总共替换了%d次", count);    
    return 0;
}