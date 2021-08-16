/* 6.1个水分子的质量约为3.0×10−23克。1夸脱水大约是950克。
编写一个 程序，提示用户输入水的夸脱数，并显示水分子的数量。 */

#include <stdio.h>

#define  ONE_H2O_WEIGHT 3.0e-23

int main(void)
{
    float quart, quantity;
    printf("Enter how many quart:");
    scanf("%f", &quart);
    quantity = quart * 950 / ONE_H2O_WEIGHT;
    printf("There are %e molecule.\n", quantity);
    
    return 0;
}