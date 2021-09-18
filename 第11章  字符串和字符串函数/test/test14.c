/* 
14.编写一个通过命令行运行的程序计算幂。第1个命令行参数是double 
类型的数，作为幂的底数，第2个参数是整数，作为幂的指数。
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc > 2 && argv[1] && argv[2])
    {
        char *dou_end;
        double p1 = strtod(argv[1], &dou_end);
        int i1 = atoi(argv[2]);
        double result = pow(p1, i1);
        printf("%lf的%d次幂为：%lf", p1, i1, result);
    }

    return 0;
}