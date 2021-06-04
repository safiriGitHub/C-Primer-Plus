/* dyn_arr.c -- 动态分配数组 */

#include <stdio.h>
#include <stdlib.h>  /* 为 malloc()、free()提供原型 */

int main(void)
{
    double *ptd;
    int max;
    int number;
    int i = 0;
    puts("What is the maximum number of type double entries?");
    if (scanf("%d", &max) != 1)
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }
    ptd = (double *)malloc(max*sizeof(double)); //1
    if (ptd == NULL) //2
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }
    /* ptd 现在指向有max个元素的数组 */
    puts("Enter the values (q to quit):");
    while (i < max && scanf("%lf", &ptd[i]) == 1)
    {
        ++i;
    }
    printf("Here are your %d entries:\n", number = i);
    for (i = 0; i < number; i++) 
    {
        printf("%7.2f ", ptd[i]); 
        if (i % 7 == 6) 
        putchar('\n'); 
    }

    if (i % 7 != 0) 
        putchar('\n'); 
    puts("Done.");
    
    free(ptd); //3
    return 0;
    
}

/*
1:
在C中，不一定要使用强制类型转换(double *)，但是在C++中必须使 用。
所以，使用强制类型转换更容易把C程序转换为C++程序。


2:
malloc()可能分配不到所需的内存。在这种情况下，该函数返回空指 针，程序结束：

3:
一些操作系统在程序结束时会自动 释放动态分配的内存，但是有些系统不会。
为保险起见，请使用free()，不 要依赖操作系统来清理。
*/
