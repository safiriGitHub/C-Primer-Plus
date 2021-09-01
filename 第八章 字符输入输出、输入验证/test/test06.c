
/* 
6.修改程序清单8.8中的get_first()函数，让该函数返回读取的第1个非空 
白字符，并在一个简单的程序中测试。
 */

#include <stdio.h>

char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void)
{
    char c;
    c = get_first();
    printf("%c\n", c);
    printf("Bye.\n");

    return 0;
}

char get_first(void)
{
    char c;
    c = getchar();
    while (c == ' ' || c == '\n' || c == '\t')
        c = getchar();
    return c;
}
