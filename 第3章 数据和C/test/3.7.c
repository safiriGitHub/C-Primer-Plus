/* 7.
1英寸相当于2.54厘米。编写一个程序，提示用户输入身高（/英寸），然后以厘米为单位显示身高。 */

#include <stdio.h>

#define YINGCUN_TO_CM 2.54

int main(void)
{
    float h, hcm;
    printf("请输入身高英寸：");
    scanf("%f", &h);
    hcm = h * YINGCUN_TO_CM;
    printf("你的身高为%.2f厘米", hcm);

    return 0;
}