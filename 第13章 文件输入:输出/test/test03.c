/* 
3.编写一个文件拷贝程序，提示用户输入文本文件名，并以该文件名作 
为原始文件名和输出文件名。该程序要使用 ctype.h 中的 toupper()函数，在 
写入到输出文件时把所有文本转换成大写。使用标准I/O和文本模式。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NAMELEN 81
char *s_gets(char *st, int len);
int main(void)
{
    FILE *fa, *fs; // fa目标文件  fs源文件
    char file_s[NAMELEN];
    char file_a[NAMELEN];
    int ch;

    puts("Enter name of source file:");
    s_gets(file_s, NAMELEN);
    if ((fs = fopen(file_s, "r")) == NULL)
    {
        fprintf(stderr, "Can't open file: %s", file_s);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of target file:");
    if (s_gets(file_a, NAMELEN) && file_a[0] != '\0')
    {
        if (strcmp(file_a, file_s) == 0)
            fputs("Can't append file to itself\n", stderr);
        else if ((fa = fopen(file_a, "w")) == NULL)        
            fprintf(stderr, "Can't open %s\n", file_a);
        else
        {
            while ((ch = getc(fs)) != EOF)
            {
                putc(toupper(ch), fa);
            }
        }
    }

    fclose(fa);
    fclose(fs);
    return 0;
}

char *s_gets(char *st, int len)
{
    char *ret_val;
    int i = 0;

    if ((ret_val = fgets(st, len, stdin)) != NULL)
        while (st[i] != '\n' && st[i] != '\0')
            i++;        
    if (st[i] == '\n')
        st[i] = '\0';
    else
        while (getchar() != '\n')
            continue;                
    
    return ret_val;
}

