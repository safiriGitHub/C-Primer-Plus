/* 
10.编写一个函数接受一个字符串作为参数，并删除字符串中的空格。 
在一个程序中测试该函数，使用循环读取输入行，直到用户输入一行空行。 
该程序应该应用该函数只每个输入的字符串，并显示处理后的字符串。
 */
#include <stdio.h>
#define SIZE 30

char * trimSpace(char *string);
char *s_gets(char *st, int n);

int main(void)
{   
    char str[SIZE]; 
    puts("输入个字符串去除里面的空格:");
    s_gets(str, SIZE);
    while (*str != 'q')
    {
        trimSpace(str);
        printf("去除空格后字符串为：%s\n", str);
        puts("输入个字符串去除里面的空格:");
        s_gets(str, SIZE);
    }
    
    return 0;
}

char * trimSpace(char *str)
{
    int count = 0;
    while (*(str+count) != '\0')
    {
        if (*(str+count) == ' ' || *(str+count) == '\t')
        {
            int move = count;
            do
            { /* 移动了字符串可能造成时间浪费 */  
                *(str+move) = *(str+move+1);
                move++;
            } while (*(str+move) != '\0');
        }
        else
        {
            count++;
        }
    }
    return str;
}

/* 效率比第一种高 */
char * trimSpace2(char *str)
{
    char *head = str;
    int count = 0;
    while (*str != '\0')
    {
        if (*str != ' ')
            *head++ = *str++;
        else
        {
            str++;
            count++;
        }
    }
    while (count--)
    {
        *head++ = '\0';
    }
    return str;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        int i = 0;
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;            
    }
    return ret_val;
}