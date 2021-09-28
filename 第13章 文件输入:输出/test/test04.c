/* 
4.编写一个程序，按顺序在屏幕上显示命令行中列出的所有文件。使用 argc控制循环。
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fi;
    int ch;

    for (int i = 1; i < argc; i++)
    {
        if ((fi = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr, "Can't open file : %s\n", argv[i]);
        }
        else 
        {
            printf("file '%s' contents: \n", argv[i]);
            while ((ch = getc(fi)) != EOF)
            {
                putchar(ch);
            }
            putchar('\n');
            fclose(fi);
        }
    }
    puts("All file printed!!");
    return 0;
}