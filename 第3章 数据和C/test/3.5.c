/* 5.一年大约有3.156×107秒。编写一个程序，提示用户输入年龄，然后显 示该年龄对应的秒数。 */
#include <stdio.h>

#define YEAR_SEC 3.156e7
int main(void) {
     int second, year;
     printf("please, Enter your age:");
     scanf("%d", &year);
     second = year * YEAR_SEC;
     printf("Your age is: %d years old.\n", year);
     printf("And you are %e second old.\n", second);

     return 0;
}