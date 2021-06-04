/* r_drive0.c -- 测试rand() 函数 */
// 与rand0.c 一起编译
#include <stdio.h>
extern unsigned int rand0(void);

int main(void)
{
    for(int count = 0; count < 5; count++)
        printf("%d\n", rand0());
    return 0;
}

/*
多文件编译 
gcc 7-rand0.c 8-r_drive0.c -o 777d
打印
16838
5758
10113
17515
31051

多次运行程序，会发现这输出完全相同，这体现了“伪随机”的一个方面。
因为每次主程序运行，都开始于相同的种子1。
可以引入另一个函数srand1()重置种子来 解决这个问题。
*/