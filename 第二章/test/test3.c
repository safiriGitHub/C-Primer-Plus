#include <stdio.h>

int main(void)
{
    int yearsold;
    printf("输入你的年龄：\n");
    scanf("%d", &yearsold);
    printf("年龄转为天数为：%d\n", yearsold*365);
    return 0;
}