/* sort_str.c -- 读入字符串，并排序字符串 */
#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 20
#define HALT ""

void stsrt(char *strings[], int num); /* 字符串排序函数 */
char *s_gets(char *st, int n);

int main(void)
{
    char input[LIM][SIZE]; /* 存储输入的数组*/
    char *ptstr[LIM]; /* 内含指针变量的数组 */
    int ct = 0; //输入计数
    int k;      //输出计数

    printf("Input up to %d lines, and I will sort them.\n", LIM); 
    printf("To stop, press the Enter key at a line's start.\n");

    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct]; //设置指针指向字符串
        ct++;
    }
    stsrt(ptstr, ct); /* 字符串排序函数 */
    puts("\nHere's the sorted list:\n");
    for (k = 0; k < ct; k++)
        puts(ptstr[k]); /* 排序后的指针 */
    return 0;
}

/* 字符串-指针-排序函数*/
void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;
    for (top = 0; top < num - 1; top++)
    for (seek = top + 1; seek < num; seek ++)
    if (strcmp(strings[top], strings[seek]) > 0)
    {
        temp = strings[top];
        strings[top] = strings[seek];
        strings[seek] = temp;
    }
}

char *s_gets(char *st, int n)
{
    char *res_get;
    int i = 0;

    res_get = fgets(st, n, stdin);
    if (res_get)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return res_get;
}