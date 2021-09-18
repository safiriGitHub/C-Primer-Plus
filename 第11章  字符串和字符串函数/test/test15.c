/* 
15.使用字符分类函数实现atoi()函数。如果输入的字符串不是纯数字， 
该函数返回0。
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int atoi(char *str);
int pow_10(int n);

int main(void)
{
    printf("%d\n", atoi("fwe"));
    printf("%d\n", atoi("121fwe"));
    printf("%d\n", atoi("12f3we"));
    printf("%d\n", atoi("2fwe"));
    printf("%d\n", atoi("888"));
    return 0;
}

int atoi(char *str)
{
    int count = 0;
    int result = 0;
    while (isdigit(*(str+count)))
        count++;
    for (int i = 0; i < count; i++)
    {
        int d = str[i] - '0';
        result += d*pow_10(count-1-i);
    }
    return result;
}

int pow_10(int n)
{
    int sum = 1;
    for (int i = 0; i < n; i++) 
        sum *= 10;
    return sum;
}
