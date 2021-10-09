/* 
8.编写一个程序，以一个字符和任意文件名作为命令行参数。如果字符 
后面没有参数，该程序读取标准输入；否则，程序依次打开每个文件并报告 
每个文件中该字符出现的次数。文件名和字符本身也要一同报告。程序应包 
含错误检查，以确定参数数量是否正确和是否能打开文件。如果无法打开文
件，程序应报告这一情况，然后继续处理下一个文件。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *s_gets(char *st, int len);
void readFormStdin(char s_ch);
int searchCharCount(char s_ch, char *content);
void readFormFile(char s_ch, char* fileName);

int main(int argc, char *argv[])
{   
    char s_ch;   

    if (argc < 2)
    {
        fprintf(stderr, "运行错误, 输入一个字符");
        exit(EXIT_FAILURE);
    }
        
    
    if (strlen(argv[1]) == 1)
        s_ch = argv[1][0];
    else
        fprintf(stderr, "第一个参数应该是单个字符");
    
    if (argc == 2) 
    {
        /* 读取标准输入模式 */
        readFormStdin(s_ch);
    }
    
    if (argc > 2)
    {
        /* 读取文件模式 */
        for (int i = 2; i < argc; i++)
        {
            readFormFile(s_ch, argv[i]);
        }
        
    }
    
    
    return 0;
}
void readFormFile(char s_ch, char* fileName)
{
    FILE *pf;
    char read_char;
    int count = 0;
    if ((pf = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "文件%s打不开哦!", fileName);
        return;
    }
    while ((read_char = fgetc(pf)) != EOF)
        if (read_char == s_ch)
            count++;

    fprintf(stdout, "字符：%c 在文件%s中出现次数为：%d\n", s_ch, fileName, count);
}
void readFormStdin(char s_ch)
{
    char stdin_buffer[1024] = {0};
    printf("请输入一段内容\n");
    if (s_gets(stdin_buffer, 1024) != NULL)
    {
        int count = searchCharCount(s_ch, stdin_buffer);
        fprintf(stdout, "字符：%c 出现次数为：%d", s_ch, count);
    }
    else
    {
        fprintf(stderr, "没有输入内容哦！！");
    }
}

int searchCharCount(char s_ch, char *content)
{
    char *temp = content;
        int count = 0;
        while (*temp++ != '\0')
            if (*temp == s_ch)
                count++;
    
    return count;
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