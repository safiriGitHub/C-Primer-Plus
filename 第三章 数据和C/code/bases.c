/* bases.c == 以十进制、八进制、十六进制打印十进制数100 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 100;
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

    // 测试一下整数类型
    long int estine;
    long johns;
    short int erns;
    short ribs;
    unsigned int s_count;
    unsigned players;
    unsigned long headcount;
    unsigned short yesvotes;
    long long ago;

    return 0;
}
