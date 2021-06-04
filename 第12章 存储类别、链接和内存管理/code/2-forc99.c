// forc99.c -- 新的C99块规则

#include <stdio.h>
int main(void)
{
    int n = 8;
    printf("  Initially, n = %d at %p\n", n, &n);

    for (int n = 1; n < 3; n++)
        printf("   loop 1: n = %d at %p\n", n, &n);
    printf("After loop 1, n = %d at %p\n", n, &n);

    for (int n = 1; n < 3; n++)
    {
        printf("   loop 2: n = %d at %p\n", n, &n);
        int n = 6;
        printf("   loop 2: n = %d at %p\n", n, &n);
        n++;
    }
    printf("After loop 2, n = %d at %p\n", n, &n);
    return 0;
}

/*

有些编译器并不支持C99/C11的这些作用域规则（Microsoft Visual Studio 2012就是其中之一）。
有些编译会提供激活这些规则的选项。例如，撰写本 书时，gcc默认支持了C99的许多特性，但是要用 选项激活程序 
清单12.2中使用的特性：
    gcc –std=c99 forc99.c
与此类似，gcc或clang都要使用 -std=c1x 或 -std=c11 选项，才支持 C11 特性。

*/