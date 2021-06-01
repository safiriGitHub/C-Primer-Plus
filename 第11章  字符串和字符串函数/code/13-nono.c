/* nono.c -- 千万不要模仿！*/

#include <stdio.h>

int main(void)
{
    char side_a[] = "Side A";
    char dont[] = {'W', 'O', 'W', '!'};
    char side_b[] = "Side B";

    puts(dont); 
    // puts() 遇到空字符停止输出，但是dont数组没有空字符，
    // 故puts()不知道在何处停止，它会一直打印直到发现一个空字符为止
}