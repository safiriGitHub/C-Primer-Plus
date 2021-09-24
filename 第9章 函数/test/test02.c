/* 
2.设计一个函数chline(ch, i, j)，打印指定的字符j行i列。在一个简单的驱 
动程序中测试该函数。 
 */
#include <stdio.h>

void chline(char ch, int i, int j);
int main(void)
{
    chline('d', 4, 2);
    
    chline('q', 5, 4);

    return 0;
}

void chline(char ch, int i, int j)
{
    for (int k = 0; k < j; k++)
    {
        for (int m = 0; m < i; m++)
        {
            putchar(ch);
        }
        putchar('\n');
    }
}