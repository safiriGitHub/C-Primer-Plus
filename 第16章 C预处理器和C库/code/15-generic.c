// generic.c -- 定义泛型宏

#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG (180/(4*atanl(1)))

//泛型平方根函数
#define SQRT(X) _Generic((X),\
long double: sqrtl,\
float: sqrtf,\
default: sqrt)(X)

//泛型正弦函数，角度的单位为度
#define SIN(X) _Generic((X),\
long double: sinl(X)/RAD_TO_DEG,\
default: sin(X)/RAD_TO_DEG,\
float: sinf(X)/RAD_TO_DEG\
)

int main(void)
{
    // _Generic((5), int:"int", float:"float", int *: "int *",default:"other");
    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;
    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);
    printf("%.17Lf\n", y); //匹配float
    printf("%.17Lf\n", yy);
    printf("%.17Lf\n", yyy);
    int i = 45;
    yy = SQRT(i); //default
    printf("%.17Lf\n", yy); 
    yyy = SIN(xxx); // 匹配 long double 
    printf("%.17Lf\n", yyy); 
    return 0;
}

/*
如何让_Generic 宏的行为像一个函数。SIN()的定义也 许提供了一个方法：
每个带标号的值都是函数调用，所以_Generic表达式的 值是一个特定的函数调用，
如sinf((X)/RAD_TO_DEG)，用传入SIN()的参数 替换X。

SQRT()的定义也许更简洁。_Generic表达式的值就是函数名，如sinf。 
函数的地址可以代替该函数名，所以_Generic表达式的值是一个指向函数的指针。
然而，紧随整个_Generic表达式之后的是(X)，函数指针(参数)表示函数指针。
因此，这是一个带指定的参数的函数指针。 

简而言之，对于 SIN()，函数调用在泛型选择表达式内部；
而对于 SQRT()，先对泛型选择表达式求值得一个指针，然后通过该指针调用它所 指向的函数。
*/
