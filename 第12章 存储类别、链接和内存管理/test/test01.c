/* 
1.不使用全局变量，重写程序清单12.4。
 */

#include <stdio.h>

void critic(int *us);
int main(void)
{
    int units;
    puts("How many pounds to a firkin of butter?");
    scanf("%d", &units);
    while (units != 56)
        critic(&units);
    printf("You must have looked it up!\n");
    return 0;
}
void critic(int *us)
{
    puts("No luck, my friend. Try again.");
    scanf("%d", us);
}