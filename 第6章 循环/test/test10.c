/* 10.编写一个程序，要求用户输入一个上限整数和一个下限整数，计算 
从上限到下限范围内所有整数的平方和，并显示计算结果。然后程序继续提 
示用户输入上限和下限整数，并显示结果，直到用户输入的上限整数小于下 
限整数为止。程序的运行示例如下： 

Enter lower and upper integer limits: 5 9 
The sums of the squares from 25 to 81 is 255 
Enter next set of limits: 3 25 
The sums of the squares from 9 to 625 is 5520 
Enter next set of limits: 5 5 
Done */
#include <stdio.h>

long caculate(int a, int b);

int main(void)
{
    int a, b;
    printf("Enter lower and upper integer limits :");
    while (scanf("%d %d", &a, &b) != 0)
    {
        printf("The sums of the squares from %d to %d is %ld\n", a, b, caculate(a, b));
        printf("Enter next set of limits:");
    }
    
    return 0;
}

long caculate(int a, int b)
{
    long sum;
    for (int i = a; i <= b; i++)
    {
        sum = sum+i*i;
    }
    return sum;
}