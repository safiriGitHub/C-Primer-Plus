// 使用循环和递归计算阶乘
#include <stdio.h>

long fact(int n);
long rfact(int n);

int main(void) {
    int num;
    printf("Enter a value in the range 0-12 (q to quit):\n");
    while (scanf("%d", &num) == 1)
    {
        if (num < 0 || num > 12)
        {
            printf("只能输入0-12的数");
        }
        else
        {
            printf("循环：%d 阶乘 = %ld\n", num, fact(num));
            printf("阶乘：%d 阶乘 = %ld\n", num, rfact(num));
        }
        printf("Enter a value in the range 0-12 (q to quit):\n");
    }
    printf("Bye.\n");
    return 0;
}

long fact(int n) {
    long ans;
    for (ans = 1; n > 1; n--)
    {
        ans *= n;
    }
    return ans;
}

long rfact(int n) {
    long ans;
    if (n > 0)
    {
        ans = n*rfact(n-1);
    }else {
        ans = 1;
    }
    return ans;
}