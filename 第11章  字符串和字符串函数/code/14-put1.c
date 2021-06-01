//完全可以在getchar()和putchar()的基础上自定义所需的函数。
/* put1.c -- 打印字符串，不添加\n*/

#include <stdio.h>

void put1(const char *string)
{
    while(*string != '\0') // 也可以这样写：while (*string) 当string指向空字符时，*string的值是0，即测试条件为假，while循环结 束。
        putchar(*string++);
}