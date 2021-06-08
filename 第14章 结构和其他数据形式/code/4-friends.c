/* friends.c -- 使用指向结构的指针 */
#include <stdio.h>
#define LEN 20
struct names
{
    char first[LEN];
    char last[LEN];
};

struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow[2] = {
        { { "Ewen", "Villard" }, "grilled salmon", "personality coach", 68112.00},
        { { "Rodney", "Swillbelly" }, "tripe", "tabloid editor", 432400.00}
    };
    struct guy *him; //一个指向结构的指针
    printf("address #1: %p, #2:%p\n", &fellow[0], &fellow[1]);
    him = &fellow[0]; // 告诉编译器该指针指向何处

    printf("pointer #1: %p, #2:%p\n", him, him+1);
    printf("hime->income is $%.2f, (*him).income is $%.2f\n", him->income, (*him).income);
    him++; //指向下一个指针
    printf("him->favfood is %s: him->handle.last is %s\n",
    him->favfood, him->handle.last);
    return 0;
}

/*
him = &fellow[0]; // 告诉编译器该指针指向何处
和数组不同的是，结构名并不是结构的地址，因此要在结构名前面加上 &运算符。

顺带一提，在有些系统中，一个结构的大小可能大于它各成员大小之和。
这是因为系统对数据进行校准的过程中产生了一些“缝隙”。
例如，有些系统必 须把每个成员都放在偶数地址上，或4的倍数的地址上。
在这种系统中，结构的内部就存在未使用的“缝隙”。


*/ 
 