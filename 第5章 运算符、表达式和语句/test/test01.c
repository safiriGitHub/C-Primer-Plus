/*1.编写一个程序，把用分钟表示的时间转换成用小时和分钟表示的时间。
使用#define或const创建一个表示60的符号常量或const变量。
通过while 循环让用户重复输入值，直到用户输入小于或等于0的值才停止循环。*/

#include <stdio.h>

#define HOUR_MIN 60
const int Hd = 60;

int main(void) {
    int mins;

    printf("请输入分钟数(输入小于等于0的数退出)：");
    while (scanf("%d", &mins) != 0)
    {
        if (mins <= 0) break;
        int show_hours;
        int show_mins;
        show_hours = mins / HOUR_MIN;
        show_mins = mins % Hd;
        printf("%d分钟是--%d小时%d分钟\n", mins, show_hours, show_mins);
        printf("请输入分钟数(输入小于等于0的数退出)：");
    }
    
    return 0;
}