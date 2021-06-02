/* strcnvt.c -- 使用 strtol() */
#include <stdio.h>
#include <stdlib.h>
#define LIM 30

char * s_gets(char * st, int n);

int main(void)
{
    char number[LIM];
    char *end;
    long value;

    puts("Enter a number (empty line to quit):");
    while (s_gets(number, LIM) && number[0] != '\0')
    {
        value = strtol(number, &end, 10); //十进制 //1
        printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        printf("字符串%s 转为10进制为: %ld, 在字符'%s'处结束，此字符的值为(%d)\n", number, value, end, *end);

        value = strtol(number, &end, 16); //十六进制
        printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        printf("字符串%s 转为16进制为: %ld, 在字符'%s'处结束，此字符的值为(%d)\n", number, value, end, *end);
        puts("Next number:");
    }
    puts("Bye!\n");
    return 0;
}

char * s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;
    if ((ret_val = fgets(st, n, stdin)) != NULL)
        while (st[i] != '\n' && st[i] != '\0')
            i++;
    if (st[i] == '\n')
        st[i] = '\0';
    else
        while (getchar() != '\n')
            continue;
    return ret_val;
}

/*
Enter a number (empty line to quit):
10
base 10 input, base 10 output: 10, stopped at  (0)
字符串10 转为10进制为: 10, 在字符处结束，此字符的值为(0)
base 16 input, base 10 output: 16, stopped at  (0)
字符串10 转为16进制为: 16, 在字符处结束，此字符的值为(0)
Next number:
10a
base 10 input, base 10 output: 10, stopped at a (97)
字符串10a 转为10进制为: 10, 在字符a处结束，此字符的值为(97)
base 16 input, base 10 output: 266, stopped at  (0)
字符串10a 转为16进制为: 266, 在字符处结束，此字符的值为(0)
Next number:
10atom
base 10 input, base 10 output: 10, stopped at atom (97)
字符串10atom 转为10进制为: 10, 在字符atom处结束，此字符的值为(97)
base 16 input, base 10 output: 266, stopped at tom (116)
字符串10atom 转为16进制为: 266, 在字符tom处结束，此字符的值为(116)
Next number:

Bye!
*/

/*
1.
&end : 剩下的不能转换的字符串的地址设置给end
比如，第一次输入的字符串 ”10“ ,转换十进制在读到空字符时结束，故&end是给end指向空字符的地址，*end是空字符的ASCII码
所以，此时打印 %s 转换 end 为空， %d 转换 *end 为ASCII码0

再比如，第三次输入的字符串 ”10atom“，转换为十六进制，在读到t字符时结束，故&end是给end指向字符't'的地址，*end是字符't'的ASCII码
所以，此时打印 %s 转换 end 为tom， %d 转换 *end 为ASCII码116

*/