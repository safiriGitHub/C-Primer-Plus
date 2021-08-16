/* 8.在美国的体积测量系统中，1品脱等于2杯，1杯等于8盎司，
1盎司等 于2大汤勺，1大汤勺等于3茶勺。
编写一个程序，提示用户输入杯数，并以 品脱、盎司、汤勺、茶勺为单位显示等价容量。
思考对于该程序，为何使用 浮点类型比整数类型更合适？ */
/* 
欧美日常使用的度量衡单位是常衡盎司（avoirdupois ounce），而欧美黄 
金市场上使用的黄金交易计量单位是金衡盎司（troy ounce）。
国际黄金市 场上的报价，其单位“盎司”都指的是黄金盎司。常衡盎司属英制计量单位， 
做重量单位时也称为英两。相关换算参考如下：1常衡盎司 = 28.350克，1金 衡盎司 = 31.104克，16常衡盎司 = 1磅。
该程序的单位转换思路是：把磅换 算成金衡盎司，即28.350÷31.104×16=14.5833。
 *//*  */
#include <stdio.h>

#define PINT_CUP 2
#define CUP_OUNCE 8
#define OUNCE_SPOON 2
#define SPOON_TEA 3

int main(void)
{
    float pint;
    float cup;
    float ounce;
    float spoon;
    float tea_spoon;

    printf("Enter how many cup:");
    scanf("%f", &cup);
    pint = cup / PINT_CUP;
    ounce = cup * CUP_OUNCE;
    spoon = ounce * OUNCE_SPOON;
    tea_spoon = spoon * SPOON_TEA;

    printf("%.0f cup equals %.1f pint, %.1f ounce, %.1f spoon, %.1f tea spoon.\n", cup, pint, ounce, spoon, tea_spoon);
    return 0;
}