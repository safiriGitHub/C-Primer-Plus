/* 

3.设计并测试一个函数，从一行输入中把一个单词读入一个数组中，并 
丢弃输入行中的其余字符。该函数应该跳过第1个非空白字符前面的所有空 
白。将一个单词定义为没有空白、制表符或换行符的字符序列。
 */
#include <stdio.h>
#define SIZE 30

char * get_word(char *out);
int main(void)
{
    char out[SIZE];
    get_word(out);
    printf("First word is: %s", out);
    return 0;
}

char * get_word(char *out)
{
    char input[SIZE];
    char *in = input;
    puts("Enter a string:");
    fgets(input, SIZE, stdin);
    while ((*in == '\n') || (*in == '\t') || (*in == ' ') && *in != '\0')
        in++;
    while ((*in != '\n') && (*in != '\t') && (*in != ' ') && (*in != '\0'))
        *out++ = *in++;
    return out;      
}
