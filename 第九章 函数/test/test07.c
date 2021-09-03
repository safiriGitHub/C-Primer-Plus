/* 
7.编写一个函数，从标准输入中读取字符，直到遇到文件结尾。程序要 
报告每个字符是否是字母。如果是，还要报告该字母在字母表中的数值位 
置。例如，c和C在字母表中的位置都是3。合并一个函数，以一个字符作为
参数，如果该字符是一个字母则返回一个数值位置，否则返回-1。
 */

#include <stdio.h>
#include <ctype.h>

int check(char ch);
int main(void)
{
    char ch;

    printf("输入一个字母：");
    while ((ch = getchar()) != EOF)
    {
        if (ch != '\n')
        {
            int loca = check(ch) + 1;
            printf("%c在字母表中的位置为%d\n", ch, loca);
            printf("输入一个字母：");
        }
    }
    
    return 0;
}

int check(char ch)
{
    if (isalpha(ch))
    {
        if (islower(ch))
            return ch - 'a';
        else
            return ch - 'A';
    }
    return -1;
}

