/* 
10.编写一个程序打开一个文本文件，通过交互方式获得文件名。通过 
一个循环，提示用户输入一个文件位置。然后该程序打印从该位置开始到下 
一个换行符之前的内容。用户输入负数或非数值字符可以结束输入循环。
 */

#include <stdio.h>
#include <stdlib.h>

#define SLEN 41

char *s_gets(char *st, int len);
int main(void)
{   
    char fileName[SLEN];
    FILE *p_file;
    unsigned long input_num;

    puts("请输入要打开的文件名：");
    s_gets(fileName, SLEN);
    if ((p_file = fopen(fileName, "r")) == NULL)
    {
        puts("打开文件出错");
        exit(EXIT_FAILURE);
    }
    
    puts("请输入一个数字，输入负数或非数值字符可以结束输入循环：");
    while (scanf("%lu", &input_num) == 1)
    {
        if (fseek(p_file, input_num, SEEK_SET) == 0)
        {
            char read[1024];
            if (fgets(read, 1024, p_file) != NULL)
                printf("%s", read);
            puts("请输入一个数字，输入负数或非数值字符可以结束输入循环：");
        }
        else 
            puts("文件定位失败，请重试。");
    }
    

    return 0;
}

char *s_gets(char *st, int len)
{
    char *ret_val = NULL;
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
