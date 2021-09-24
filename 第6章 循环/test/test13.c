/* 
13.编写一个程序，创建一个包含8个元素的int类型数组，分别把数组元 
素设置为2的前8次幂。使用for循环设置数组元素的值，使用do while循环显 
示数组元素的值。
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    double array[8];
    for (int i = 0; i < 8; i++)
    {
        array[i] = pow(2, i+1);
    }
    
    int i = 0;
    do
    {
        printf("%.0lf\n", array[i++]);
    } while (8>i);
    
    return 0;
}