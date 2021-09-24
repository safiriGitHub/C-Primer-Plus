
#include <stdio.h>
#include <string.h>

#define PRAISE "You are an extraordinary being."

int main(void) {
    char name[40];
    printf("What's your name?");
    scanf("%s", name);
    printf("Hello, %s.%s\n", name, PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells.\n",
    strlen(name), sizeof(name));
    printf("The phrase of praise has %zd letters",
    strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof(PRAISE));
    return 0;
    //使用了两种方法处理很长的printf()语句。
    //第1种方法 是将printf()语句分为两行（可以在参数之间断为两行，但是不要在双引号中 的字符串中间断开）；
    //第 2 种方法是使用两个printf()语句打印一行内容，只 在第2条printf()语句中使用换行符（\n）。
}