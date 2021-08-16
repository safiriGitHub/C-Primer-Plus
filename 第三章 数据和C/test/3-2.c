//2.编写一个程序，要求提示输入一个ASCII码值（如，66），然后打印 输入的字符。
#include <stdio.h>
int main(void)
{
    int asc_code;
    printf("请输入一个ASCII码值，如66：");
    scanf("%d", &asc_code);
    printf("输入的字符为%c", asc_code);
}
// 快速学习 拥抱变化
