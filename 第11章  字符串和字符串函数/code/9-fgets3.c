/* fgets3.c -- 使用fgets() */
//该程序 读取输入行，删除储存在字符串中的换行符，如果没有换行符，则丢弃数组 装不下的字符。
#include <stdio.h>
#define STLEN 10

int main(void)
{
    char words[STLEN];
    int i;

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
    {
        i = 0;
        //以下代码：遍历字符串，直至遇到换行符或空字符。
        //如果先遇到换行符，下面的if 语句就将其替换成空字符；
        //如果先遇到空字符，else部分便丢弃输入行的剩 余字符。
        while (words[i] != '\n' && words[i] != '\0')
        {
            i++;
        }
        if (words[i] == '\n')
        {
            words[i] = '\0';
        }
        else { // 如果word[i] == '\0'则执行这部分代码
            while (getchar() != '\n')
            {
                continue;
            }
        }
        puts(words);        
    }
    puts("Done");
    return 0;
}
