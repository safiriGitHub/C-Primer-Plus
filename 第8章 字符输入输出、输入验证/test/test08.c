/* 
8.编写一个程序，显示一个提供加法、减法、乘法、除法的菜单。获得 
用户选择的选项后，程序提示用户输入两个数字，然后执行用户刚才选择的 
操作。该程序只接受菜单提供的选项。程序使用float类型的变量储存用户输 
入的数字，如果用户输入失败，则允许再次输入。进行除法运算时，如果用 
户输入0作为第2个数（除数），程序应提示用户重新输入一个新值。该程序 
的一个运行示例如下：

Enter the operation of your choice: 
a. add s. subtract 
m. multiply d. divide 
q. quit 
a

Enter first number: 22 .4 
Enter second number: one 
one is not an number. 
Please enter a number, such as 2.5, -1.78E8, or 3: 1 
22.4 + 1 = 23.4 

Enter the operation of your choice: 
a. add s. subtract 
m. multiply d. divide
q. quit 
d

Enter first number: 18.4 
Enter second number: 0 
Enter a number other than 0: 0.2 
18.4 / 0.2 = 92 
Enter the operation of your choice: 
a. add s. subtract 
m. multiply d. divide 
q. quit 
q
Bye.
 */

#include <stdio.h>
#include <stdbool.h>

char menu(void);
float enter_first(void);
float enter_second(void);

int main(void)
{
    char choice;
    choice = menu();
    if (choice == 'q')
        return 0;

    float first = 0.0f;
    float second = 0.0f;
    float result = 0.0f;
    first = enter_first();
    second = enter_second();
    while (choice == 'd' && second == 0.0)
    {
        printf("除数不能为0");
        second = enter_second();
    }
    
    switch (choice)
    {
    case 'a':
        result = first + second;
        printf("%f+%f=%f", first, second, result);
        break;
    case 's':
        result = first - second;
        printf("%f-%f=%f", first, second, result);
        break;
    case 'm':
        result = first * second;
        printf("%f*%f=%f", first, second, result);
        break;
    case 'd':
        result = first / second;
        printf("%f/%f=%f", first, second, result);
        break;
    default:
        break;
    }
    

    return 0;
}

char menu(void)
{
    char ch;
    bool input_bool = false;

    do
    {
        printf("Enter the operation of your choice: "
            "\na. add s. subtract "
            "\nm. multiply d. divide" 
            "\nq. quit \n");
        scanf("%c", &ch);
        if (ch == 'a' || ch == 's' || ch == 'm' || ch == 'd' || ch == 'q')
        {
            input_bool = true;
        }
        else
        {
            input_bool = false;
            printf("Enter error, 请输入正确选项\n");
        }
    } while (!input_bool);
    
    return ch;
    
}

float enter_first(void)
{
    float first = 0.0;
    printf("Enter first number: ");
    while (scanf("%f", &first) != 1)
    {   
        printf("输入错误，Enter first number: ");
    }
    return first;
}

float enter_second(void)
{
    float second = 0.0;
    printf("Enter second number: ");
    while (scanf("%f", &second) != 1)
    {   
        printf("输入错误，Enter second number: ");
    }
    return second;
}