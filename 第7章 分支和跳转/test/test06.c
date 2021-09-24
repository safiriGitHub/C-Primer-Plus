/* 6.编写程序读取输入，读到#停止，报告ei出现的次数。 
注意该
程序要记录前一个字符和当前字符。用“Receive your eieio award”这 
样的输入来测试。 */

#include <stdio.h>

int main(void)
{
    char pre_ch;
    char ch;
    int count = 0;

    while ((ch = getchar()) != '#')
    {
        if ('e' == pre_ch && 'i' == ch)
        {
            count++;
        }
        pre_ch = ch;
    }
    
    printf("报告ei出现的次数:%d", count);
    return 0;
}