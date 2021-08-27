/* 16.Daphne以10%的单利息投资了100美元（也就是说，每年投资获利相 
当于原始投资的10%）。Deirdre以 5%的复合利息投资了 100 美元（也就是 
说，利息是当前余额的 5%，包含之前的利息）。编写一个程序，计算需要 
多少年Deirdre的投资额才会超过Daphne，并显示那时两人的投资额。*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    double daphne = 100;
    double deirdre = 100;
    double daphne_grow = 0.1;
    double deirdre_grow = 0.05;
    double daphne_num;
    double deirdre_num;
    int year = 0;
    
    printf("year\tdaphne_num\tdeirdre_num\t\n");
    do
    {
        year++;
        daphne_num  = daphne + daphne*daphne_grow*year;
        deirdre_num = deirdre * pow((1+deirdre_grow), year);
        printf("%d\t%lf\t%lf\t\n", year, daphne_num, deirdre_num);
    } while (daphne_num > deirdre_num);
    printf("%d年Deirdre的投资额(%lf)才会超过Daphne(%lf)", year, deirdre_num, daphne_num);
    return 0;
}