/* escape.c -- 使用转移序列 */ 
// 了解
#include <stdio.h> 
int main(void) {
    float salary;
    printf("\aEnter your desired monthly salary:"); /* 1 */
    printf(" $_______\b\b\b\b\b\b\b");              /* 2 */
    scanf("%f", &salary);
    printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12.0); /* 3 */
    printf("\rGee!\n");                                                  /* 4 */
    int f = 040;

    int imate = 2; 
    long shot = 53456; 
    char grade = 'A'; 
    float log = 2.71828; 
    printf("The odds against the %d were %ld to 1.\n", imate, shot); 
    printf("A score of %f is not an %c grade.\n", log, grade); 

    char ch = '\r';
    printf("十进制-%x\n",ch);
    char ch2 = 13;
    printf("ch2-%c", ch2);

    return 0;

}

// 3:因为这条printf()语句中没有使用换行字符，所以光标停留在最后的点号 后面。
// 4:第4条printf()语句以\r开始。这使得光标回到当前行的起始处。然后打印 Gee!，接着\n使光标移至下一行的起始处。

/*屏幕最后显示的内容应该是：
Enter your desired monthly salary: $10000__

Gee!    $10000.00 a month is $120000.00 a year.
*/