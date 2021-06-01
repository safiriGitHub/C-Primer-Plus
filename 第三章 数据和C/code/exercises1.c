//1.通过试验（即编写带有此类问题的程序）观察系统如何处理整数上溢、浮点数上溢和浮点数下溢的情况。
#include <stdio.h>

int main(void) {
    signed char maxa = 128;
    printf("signed char 上溢为%d\n", maxa+1);
    //signed char 上溢为-127% 

    double maxd = 3.6E100;
    printf("maxd--%f", maxd);
  
    return 0;
}