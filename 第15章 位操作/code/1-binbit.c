/* binbit.c -- 使用位操作显示二进制 */

#include <stdio.h>
#include <limits.h>  // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节 的位数
char *itobs(int, char*);
void show_bstr(const char*);

int main(void)
{
    char bin_str[CHAR_BIT*sizeof(int)+1]; //1
    int number;

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input teminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Bye!"); 
    return 0;
}

char *itobs(int n, char* ps) //2
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size-1; i>=0; i--,n>>=1) //3
        ps[i]=(01&n)+'0'; 
    ps[size] = '\0';
    return ps;
}

/* 4位一组显示二进制字符串 */
void show_bstr(const char *str)
{
    int i = 0;
    while(str[i]) /* 不是一个空字符 */
    {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i]) 
            putchar(' ');
    }
}

/*1
使用limits.h中的CHAR_BIT宏，该宏表示char中的位数。 
sizeof运算符返回char的大小，所以表达式CHAE_BIT * sizeof(int)表示int类型的位数。
bin_str数组的元素个数是CHAE_BIT * sizeof(int) + 1，留出一个位置 给末尾的空字符。
*/

/*2
itobs()函数，首次执行for循环时，对01 & n求值。
01是一个八进制形式的掩码，该掩码除0号位是1之外，其他所有位都为0。
因此，01 & n就是n 最后一位的值。该值为0或1。
但是对数组而言，需要的是字符'0'或字符'1'。 该值加上'0'即可完成这种转换（假设按顺序编码的数字，如 ASCII）。
其结果存放在数组中倒数第2个元素中（最后一个元素用来存放空字符）。
顺带一提，用1 & n或01 & n都可以。我们用八进制1而不是十进制1，只 是为了更接近计算机的表达方式。用 0x1 & n 也可
*/

/*3
然后，循环执行i--和n >>= 1。
i--移动到数组的前一个元素，n >>= 1使n中的所有位向右移动一个位置。
进入下一轮迭代时，循环中处理的是n中新的最右端的值。
然后，把该值储存在倒数第3个元素中，以此类推。itobs() 函数用这种方式从右往左填充数组。
*/