/* 4.使用嵌套循环，按下面的格式打印字母： 
A
BC
DEF 
GHIJ 
KLMNO 
PQRSTU 
如果你的系统不使用以数字顺序编码的代码，请参照练习3的方案解决。 
*/

#include <stdio.h>

int main(void)
{
    char ch = 'A';
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < i+1; j++)
        {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    
    return 0;
}