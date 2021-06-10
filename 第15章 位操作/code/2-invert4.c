/*invert4.c -- 使用位操作显示二进制 
我们来看另一个例子。这次要编写的函数用于切换一个值中的后 n 位， 待处理值和 n 都是函数的参数。 
～运算符切换一个字节的所有位，而不是选定的少数位。但是，^运算 符（按位异或）可用于切换单个位。
假设创建了一个掩码，把后n位设置为1，其余位设置为0。
然后使用^组合掩码和待切换的值便可切换该值的最后n 位，而且其他位不变。
*/
#include <stdio.h>
#include <limits.h>

char *itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int main(void)
{
    char bin_str[CHAR_BIT*sizeof(int)+1];
    int number; 
    puts("Enter integers and see them in binary."); 
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d is\n", number); 
        show_bstr(bin_str); 
        putchar('\n');
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number, bin_str));
        putchar('\n');
    }
    puts("Bye!");
    return 0;
}

char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT*sizeof(int);
    for(i = size-1; i >= 0; i--, n>>=1)
        ps[i] = (01&n)+'0';
    ps[size] = '\0';
    return ps;
}

//以4位为一组，显示二进制字符串
void show_bstr(const char *str)
{
    int i = 0;
    while (str[i]) /*不是空字符*/
    {
        putchar(str[i]);
        if (++i%4 == 0 && str[i])
            putchar(' ');
    }
}

int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1;
    while (bits-- > 0) //1
    {
        mask |= bitval;
        bitval <<= 1;
    }
    return num^mask;
}

/*
while循环用于创建所需的掩码。
最初，mask的所有位都为0。第1轮循 环将mask的0号位设置为1。
然后第2轮循环将mask的1号位设置为1，以此类推。循环bits次，mask的后bits位就都被设置为1。
最后，num ^ mask运算即得 所需的结果。
*/