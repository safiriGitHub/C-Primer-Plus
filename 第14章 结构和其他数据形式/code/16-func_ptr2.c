/* fun_ptr.c -- 使用函数指针 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char *s_gets(char *st, int n);
enum menutype {u, l, t, o, n};
enum menutype showmenu(void);

void eatline(void); //读取至行末尾
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *); //大小写转置
void Dummy(char *); //不更改字符串

typedef void(*V_FP_CHARP)(char *);
void show(V_FP_CHARP fp, char *str);
V_FP_CHARP arpf[4] = {ToUpper, ToLower, Transpose, Dummy};


int main(void)
{
    char line[LEN];
    char copy[LEN];
    enum menutype choice;
    void(*pfun)(char *); //声明一个函数指针，被指向的函数接受char *类型的参数，无返回值

    puts("Enter a string (empty line to quit):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0')
    {
        while ((choice = showmenu()) != n)
        {
            strcpy(copy, line); //为show()函数拷贝一份
            show(arpf[choice], copy); //根据用户的选择，使用选定的函数
        }
        puts("Enter a string (empty line to quit):");
    }

    puts("Bye!");
    return 0;
}

enum menutype showmenu(void)
{
    char ans;
    enum menutype menu;
    puts("Enter menu choice:");
    puts("u) uppercase l) lowercase"); 
    puts("t) transposed case o) original case"); 
    puts("n) next string");
    ans = getchar(); //获取用户的输入
    ans = tolower(ans); //转换为小写
    eatline(); //清理输入行
    while (strchr("ulton", ans) == NULL){
        puts("Please enter a u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }
    switch (ans) //switch 语句设置指针
    {
        case 'u':
            menu = u;
            break;
        case 'l':
            menu = l;
            break;
        case 't':
            menu = t;
            break;
        case 'o':
            menu = o;
            break;
        case 'n':
            menu = n;
            break;
    }
    return menu;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void ToUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char *str)
{
    while (*str)
    {
        *str = tolower(*str);
        str++;
    }
}
void Transpose(char *str) //大小写转置
{
    while (*str)
    {
        if (islower(*str))
            *str = toupper(*str);
        else if(isupper(*str))
            *str = tolower(*str);
        str++;
    }
}
void Dummy(char *str) //不更改字符串
{
    
}

void show(void(*fp)(char *), char *str)
{
    (*fp)(str); //把用户选定的函数作用于str
    puts(str); //显示结果
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