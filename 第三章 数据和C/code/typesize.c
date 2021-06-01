/* typesize.c -- 打印类型大小*/

#include <stdio.h>

int main(void) {
    /* C99为类型大小提供%zd转换说明 */
    printf("short -- %zd\n ", sizeof(short));
    printf("unsigned short -- %zd\n ", sizeof(unsigned short));
    // 相同类型有符号和无符号位数相同，不再打印有符号的类型

    printf("int -- %zd\n ", sizeof(int));
    printf("long long -- %zd\n ", sizeof(long long));
    printf("long -- %zd\n ", sizeof(long));
    printf("char -- %zd\n ", sizeof(char));
    printf("double -- %zd\n ", sizeof(double));
    printf("long double -- %zd\n ", sizeof(long double));

    printf("--------------\n");
    printf("int32_t -- %zd\n", sizeof(int32_t));
}