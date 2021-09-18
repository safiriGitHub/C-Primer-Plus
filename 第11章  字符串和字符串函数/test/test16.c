/* 
16.编写一个程序读取输入，直至读到文件结尾，然后把字符串打印出 
来。该程序识别和实现下面的命令行参数： 
-p 按原样打印
-u 把输入全部转换成大写 
-l 把输入全部转换成小写 
如果没有命令行参数，则让程序像是使用了-p参数那样运行。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *s_gets(char *st, int n);
int main(int argc, char* argv[])
{
    char c;
    if (argc < 2)
        c = 'p';
    else
        c = argv[1][1];
    char string[256];
    puts("Enter the string:");
    s_gets(string, 256);
    int length = strlen(string);
    switch (c)
    {
    case 'p':
        printf("The original text is: %s", string);
        break;
    case 'u':
        printf("The Upper text is:");
        for (int i = 0; i < length; i++)
        {
            putchar(toupper(string[i]));
        }
        break;
    case 'l':
        printf("The Lower text is:");
        for (int i = 0; i < length; i++)
        {
            putchar(tolower(string[i]));
        }
        break;
    default:
        break;
    }
    return 0;
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