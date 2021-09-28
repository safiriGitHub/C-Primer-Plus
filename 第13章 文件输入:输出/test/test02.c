/* 
2.编写一个文件拷贝程序，该程序通过命令行获取原始文件名和拷贝文 
件名。尽量使用标准I/O和二进制模式。
 */
#include <stdio.h>
#include <stdlib.h>

#define NAMELEN 81
char * s_gets(char *st, int len);

int main(void)
{
    FILE *fa, *fs; // fa目标文件  fs源文件
    char file_s[NAMELEN];
    char file_a[NAMELEN];
    int ch = 0;

    puts("Enter name of source file:");
    s_gets(file_s, NAMELEN);
    if ((fs = fopen(file_s, "rb")) == NULL)
    {
        fprintf(stderr, "Can't open file: %s", file_s);
        exit(EXIT_FAILURE);
    }
    
    puts("Enter name of destination file:");
    s_gets(file_a, NAMELEN);
    if ((fa = fopen(file_a, "wb")) == NULL)
    {
        fprintf(stderr, "Can't open file: %s", file_a);
        exit(EXIT_FAILURE);
    }

    // 开始拷贝
    while ((ch = fgetc(fs)) != EOF)
    {
        fputc(ch, fa);
    }
    fclose(fs);
    fclose(fa);

    return 0;
}

char * s_gets(char *st, int len)
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