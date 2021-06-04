// where.c -- 数据被储存在何处？

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char *pcg = "String Literal";
int main()
{
    int auto_store = 40;
    char auto_string[] = "Auto char Array";
    int *pi;
    char *pcl;
    pi = (int *)malloc(sizeof(int));
    *pi = 35;
    pcl = (char *)malloc(strlen("Dynamic String") + 1);
    strcpy(pcl, "Dynamic String");

    printf(" 静态存储类别：\n");
    printf(" static_store: %d at %p\n", static_store, &static_store); 
    printf(" %s at %p\n", pcg, pcg); 
    printf(" %s at %p\n", "Quoted String", "Quoted String");
    puts("--------------");

    puts("自动存储类别--------------");
    printf(" auto_store: %d at %p\n", auto_store, &auto_store);
    printf(" %s at %p\n", auto_string, auto_string); 

    puts("动态分配内存--------------");
    printf(" *pi: %d at %p\n", *pi, pi); 
    printf(" %s at %p\n", pcl, pcl); 
    
    free(pi);
    free(pcl);
    return 0;
}

/*
 静态存储类别：
 static_store: 30 at 0x104875038
 String Literal at 0x104870ec0
 Quoted String at 0x104870f2b
 --------------
 自动存储类别--------------
 auto_store: 40 at 0x7ffeeb392528
 Auto char Array at 0x7ffeeb392530
 动态分配内存--------------
 *pi: 35 at 0x7ff0be405aa0
 Dynamic String at 0x7ff0be405ab0

 如上所示，静态数据（包括字符串字面量）占用一个区域，
 自动数据占 用另一个区域，
 动态分配的数据占用第3个区域（通常被称为内存堆或自由内存）。
*/
