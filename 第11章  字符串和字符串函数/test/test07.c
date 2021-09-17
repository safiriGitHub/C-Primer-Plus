/* 
7.strncpy(s1, s2, n)函数把s2中的n个字符拷贝至s1中，截断s2，或者有必 
要的话在末尾添加空字符。如果s2的长度是n或多于n，目标字符串不能以空 
字符结尾。该函数返回s1。自己编写一个这样的函数，名为mystrncpy()。在 
一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

#include <stdio.h>
#define SIZE 40

char *mystrncpy(char *dest, char *src, int n);
int main(void)
{
    char dest[SIZE];
    char source[SIZE];
    int num = 0;
    printf("Enter a string as source (blank to quit): ");
    fgets(source, SIZE, stdin);
    printf("Enter number of charactor you need to copy: ");
    scanf("%d", &num);
    while (*source != '\n') 
    {
        mystrncpy(dest, source, num);
        printf("The destination string is: %s\n", dest);
        while (getchar() != '\n')
            break;
        printf("Enter a string as source (blank to quit): ");
        fgets(source, SIZE, stdin);
        printf("Enter number of charactor you need to copy: ");
        scanf("%d", &num);
    }
    
    return 0;
}

char *mystrncpy(char *dest, char *src, int n)
{
    int count = 0;
    while (*src != '\0' && count < n)
    {
        *(dest + count++) = *src++;
    }
    if (count < n)
    {
        while (count < n)
        {
            *(dest + count++) = '\0';
        }
    }
    return dest;    
}