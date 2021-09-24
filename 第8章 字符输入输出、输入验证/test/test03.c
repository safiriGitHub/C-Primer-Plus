/* 
3.编写一个程序，在遇到 EOF 之前，把输入作为字符流读取。该程序 
要报告输入中的大写字母和小写字母的个数。假设大小写字母数值是连续 
的。或者使用ctype.h库中合适的分类函数更方便。
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int lower_count = 0;
    int upper_count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
        {
            lower_count++;
        }
        else if (isupper(ch))
        {
            upper_count++;
        }
    }
    printf("大写字母%d个 小写字母%d个", upper_count, lower_count);
    return 0;
}