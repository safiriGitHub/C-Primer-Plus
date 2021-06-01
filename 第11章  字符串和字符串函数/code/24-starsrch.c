/* starsrch.c -- 使用strncmp()*/

#include <stdio.h>
#include <string.h>
#define LISTSIZE 6

int main(void)
{
    const char *list[LISTSIZE] = 
    {
        "astronomy", "astounding", 
        "astrophysics", "ostracize", 
        "asterism", "astrophobia"
    };
    int count = 0;
    int i;
    for (i = 0; i < LISTSIZE; i++)
        if (strncmp(list[i], "astro", 1) == 0) //1
        {
            printf("Found: %s\n", list[i]); 
            count++;
        }
    printf("The list contained %d words beginning" " with astro.\n", count);
    return 0;
}

/*1 代码的意思是：比较list[i] 和 "astro" 的前5个元素是否相等
  所以 改成 if (strncmp(list[i], "astrodd", 5) == 0)  结果也不变
  改成 if (strncmp(list[i], "astro", 1) == 0) 则只比较"astro" 的前1个元素是否相等，结果有5个字符串符合
*/
