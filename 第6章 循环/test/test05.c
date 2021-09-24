/* 5.编写一个程序，提示用户输入大写字母。使用嵌套循环以下面金字塔 
型的格式打印字母：
A
ABA 
ABCBA 
ABCDCBA 
ABCDEDCBA 
打印这样的图形，要根据用户输入的字母来决定。例如，上面的图形是 
在用户输入E后的打印结果。 
提示：用外层循环处理行，每行使用3个内层循环，分别处理空格、以升序打印字母、以降序打印字母。
如果系统不使用ASCII或其他以数字顺序 编码的代码，请参照练习3的解决方案。 */

#include <stdio.h>

int main(void)
{
    char ch_h = 'A';
    for (size_t i = 0; i < 6; i++)
    {
        for (char j = 'A'; j < ch_h; j++)
        {
            printf("%c", j);
        }
        
        for (char j = ch_h; j >= 'A'; j--)
        {
            printf("%c", j);
        }
        ch_h++;
        printf("\n");
    }
    
    return 0;
}