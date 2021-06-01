/*join_chk.c -- 拼接两个字符串，检查第1个数组的大小*/

#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13

char * s_gets(char *st, int n);

int main(void)
{
    char flower[SIZE];
    char addon [] = "s smell like old shoes.";
    char bug[BUGSIZE];
    int available;

    puts("What is your favorite flower?");
    s_gets(flower, SIZE);
    if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
    {
        strcat(flower, addon);
    }
    puts(flower);

    puts("What is your favorite bug?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) - 1;
    strncat(bug, addon, available);
    puts(bug);

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

/*
strcat()函数无法检查第1个数组是否能容纳第2个字符串。如果分配给第
1个数组的空间不够大，多出来的字符溢出到相邻存储单元时就会出问题。
*/