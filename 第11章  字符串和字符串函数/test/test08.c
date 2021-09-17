/* 
8.编写一个名为string_in()的函数，接受两个指向字符串的指针作为参 
数。如果第2个字符串中包含第1个字符串，该函数将返回第1个字符串开始
的地址。例如，string_in("hats", "at")将返回hats中a的地址。否则，该函数返 
回空指针。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值。
 */

#include <stdio.h>
#define SIZE 40

char * string_in(char *source, char *target);
char *s_gets(char *st, int n);
int main(void)
{
    char source[SIZE];
    char target[SIZE];
    printf("Enter a string as source (blank to quit): ");
    s_gets(source, SIZE);
    printf("Enter a string as target (blank to quit): ");
    s_gets(target, SIZE);

    while (*source != '\n') 
    {
        char *result = string_in(source, target);
        if (result == NULL)
            printf("not found '%s' in '%s'\n", target, source);
        else
            printf("fount at address: %p -- %s\n", result, result);
        printf("Enter a string as source (blank to quit): ");
        s_gets(source, SIZE);
        printf("Enter a string as target (blank to quit): ");
        s_gets(target, SIZE);
    }
    return 0;
}

char * string_in(char *source, char *target)
{
    int count = 0;
    while (*(target+count) != '\0' && *source != '\0')
    {
        if (*(target+count) == *(source+count))
        {
            count++;
        }
        else
        {
            source++;
            count = 0;
        }
    }
    if (count > 0)
        return source;
    else
        return NULL;
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