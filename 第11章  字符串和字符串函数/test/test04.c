/* 
4.设计并测试一个函数，它类似编程练习3的描述，只不过它接受第2个 参数指明可读取的最大字符数。
 */
#include <stdio.h>
#define SIZE 30

char * get_word(char *out, int len);
int main(void)
{
    char out[3];
    get_word(out, 3);
    printf("First word is: %s", out);
    return 0;
}

char * get_word(char *out, int len)
{
    char input[SIZE];
    char *in = input;
    int i = 0;
    puts("Enter a string:");
    fgets(input, SIZE, stdin);
    while ((*in == '\n') || (*in == '\t') || (*in == ' ') && *in != '\0')
        in++;
    while ((*in != '\n') && (*in != '\t') && (*in != ' ') && (*in != '\0') && i < len)
    {
        *out++ = *in++;
        i++;
    }
    return out;      
}