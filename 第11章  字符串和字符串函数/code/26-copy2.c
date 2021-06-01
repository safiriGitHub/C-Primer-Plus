/*copy2.c -- 使用strcpy()*/
#include <stdio.h>
#include <string.h>
#define WORDS "beast"
#define SIZE 40

int main(void)
{
    const char *orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char *ps;
    puts(orig);
    puts(copy);

    ps = strcpy(copy + 7, orig);
    puts(copy); //1
    puts(ps); //2

    return 0;
}
/*
beast
Be the best that you can be.
Be the beast
beast
*/

/*1
strcpy()把源字符串中的空字符也拷贝在内。故打印到 beast 遇到空字符就停止了
2
由于第1个参数是copy + 7，所以ps指向copy中的第8个元素（下标为7）。因此puts(ps)从该处开始打 印字符串。
*/
