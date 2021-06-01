/* fgets2.c -- 使用fgets() 和 fputs() */

#include <stdio.h>
#define STLEN 10

int main(void)
{
    char words[STLEN];
    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
    {
        fputs(words, stdout);
    }
    puts("Done.");
    return 0;
}

/*
fgets()储存换行符有好处也有坏处。坏处是你可能并不想把换行符储存
在字符串中，这样的换行符会带来一些麻烦。好处是对于储存的字符串而言
，检查末尾是否有换行符可以判断是否读取了一整行。如果不是一整行，
要妥善处理一行中剩下的字符。--因为该函数专门设计用于处理文件输入
*/

