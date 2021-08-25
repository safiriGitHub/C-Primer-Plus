/* 7.编写一个程序把一个单词读入一个字符数组中，然后倒序打印这个单 
词。提示：strlen()函数（第4章介绍过）可用于计算数组最后一个字符的下 标。 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char words[30];
    printf("Enter the word:");
    // scanf("%s", &words);
    gets(words);
    printf("your enter is: %s\n", words);
    printf("The reverse word is: ");
    for (int i = strlen(words) - 1; i >= 0; i--)
    {
        printf("%c", words[i]);
    }
    
    return 0;
}