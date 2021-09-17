/* 
11.编写一个函数，读入10个字符串或者读到EOF时停止。该程序为用 
户提供一个有5个选项的菜单：打印源字符串列表、以ASCII中的顺序打印字 
符串、按长度递增顺序打印字符串、按字符串中第1个单词的长度打印字符 
串、退出。菜单可以循环显示，除非用户选择退出选项。当然，该程序要能 
真正完成菜单中各选项的功能。
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20

void show_menu();
void print_original(char str[][SIZE], int len);
void print_ascii(char str[][SIZE], int len);
void print_length(char str[][SIZE], int len);
void print_words(char str[][SIZE], int len);
void sort_order(int order[][2], int len);
int get_word_length(char *str);

int main(void)
{
    char string[5][SIZE];
    char choice = 0;
    puts("Enter 5 strings serperate by enter.");
    for (int i = 0; i < 5; i++)
    {
        fgets(string[i], SIZE, stdin);
    }
    show_menu();
    scanf("%c", &choice);
    while (choice != 'q')
    {
        getchar();
        switch (choice)
        {
        case 'a':
            print_original(string, 5);
            break;
        case 'b':
            print_ascii(string, 5);
            break;
        case 'c':
            print_length(string, 5);
            break;
        case 'd':
            print_words(string, 5);
            break;
        default:
            puts("Error choice, retry!");
            break;
        }
        show_menu();
        scanf("%c", &choice);
    }
    
    
    return 0;
}

void show_menu()
{
    puts("Menu:");
    puts("================================================================");
    puts("a) print original strings.\tb) print string by asii order.");
	puts("c) print strings by length.\td) print string by word length.");
    puts("q) quit");
	puts("================================================================");
}
void print_original(char str[][SIZE], int len)
{
    puts("print 5 strings in original mode.");
    for (int i = 0; i < len; i++)
        printf("%d: %s", i+1, str[i]);    
}
void print_ascii(char str[][SIZE], int len)
{
    puts("print 5 string in ascii mode.");
    int order[5][2];
    for (int i = 0; i < len; i++)
    {
        order[i][0] = i;
        order[i][1] = str[i][0];
    }
    sort_order(order, len);
    for (int i = 0; i < len; i++)
        printf("ASCII NO.%d: %s", i+1, str[order[i][0]]); 
}
void print_length(char str[][SIZE], int len)
{
    puts("print 5 strings in length mode.");
    int order[5][2];
    for (int i = 0; i < len; i++)
    {
        order[i][0] = i;
        order[i][1] = strlen(str[i]);
    }
    sort_order(order, len);
    for (int i = 0; i < len; i++)
        printf("LENGTH No. %d: %s", i+1, str[order[i][0]]);    
}
void print_words(char str[][SIZE], int len)
{
    puts("print 5 strings in words mode.");
	int order[5][2];
	for (int i = 0; i < len; i++)
	{
		order[i][0] = i;
		order[i][1] = get_word_length(str[i]);
	}
	sort_order(order, len);
	for (int i = 0; i < len; i++)
		printf("WORDS No.%d: %s", i + 1, str[order[i][0]]);
}

void sort_order(int order[][2], int len)
{
    int tmp[2];
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-1-i; j++)
        {
            if (order[j][1] > order[j+1][1])
            {
                tmp[0] = order[j][0];
                tmp[1] = order[j][1];
                order[j][0] = order[j + 1][0];
				order[j][1] = order[j + 1][1];
				order[j + 1][0] = tmp[0];
				order[j + 1][1] = tmp[1];
            }
            
        }
        
    }
    
}
int get_word_length(char *str)
{
    char *in = str;
    int len = 0;
    while (isalpha(*in) == 0)
        in++;
    while (isalpha(*in) != 0)
    {
        in++;
        len++;
    }
    return len;
}