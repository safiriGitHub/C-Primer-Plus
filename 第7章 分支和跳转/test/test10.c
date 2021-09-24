/* 10.1988年的美国联邦税收计划是近代最简单的税收方案。它分为4个类 
别，每个类别有两个等级。 下面是该税收计划的摘要（美元数为应征税的收入）： 

例如，一位工资为20000美元的单身纳税人，应缴纳税费 
0.15×17850+0.28×（20000−17850）美元。编写一个程序，让用户指定缴纳 
税金的种类和应纳税收入，然后计算税金。程序应通过循环让用户可以多次 输入。
*/


#include <stdio.h>
#include <stdlib.h>

#define  SINGLE 17850	//
#define  HOLDER 23900	//
#define   MARRY 26750	//
#define DIVORCE 14875	//

#define BASE_TAX 0.15f
#define EXTRA_TAX 0.28f

void show_menu(void)
{
	system("cls");
	printf("Please select tax type, There are for type:\n");
	printf("1)Single\t2)House holder\n3)Married\t4)Divorced\n5)Quit\n");
	printf("Your selected type: ");
}

int main(void)
{
	char type;
	float salary;
	float tax, salary_taxed;
	printf("Please select tax type, There are for type:\n");
	printf("1)Single\t2)House holder\n3)Married\t4)Divorced\n5)Quit\n");
	printf("Please select your type: ");
	scanf("%c", &type);
	while (type != '5')
	{
		switch (type)
		{
		case '1':
			show_menu();
			printf("Type single.\nEnter your salsry: ");
			sscanf("%f", &salary);
			if (salary <= SINGLE)
			{
				tax = salary * BASE_TAX;
				salary_taxed = salary - tax;
			}
			else
			{
				tax = (SINGLE*BASE_TAX) + ((salary - SINGLE)*EXTRA_TAX);
				salary_taxed = salary - tax;
			}
			printf("Your salary is %.2f, tax is %.2f, after tax salary is %.2f\n",\
				salary, tax, salary_taxed);
			getchar();
			break;
		case '2':
			show_menu();
			printf("Type house holder.\nEnter your salary: ");
			sscanf("%f", &salary);
			if (salary <= HOLDER)
			{
				tax = salary * BASE_TAX;
				salary_taxed = salary - tax;
			}
			else
			{
				tax = HOLDER * BASE_TAX + ((salary - HOLDER)*EXTRA_TAX);
				salary_taxed = salary - tax;
			}
			printf("Your salary is %.2f, tax is %.2f, after tax salary is %.2f\n",\
				salary, tax, salary_taxed);
			getchar();
			break;
		case '3':
			show_menu();
			printf("Type married.\nEnter your salary: ");
			sscanf("%f", &salary);
			if (salary <= MARRY)
			{
				tax = salary * BASE_TAX;
				salary_taxed = salary - tax;
			}
			else
			{
				tax = (MARRY*BASE_TAX) + ((salary - MARRY)*EXTRA_TAX);
				salary_taxed = salary - tax;
			}
			printf("Your salary is %.2f, tax is %.2f, after tax salary is %.2f\n",\
				salary, tax, salary_taxed);
			getchar();
			break;
		case '4':
			show_menu();
			printf("Type divorce.\nEnter your salary: ");
			sscanf("%f", &salary);
			if (salary <= DIVORCE)
			{
				tax = salary * BASE_TAX;
				salary_taxed = salary - tax;
			}
			else
			{
				tax = DIVORCE * BASE_TAX + ((salary - DIVORCE)*EXTRA_TAX);
				salary_taxed = salary - tax;
			}
			printf("Your salary is %.2f, tax is %.2f, after tax salary is %.2f\n",\
				salary, tax, salary_taxed);
			getchar();
			break;
		case '5':
			break;
		default:
			printf("Error selected type.\n");
		}
		printf("Please select your type: ");
		sscanf("%c", &type, 1);
	}
	return 0;
}