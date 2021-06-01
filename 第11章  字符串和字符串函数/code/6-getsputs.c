/* getsputs.c -- 使用gets() 和 puts() */
#include <stdio.h>

#define STLEN 5
int main(void)
{
    char words[STLEN];
    puts("Enter a string, please.");
    gets(words); //典型用法

    printf("Your string twice:\n");
    printf("%s\n", words); 
    puts(words); 
    puts("Done."); 
    return 0;
}

//zsh: segmentation fault  
//“Segmentation fault”（分段错误）似乎不是个好提示，的确如此。在 UNIX系统中，这条消息说明该程序试图访问未分配的内存。
