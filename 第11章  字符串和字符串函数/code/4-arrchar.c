/* arrchar.c -- 指针数组，字符串数组 */

#include <stdio.h>
#define SLEN 40
#define LIM 5

int main(void)
{
    const char *mytalents[LIM] = {
        "曾经沧海难为水",
        "除却巫山不是云",
        "呜呜呜",
        "lalala"
    };

    char yourtalents[LIM][SLEN] = {
        "曾经沧海难为水",
        "除却巫山不是云",
        "呜呜呜"
    };

    int i;
    puts("比较一下");
    printf("%-36s %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i++) 
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
    
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
    sizeof(mytalents), sizeof(yourtalents));

    return 0;
}

//sizeof mytalents: 40, sizeof yourtalents: 200
/*
mytalents数组是一个内含5个指针的数组，在我们的系统中共占用40字节(即5个long指针)。
mytalents中的指针指向初始化时所用的字符串字面量的位置，这些字符 串字面量被储存在静态内存中；
而 yourtalents 中的数组则储存着字符串字面 量的副本，所以每个字符串都被储存了两次。

*/

