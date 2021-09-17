/* 
1.设计并测试一个函数，从输入中获取下n个字符（包括空白、制表 符、换行符），
把结果储存在一个数组里，它的地址被传递作为一个参数。
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
        if (str[i] == EOF)
        {
            break;
        }
    }
    return str;
}
