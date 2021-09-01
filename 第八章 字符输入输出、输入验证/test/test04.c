/* 
4.编写一个程序，在遇到EOF之前，把输入作为字符流读取。该程序要 
报告平均每个单词的字母数。不要把空白统计为单词的字母。实际上，标点 
符号也不应该统计，但是现在暂时不同考虑这么多（如果你比较在意这点， 
考虑使用ctype.h系列中的ispunct()函数）。
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int words = 0;
    int letters = 0;
    char c;
    
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c) != 0)
        {
            letters++;
        }
        if (ispunct(c) != 0 || c == ' ')
        {
            words++;
        }
    }
    printf("There are %d words, %dcharactors, 平均每单词字母数%g", words, letters, 1.0*letters/words);
    return 0;
}