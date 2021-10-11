/* 
11.编写一个程序，接受两个命令行参数。第1个参数是一个字符串，第 
2个参数是一个文件名。然后该程序查找该文件，打印文件中包含该字符串 
的所有行。因为该任务是面向行而不是面向字符的，所以要使用fgets()而不 
是getc()。使用标准C库函数strstr()（11.5.7节简要介绍过）在每一行中查找 
指定字符串。假设文件中的所有行都不超过255个字符。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LNUM 255

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        puts("失败");
        exit(EXIT_FAILURE);
    }
    
    char *s_ch = argv[1];
    char *file_name = argv[2];
    FILE *pf;
    char read[LNUM];
    int line = 0;

    if ((pf = fopen(file_name, "r")) == NULL)
    {
        puts("失败");
        exit(EXIT_FAILURE);
    }
    
    while (fgets(read, LNUM, pf) != NULL)
    {
        line++;
        if (strstr(read, s_ch) != NULL)
            printf("第%d行：%s", line, read);
    }
    
    return 0;
}