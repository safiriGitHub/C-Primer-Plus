/* 5.使用switch重写练习4。 */
#include <stdio.h>

int main(void)
{
    int count = 0;
    char ch;

    while ((ch = getchar()) != '#') 
    {
        switch (ch)
        {
        case '.':
            printf("!");
            count++;
            break;
        case '!':
            printf("!!");
            count++;
            break;
        default:
            printf("%c", ch);
            break;
        }
    }
    printf("总共替换了%d次", count); 
    return 0;
}