// mytype.c

#include <stdio.h>

#define MYTYPE(X) _Generic((X),\
int: "int",\
float: "float",\
double: "double",\
default: "other"\
)

#define MYTYPE2(Y) _Generic((Y), int:"int", float:"float", int *: "int *",default:"other")

int main(void)
{
    int d = 5;
    printf("%s\n", MYTYPE(d)); //d是int类型
    printf("%s\n", MYTYPE(2.0*d)); // 2.0 * d 是double类型
    printf("%s\n", MYTYPE(3L)); // 3L是long类型 
    printf("%s\n", MYTYPE(&d)); // &d 的类型是 int *
    
    printf("%s\n", MYTYPE2(d)); //d是int类型
    printf("%s\n", MYTYPE2(2.0*d)); // 2.0 * d 是double类型
    printf("%s\n", MYTYPE2(3L)); // 3L是long类型 
    printf("%s\n", MYTYPE2(&d)); // &d 的类型是 int *
    return 0;
}