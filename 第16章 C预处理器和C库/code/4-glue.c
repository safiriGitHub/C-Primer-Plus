/* glue.c -- 使用##运算符 */
#include <stdio.h>
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x"#n"=%d\n",x##n);

int main(void)
{
    int XNAME(1) = 14; //变成int x1 = 14;
    int XNAME(2) = 20; //变成int x2 = 20;
    int x3 = 30;
    PRINT_XN(1); //printf("x1=%d\n",x1);
    PRINT_XN(2); //printf("x2=%d\n",x2);
    PRINT_XN(3); //printf("x3=%d\n",x3);
    return 0;
}

// x1=14
// x2=20
// x3=30
// PRINT_XN()宏用#运算符组合字符串，##运算符把记号组合为一 个新的标识符。

