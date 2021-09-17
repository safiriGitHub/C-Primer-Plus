/* 
2.修改并编程练习1的函数，在n个字符后停止，或在读到第1个空白、 
制表符或换行符时停止，哪个先遇到哪个停止。不能只使用scanf()
 */

#include <stdio.h>

#define SIZE 30
char * read_char(char *str, int len);

int main(void)
{
    char test[SIZE];
    puts("Enter a string:");
    read_char(test, SIZE);
    puts("The string is:");
    puts(test);

    return 0;
}

char * read_char(char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        str[i] = getchar();
        if (str[i] == EOF || str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
            break;
    }
    return str;
}