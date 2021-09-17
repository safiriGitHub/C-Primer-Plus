/* 
6.编写一个名为is_within()的函数，接受一个字符和一个指向字符串的 
指针作为两个函数形参。如果指定字符在字符串中，该函数返回一个非零值 
（即为真）。否则，返回0（即为假）。在一个完整的程序中测试该函数， 
使用一个循环给函数提供输入值。
 */

#include <stdio.h>
#include <stdbool.h>

#define SIZE 40
bool is_within(char *str, char c);

int main(void)
{
    char source[SIZE];
    char dest = ' ';
    printf("Enter a string: ");
    fgets(source, SIZE, stdin);
    while (dest != EOF)
    {
        printf("Enter a char to find (EOF to Quit): ");
        while ((dest = getchar()) == '\n')
        {
            continue;
        }
        if (is_within(source, dest))
        {
            printf("Found the charactor %c in the string\n", dest);
        }
        else
        {
            printf("Charactor %c not found. Try another?\n", dest);
        }
    }
    
    return 0;
}

bool is_within(char *str, char c)
{
    while (*str != '\0')
    {
        if (*str == c)
            return true;
        else
            str++;
    }
    return false;
}