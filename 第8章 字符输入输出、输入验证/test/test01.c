/* 1.设计一个程序，统计在读到文件结尾之前读取的字符数。 */
#include <stdio.h>

int main(void)
{
    int count = 0;
    char c;
    puts("Enter Ctrl+D end the input.");
    while ((c = getchar()) != EOF)
    {
        count++;
    }
    printf("The file has %d characters.\n", count);
    puts("Done!");
    return 0;
}