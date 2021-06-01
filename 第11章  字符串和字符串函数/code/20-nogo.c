/* nogo.c -- 该程序是否能正常运行?*/

#include <stdio.h> 
#define ANSWER "Grant" 
#define SIZE 40 
char * s_gets(char * st, int n); 

int main(void) 
{
    char try[SIZE]; 
    puts("Who is buried in Grant's tomb?"); 
    s_gets(try, SIZE); 
    while (try != ANSWER) //1
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE); 
    }
    puts("That's right!"); 
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
/*1
ANSWER和try都是指针
因为ANSWE和try储存在不同的位置，所以这两个地址 不可能相同，
因此，无论用户输入什么，程序都提示输入不正确。这真让人 沮丧。
*/