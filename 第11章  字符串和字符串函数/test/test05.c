/* 
5.设计并测试一个函数，搜索第1个函数形参指定的字符串，在其中查 
找第2个函数形参指定的字符首次出现的位置。如果成功，该函数返指向该 
字符的指针，如果在字符串中未找到指定字符，则返回空指针（该函数的功 能与 strchr()函数相同）。
在一个完整的程序中测试该函数，使用一个循环 给函数提供输入值。
 */

#include <stdio.h>

#define SIZE 40
char * find_char(char *str, char c);

int main(void)
{
    char source[SIZE];
    char dest = ' ';
    char *position;
    printf("Enter a string: ");
    fgets(source, SIZE, stdin);
    while (dest != EOF)
    {
        printf("Enter a char to find (EOF for Quit): ");
        while ((dest = getchar()) == '\n')
        {
            continue;
        }
        if ((position = find_char(source, dest)) != NULL)
        {
            printf("Found the char %c in the %p\n", *position, position);
        }
        else
        {
            printf("Charactor %c not found. Try another?\n", dest);
        }
    }
    
    return 0;
}

char * find_char(char *str, char c)
{
    while (*str != '\0')
    {
        if (*str == c)
            return str;
        else
            str++;
    }
    return NULL;
}