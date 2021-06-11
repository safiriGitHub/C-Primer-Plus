// predef.c -- 预定义宏和预定义标识符

#if __STDC_VERSION__ >= 201112L
	//支持C11及以后的版本 
#else
    #error Not C11
#endif
//如果编译器只支持旧标准，则会编译失败，如果支持C11标准，就能成 功编译。



#include <stdio.h>
void why_me();

int main()
{
    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The time is %s.\n", __TIME__);
    printf("The version is %ld.\n", __STDC_VERSION__); 
    printf("This is line %d.\n", __LINE__);
    printf("This function is %s\n", __func__);
    why_me(); 
    return 0;
}
void why_me()
{
    printf("This function is %s\n", __func__);
    printf("This is line %d.\n", __LINE__);
}
/*
The file is 12-predef.c.
The date is Jun 11 2021.
The time is 18:45:14.
The version is 201710.
This is line 12.
This function is main
This function is why_me
This is line 20.
*/

