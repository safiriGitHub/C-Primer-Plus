/* 
5.修改程序清单8.4的猜数字程序，使用更智能的猜测策略。例如，程序 
最初猜50，询问用户是猜大了、猜小了还是猜对了。如果猜小了，那么下一 
次猜测的值应是50和100中值，也就是75。如果这次猜大了，那么下一次猜 
测的值应是50和75的中值，等等。使用二分查找（binary search）策略，如 
果用户没有欺骗程序，那么程序很快就会猜到正确的答案。
 */

#include <stdio.h>

int main(void)
{
    int start = 1;
    int end = 100;
    int guess = 50;
    int sum = 0;
    char ch;
    printf("我测测你得年龄:%d?\n", guess);
    printf("%d岁是大于还是小于你得年龄，猜对了输入'y',大于输入\"l\",小于输入\"s\"\n", guess);

    while ((ch = getchar()) != 'y')
    {
        sum++;
        switch (ch)
        {
        case 's':
        case 'S':
            start = guess + 1;
            guess = (start+end) / 2;
            break;
        case 'l':
        case 'L':
            end = guess - 1;
            guess = (start+end) / 2;
            break;
        default:
            break;
        }
        printf("我测测你得年龄:%d?\n", guess);
        printf("%d岁是大于还是小于你得年龄，猜对了输入'y',大于输入\"l\",小于输入\"s\"\n", guess);
    }
    if (ch == 'y' || ch == 'Y')
    {
        printf("你得年龄是%d", guess);
    }
    
    return 0;
}