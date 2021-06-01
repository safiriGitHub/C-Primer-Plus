#include <stdio.h> 
#include <string.h>

int main(void) 
{
    printf("strcmp(\"A\", \"A\") is "); 
    printf("%d\n", strcmp("A", "A")); 
    printf("strcmp(\"A\", \"B\") is "); 
    printf("%d\n", strcmp("A", "B")); 
    printf("strcmp(\"B\", \"A\") is "); 
    printf("%d\n", strcmp("B", "A")); 
    printf("strcmp(\"C\", \"A\") is "); 
    printf("%d\n", strcmp("C", "A")); 
    printf("strcmp(\"Z\", \"a\") is "); 
    printf("%d\n", strcmp("Z", "a")); 
    printf("strcmp(\"apples\", \"apple\") is ");
    printf("%d\n", strcmp("apples", "apple")); 
    return 0; 
}

/*
ASCII标准规定，在字母表中，如果第1个字符串在第2个字符串前面， 
strcmp()返回一个负数，一般为-1
如果两个字符串相同，strcmp()返回0；
如果第1个字 符串在第2个字符串后面，strcmp()返回正数，一般为1

然而，返回的具体值取决于实 现。

strcmp()函数比较的是字符串，不是字符，所以其参数应该是字符串 （如"apples"和"A"），而不是字符（如'A'）。
*/
