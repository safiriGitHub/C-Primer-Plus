/* 
6.使用命令行参数的程序依赖于用户的内存如何正确地使用它们。重写 
程序清单 13.2 中的程序，不使用命令行参数，而是提示用户输入所需信息。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 40
char * s_gets(char *st, int n);
int main(void)
{
    FILE *in, *out; //声明两个指向FILE的指针
    int ch;
    char file_app[SLEN]; //目标文件名
    char file_src[SLEN]; //源文件名
    int count = 0;

    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);
    if ((out = fopen(file_app, "w")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of source file:");
    s_gets(file_src, SLEN);
    if ((in = fopen(file_src, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_src);
        exit(EXIT_FAILURE);
    }

    //拷贝数据
    while ((ch = getc(in)) != EOF)
    {
        if (count++ % 3 == 0)
            putc(ch, out); // 打印3个字符中的第1个字符
    }
    
    //收尾工作
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files\n");
    }

    return 0;
    
}

char * s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    if ((ret_val = fgets(st, n, stdin)) != NULL)
        while (st[i] != '\n' && st[i] != '\0')
            i++;
    if (st[i] == '\n')
        st[i] = '\0';
    else
        while (getchar() != '\n')
            continue;
    return ret_val;
}