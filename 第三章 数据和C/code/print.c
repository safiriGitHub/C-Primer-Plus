#include <stdio.h>
#include <stdint.h>

int main(void) {
    // 该例子说明，使用错误的转换会得到意想不到的结果
    unsigned int un = 3000000000; /* int 为32位和short为16位的系统*/
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;
    printf("un = %u and not %d\n", un, un);
    //-- un = 3000000000 and not -1294967296
    //对于无符号变量 un，使用%d会生成负值！
    //其原因是，无符号值 3000000000 和有符号值−129496296 在系统内存中的内部表示完全相同（详见第15 章）。
    //因此，如果告诉printf()该数是无符号数，它打印一个值；如果告诉它 该数是有符号数，它将打印另一个值。
    //在待打印的值大于有符号值的最大值 时，会发生这种情况。对于较小的正数（如96），有符号和无符号类型的存 储、显示都相同。

    printf("end = %hd and %d\n", end, end);
    // end = 200 and 200
    /*
    第2行输出，对于short类型的变量end，在printf()中无论指定以short类型 （%hd）还是int类型（%d）打印，打印出来的值都相同。
    这是因为在给函 数传递参数时，C编译器把short类型的值自动转换成int类型的值。
    你可能会 提出疑问：为什么要进行转换？h修饰符有什么用？
    第1个问题的答案是， int类型被认为是计算机处理整数类型时最高效的类型。因此，在short和int类 型的大小不同的计算机中，用int类型的参数传递速度更快。
    第2个问题的答 案是，使用h修饰符可以显示较大整数被截断成 short 类型值的情况。
    */

    printf("big = %ld and not %hd\n", big, big);
    // big = 65537 and not 1
    /*
    第 3 行 输出就演示了这种情况。把 65537 以二进制格式写成一个 32 位数是 00000000000000010000000000000001。
    使用%hd，printf()只会查看后 16 位，所以显示的值是 1。
    */
    printf("verybig = %lld and not %ld\n", verybig, verybig);
    //verybig = 12345678908642 and not 12345678908642
    //与此类似，输出的最后一行先显示了verybig的完整 值，然后由于使用了%ld，printf()只显示了储存在后32位的值。
    return 0;
}