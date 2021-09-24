/* 
11.ABC 邮购杂货店出售的洋蓟售价为 2.05 美元/磅，甜菜售价为 1.15 
美元/磅，胡萝卜售价为 1.09美元/磅。在添加运费之前，100美元的订单有 
5%的打折优惠。少于或等于5磅的订单收取6.5美元的运费和包装费，5磅～ 
20磅的订单收取14美元的运费和包装费，超过20磅的订单在14美元的基础上 
每续重1磅增加0.5美元。编写一个程序，在循环中用switch语句实现用户输 
入不同的字母时有不同的响应，即输入a的响应是让用户输入洋蓟的磅数，b 
是甜菜的磅数，c是胡萝卜的磅数，q 是退出订购。程序要记录累计的重 量。
即，如果用户输入 4 磅的甜菜，然后输入 5磅的甜菜，程序应报告9磅 的甜菜。
然后，该程序要计算货物总价、折扣（如果有的话）、运费和包装 
费。随后，程序应显示所有的购买信息：物品售价、订购的重量（单位： 
磅）、订购的蔬菜费用、订单的总费用、折扣（如果有的话）、运费和包装 
费，以及所有的费用总额。
 */

#include <stdio.h>

#define ARTI 2.05f // 洋蓟
#define BEET 1.15f // 甜菜
#define CARROT 1.09f // 胡萝卜
#define DISCOUNT 0.05f // 每百元优惠

char menu(void);
float get_weight(void);

int main(void)
{
    float arti = 0;
    float beet = 0;
    float carrot = 0;
    char choice;
    float weight, amount, rebate, freight; // 重量 数量 折扣 运费
    float total;

    choice = menu();
    if (choice == 'e')
    {
        printf("退出了\n");
        return 0;
    }
    
    while (choice != 'e')
    {
        switch (choice)
        {
        case 'a':
            arti += get_weight();
            break;
        case 'b':
            beet += get_weight();
            break;
        case 'c':
            carrot += get_weight();
            break;
        case 'e':
            break;
        default:
            printf("输入错误，请重试\n");
            break;
        }
        choice = menu();
    }
    
    amount = arti*ARTI + beet*BEET + carrot*CARROT;
    weight = arti + beet + carrot;

    if (amount >= 100)
    {
        rebate = amount * DISCOUNT;
    }
    else 
    {
        rebate = 0;
    }

    if (weight <= 5)
    {
        freight = 6.5f;
    }
    else if (weight > 5 && weight <= 20)
    {
        freight = 14;
    }
    else 
    {
        freight = 14 + (weight-20)*0.5f;
    }
    total = amount + freight - rebate;
    
    printf("商品价格：\n洋蓟%.2f/磅，甜菜%.2f/磅，胡萝卜%.2f/磅\n", ARTI, BEET, CARROT);
    printf("您购买了洋蓟%.2f磅，甜菜%.2f磅，胡萝卜%.2f磅\n", arti, beet, carrot);
    printf("订单总重量%g磅，折扣%g$，商品花费%g$，运费%g$，合计%g$\n", 
        weight, rebate, amount, freight, total);
    return 0;
}

char menu(void)
{
    printf("***********************\n");
    printf("选择商品：\n");
    printf("a)洋蓟 b)甜菜 c)胡萝卜 e)exit\n");
    printf("***********************\n");
    printf("输入你要买的选项：（a/b/c）e退出\n");
    char ch;
    if (scanf("%c", &ch) != 1)
        printf("输入错误");
    return ch;
}

float get_weight(void)
{
    float weight;
    printf("输入你要买的磅数：");
    if (scanf("%f", &weight) != 1)
        printf("输入错误");
    return weight;
}