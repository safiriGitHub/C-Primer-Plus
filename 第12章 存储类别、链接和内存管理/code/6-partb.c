// partb.c -- 程序的其余部分
// 与parta.c 一起编译

#include <stdio.h>

extern int count; //引用式声明，外部链接
static int total = 0; //静态定义，内部链接
void accumulate(int k); //函数原型  并未在文件中调用该函数，所以其原型为可选（即省略原型也 不影响使用）
void accumulate(int k) //k 具有块作用域，无链接 
{
    static int subtotal = 0; //静态 无链接
    if (k <= 0) 
    {
        printf("loop cycle: %d\n", count); 
        printf("subtotal: %d; total: %d\n", subtotal, total); 
        subtotal = 0; 
    }
    else 
    {
        subtotal += k; 
        total += k; 
    }
}



