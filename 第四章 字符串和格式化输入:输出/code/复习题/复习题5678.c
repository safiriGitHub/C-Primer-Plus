/*5.假设一个程序的开头是这样： 
#define BOOK "War and Peace" int main(void) 
{float cost =12.99; float percent = 80.0; 
请构造一个使用BOOK、cost和percent的printf()语句，打印以下内容： 
This copy of "War and Peace" sells for $12.99. That is 80% of list.*/

#include <stdio.h>
#define BOOK "War and Peace"
int main(void) {
    float cost = 12.99;
    float percent = 80.0;
    printf("This copy of \"%s\" sells for $%.2f. That is %.0f%% of list.", BOOK, cost, percent);

    /*6.打印下列各项内容要分别使用什么转换说明？ 
    a.一个字段宽度与位数相同的十进制整数 %d
    b.一个形如8A、字段宽度为4的十六进制整数 %4x
    c.一个形如232.346、字段宽度为10的浮点数 %10.3f
    d.一个形如2.33e+002、字段宽度为12的浮点数  %12.2e
    e.一个字段宽度为30、左对齐的字符串  %-30s
    */


    /*
    7.打印下面各项内容要分别使用什么转换说明？ 
    a.字段宽度为15的unsigned long类型的整数 %15uL ❌  %15lu
    b.一个形如0x8a、字段宽度为4的十六进制整数 %4x ❌ %#4x
    c.一个形如2.33E+02、字段宽度为12、左对齐的浮点数  %-12.2e
    d.一个形如+232.346、字段宽度为10的浮点数  %+10.3f
    e.一个字段宽度为8的字符串的前8个字符 %8.8s
    */


    /*
    8.打印下面各项内容要分别使用什么转换说明？ 
    a.一个字段宽度为6、最少有4位数字的十进制整数 %6.4d
    b.一个在参数列表中给定字段宽度的八进制整数 %*o
    c.一个字段宽度为2的字符  %2c
    d.一个形如+3.13、字段宽度等于数字中字符数的浮点数 %+.2f ❌  %+0.2f
    e.一个字段宽度为7、左对齐字符串中的前5个字符 %-7.5s
    */ 
   


}