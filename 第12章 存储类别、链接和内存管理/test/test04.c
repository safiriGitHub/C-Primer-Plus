/* 
4.在一个循环中编写并测试一个函数，该函数返回它被调用的次数。
 */
#include <stdio.h>

void func(void);
int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        func();
    }
    
    return 0;
}

void func(void)
{
    static int callback = 0;
    printf("The function call %d times.\n", ++callback);
}