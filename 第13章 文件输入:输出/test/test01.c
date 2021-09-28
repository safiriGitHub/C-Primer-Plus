/* 
1.修改程序清单13.1中的程序，要求提示用户输入文件名，并读取用户 
输入的信息，不使用命令行参数。
 */

#include <stdio.h>
#include <stdlib.h>

#define NAMELEN 81
char *s_gets(char s[], int len);

int main(void)
{
    char file_name[NAMELEN];
    FILE *fp;
    int ch;
    unsigned long count = 0;

    printf("Enter file name:\n");
    s_gets(file_name, NAMELEN);

    if ((fp = fopen(file_name, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s file", file_name);
        exit(EXIT_FAILURE);
    }
    
    while ((ch = fgetc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    
    fclose(fp);
    printf("File %s has %lu characters\n", file_name, count);
    return 0;
}

char *s_gets(char s[], int len)
{
    char *res_val;
    int i = 0;
    if ((res_val = fgets(s, len, stdin)) != NULL)
    {
        while (s[i] != '\n' && s[i] != '\0')
        {
            i++;
        }
    }
    if (s[i] == '\n')
        s[i] = '\0';
    else
        while (getchar() != '\n')
            continue;
    return res_val;        
}