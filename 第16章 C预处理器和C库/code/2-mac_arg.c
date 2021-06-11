/* mac_arg.c -- 带参数的宏 */
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n", X);

int main(void)
{
    int x = 5;
    int z;
    printf("x=%d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x):");
    PR(z);

    z = SQUARE(2); 
    printf("Evaluating SQUARE(2): "); 
    PR(z);

    printf("Evaluating SQUARE(x+2):");
    PR(SQUARE(x+2)); //x+2*x+2 ==> 5+2*5+2 = 17 解释1

    printf("Evaluating 100/SQUARE(2):");
    PR(100/SQUARE(2)); // 100/2*2 = 100

    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x):");
    PR(SQUARE(++x)); // ++x*++x ==> 6*7 = 42 递增了两次x，一次在乘法运算之前，一次 在乘法运算之后 //解释2
    printf("After incrementing, x is %x.\n", x);

    return 0;
}

/*
解释1
演示了函数调用和宏调用的重要区别。
函数调用在程序运行时把参数的值传递给函数。
宏调用在编译之前把参数记号传递给程序。
这两个不同的过程发生在不同时期。

解释2
由于标准并未对这类运算规定顺序，所以有些编译器得 7*6。
而有些编 译器可能在乘法运算之前已经递增了x，所以7*7得49。
在C标准中，对该表 达式求值的这种情况称为未定义行为。

无论哪种情况，x的开始值都是5，虽 然从代码上看只递增了一次，但是x的最终值是7。 
解决这个问题最简单的方法是，避免用++x 作为宏参数。
一般而言，不 要在宏中使用递增或递减运算符。
但是，++x可作为函数参数，因为编译器 会对++x求值得5后，再把5传递给函数。
*/
