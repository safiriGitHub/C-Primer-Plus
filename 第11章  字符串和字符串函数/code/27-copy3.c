/*copy3.c -- 使用strncpy()*/

#include <stdio.h>
#include <string.h>
#define SIZE 40
#define TARGSIZE 7
#define LIM 5
char * s_gets(char *st, int n);

int main(void)
{
    char qwords[LIM][TARGSIZE];
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