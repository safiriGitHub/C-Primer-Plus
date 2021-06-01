/*sum_arr2.c -- 数组元素之和*/

#include <stdio.h>
#define SIZE 10

int sump(int *start, int *end);
int main(void)
{
    int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long answer;
    answer = sump(marbles, marbles + SIZE);
    printf("marbles数组元素之和等于 %ld", answer);
    return 0;
}

/*使用指针算法*/
int sump(int *start, int *end)
{
    int total = 0;
    while (start < end) //1
    {
        total += *start; // 把数组元素的值加起来
        start++; // 让指针指向下一个元素
        //2
        // total += *start++;
    }
    return total;
}

/*1
循环最后处理的一个元素是end所指向位置的前一个元素。
这意味着end指向的位置实际上在数组最后一个元素的后面。
C保证在给数组分配空间时，指向数组后面第一个位置的指针仍是有效的指针。
这使得 while循环的测试条件是有效的，因为 start在循环中最后的值是end。
注意，使用这种“越界”指针的函数调用更为简洁：
 answer = sump(marbles, marbles + SIZE);
*/

/*2
还可以把循环体压缩成一行代码：
    total += *start++;
一元运算符*和++的优先级相同，但结合律是从右往左，所以start++先 求值，然后才是*start。
使用start++而不是++start，意味着先把指针指向位置上的值加到total上，然 后再递增指针
*/