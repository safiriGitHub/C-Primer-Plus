/* manybook.c -- 包含多本书的图书目录 */
/*
内含100个结构变量的数组。该数组是自动存储类别的对象
*/

#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL 41 
#define MAXAUTL 41
#define MAXBKS 100 /* 书籍的最大数量 */
struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS]; /*book类型结构的数组*/ 
    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL 
    && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);

        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);

        while (getchar() != '\n') 
            continue; /* 清理输入行 
            我们插入的这两行代码只会在输入序 列中查找并删除\n，不会处理其他字符。
            这样s_gets()就可以重新开始下一次 输入。*/
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    if (count > 0)
    {   
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
            library[index].author, library[index].value);
    }else
        printf("No books? Too bad.\n");
    return 0;
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}



