// intconv.c -- 一些不匹配的整形转换
#include <stdio.h>
#define PAGES 336
#define WORDS 65618

int main(void) {
    short num = PAGES;
    short mnum = -PAGES;
    printf("num as short and unsigned short: %hd %hu\n", num, num);
    printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum);
    printf("num as int and char: %d %c\n", num, num);
    printf("WORDS as int, short, and char: %d %hd %c\n", WORDS, WORDS, WORDS);
    return 0;
    /*
        num as short and unsigned short: 336 336  正确输出
        -num as short and unsigned short: -336 65200 
        %u的输出结果为65200，而非336。原因：short int大小是2字节，系统使用二进制补码来表示有符号整数。
        这种方法，数字0~32767代表他们本身，而数字32768~65535表示负数。65535表示-1，65534表示-2，以此类推。
        -336表示为65200（即，65536-336）。所以有符号int时，65200代表-336；解释成无符号int时，65200则代表65200
        尽管并非所有 的系统都使用这种方法来表示负整数，但要注意一点：别期望用%u转换说 明能把数字和符号分开。

        num as int and char: 336 P
        第3行演示了如果把一个大于255的值转换成字符会发生什么情况。
        在我们的系统中，short int是2字节，char是1字节。
        当printf()使用%c打印336时， 它只会查看储存336的2字节中的后1字节。
        这种截断（见图4.8）相当于用一个整数除以256，只保留其余数。
        在这种情况下，余数是80，对应的ASCII值 是字符P。
        用专业术语来说，该数字被解释成“以256为模”（modulo 256）， 即该数字除以256后取其余数。
        
        WORDS as int, short, and char: 65618 82 R
        82： short为2个字节 -->65618除以65536的余数
        R: modulo 256
    */
}
