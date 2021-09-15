/* 
10.编写一个函数，把两个数组中相对应的元素相加，然后把结果储存 
到第 3 个数组中。也就是说，如果数组1中包含的值是2、4、5、8，数组2中 
包含的值是1、0、4、6，那么该函数把3、4、9、14赋给第3个数组。函数接 
受3个数组名和一个数组大小。在一个简单的程序中测试该函数。
 */

#include <stdio.h>

#define ROW 4
void addcopy(int arr1[], int arr2[], int arr3[], int row);
int main(void)
{
    int arr1[ROW] = {2,4,5,8};
    int arr2[ROW] = {1,0,4,6};
    int arr3[ROW];

    addcopy(arr1, arr2, arr3, ROW);
    for (int i = 0; i < ROW; i++)
    {
        printf("%d ", arr3[i]);
    }
    
    return 0;
}

void addcopy(int arr1[], int arr2[], int arr3[], int row)
{
    for (int i = 0; i < row; i++)
    {
        arr3[i] = arr1[i] + arr2[i];
    }
}
