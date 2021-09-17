/* 
9.编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整 
的程序中测试该函数，使用一个循环给函数提供输入值。
 */

#include <stdio.h>
#define SIZE 30

char *reverse(char *str);
char *s_gets(char *st, int n);
char *reverse2(char *str);

int main(void)
{
    // printf("%s",reverse((char []){'a','b','c','d'}));
    char reverse_str[SIZE];
    puts("Enter a string to reverse('q' to quit) :");
    s_gets(reverse_str, SIZE);
    while (*reverse_str != 'q')
    {
        reverse(reverse_str);
        printf("reverse result: %s\n", reverse_str);
        puts("Enter a string to reverse(blank to quit) :");
        s_gets(reverse_str, SIZE);
    }
    
    return 0;
}

char *reverse(char *str)
{
    int count = 0;
    while (*(str+count) != '\0')
        count++;
    
    for (int i = 0; i < count/2; i++)
    {
        char temp = *(str+i);
        *(str+i) = *(str+count-i-1);
        *(str+count-i-1) = temp;
    }
    return str;
}
char *reverse2(char *str)
{
    int count = 0;
    while (*(str+count) != '\0')
        count++;
    
    for (int i = 0, k = count-i-1; i < count/2; i++, k--)
    {
        char temp = *(str+i);
        *(str+i) = *(str+k);
        *(str+k) = temp;
    }
    return str;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
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