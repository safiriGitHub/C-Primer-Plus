/* put_out.c -- 使用puts() */

#include <stdio.h>
#define DEF "I am a #defined string."

int main(void)
{
    char str1[80] = "An array was initialized to me.";
    const char *str2 = "A pointer was initialized to me.";
    puts("I'm an argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]); //1
    puts(str2 + 4); //2
    return 0;
}
// ray was initialized to me.
//1 表达式&str1[5]是str1数组的第6个元素（r），puts()从该元素开始输出

// inter was initialized to me.
//2 str2+4指向储存"pointer"中i的存储单元，puts()从这里开始输出。

