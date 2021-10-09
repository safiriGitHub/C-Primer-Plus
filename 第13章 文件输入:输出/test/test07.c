/* 
7.编写一个程序打开两个文件。可以使用命令行参数或提示用户输入文 件名。
a.该程序以这样的顺序打印：打印第1个文件的第1行，第2个文件的第1 
行，第1个文件的第2行，第2个文件的第2行，以此类推，打印到行数较多文 
件的最后一行。 
b.修改该程序，把行号相同的行打印成一行。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 40
char *s_gets(char *st, int len);
int main(void)
{
    FILE *file1, *file2;
    char file_name_1[SLEN]; 
    char file_name_2[SLEN];
    char buffer_1[256] = {0};
    char buffer_2[256] = {0};

    puts("Enter name of first file:");
    s_gets(file_name_1, SLEN);
    if ((file1 = fopen(file_name_1, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_name_1);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of second file:");
    s_gets(file_name_2, SLEN);
    if ((file2 = fopen(file_name_2, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_name_2);
        exit(EXIT_FAILURE);
    }

    //a 
    while (feof(file1) == 0 || feof(file2) == 0)
    {
        if (fgets(buffer_1, 256, file1) != NULL)
        {
            // 实现b
            int length = strlen(buffer_1);
            if (buffer_1[length - 1] == '\n')
                buffer_1[length-1] = '\0';
            
            fputs(buffer_1, stdout);
        }
        if (fgets(buffer_2, 256, file2) != NULL)
        {
            fputs(buffer_2, stdout);
        }
    }
    return 0;
}

char *s_gets(char *st, int len)
{
    char *ret_val;
    int i = 0;

    if ((ret_val = fgets(st, len, stdin)) != NULL)
    {
        while (st[i] != '\0' && st[i] != '\n')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;            
    }
    return ret_val;
}