/*9.分别写出读取下列各输入行的scanf()语句，并声明语句中用到变量和 数组。
a.101 
b.22.32 8.34E−09
c.linguini 
d.catch 22 
e.catch 22 （但是跳过catch）
*/

/*
10.什么是空白？ \0
11.下面的语句有什么问题？如何修正？ 
printf("The double type is %z bytes..\n", sizeof(double));
*/



#include <stdio.h>
int main(void) {
    int a;
    scanf("%d",&a);
    printf("%d\n", a);

    float b1;
    double b2;
    scanf("%f",&b1);
    scanf("%e",&b2);
    printf("%f", b1);
    printf("%e", b2);

    char c[30];
    scanf("%s", c);
    printf("%s",c);

    char d1[30];
    int d2;
    scanf("%s %d", d1, &d2);
    printf("%s %d", d1, d2);

    char c1[30];
    int c2;
    //scanf("%*s %d", c1, &c2); ❌
    scanf("%*s %d", &c2);
    printf("%s %d", c1, c2);

    printf("The double type is %zd bytes..\n", sizeof(double));
}
