/* fgets1.c -- 使用fgets() 和 fputs() */

#include <stdio.h>
#define STLEN 14

int main(void)
{
    char words[STLEN];
    puts("Enter a string, please.");
    fgets(words, STLEN, stdin);//fgets()函数的第3 个参数指明要读入的文件。如果读入从键盘输入的数 据，则以stdin（标准输入）作为参数
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout); //fputs()函数的第2个参数指明它要写入的文件。如果要显示在 计算机显示器上，应使用stdout（标准输出）作为该参数

    puts("Enter another string, please."); 
    fgets(words, STLEN, stdin); 
    printf("Your string twice (puts(), then fputs()):\n"); 
    puts(words); 
    fputs(words, stdout);   
    puts("Done.");
    return 0;
}
/*
Enter a string, please.
apple pie
Your string twice (puts(), then fputs()):
apple pie

apple pie
Enter another string, please.
strawberry shortcake
Your string twice (puts(), then fputs()):
strawberry sh
strawberry shDone.
*/

/*
因为 fgets()函数把换行符放在字符串的末尾（假设输入行不溢出），
通常要与 fputs()函数配对使用，除非该函数不在字符串末尾添加换行符。

第1行输入，apple pie，比fgets()读入的整行输入短，因此，apple pie\n\0 被储存在数组中。
所以当puts()显示该字符串时又在末尾添加了换行符，因此apple pie后面有一行空行。
因为fputs()不在字符串末尾添加换行符，所以并未打印出空行。

第2行输入，strawberry shortcake，
超过了大小的限制，所以fgets()只读入了13个字符，并把strawberry sh\0 储存在数组中。
puts()函数会在待输出字符串末尾添加一个换行符，故第一个 strawberry sh 换行了
而fputs()不会这样做，故 Done 跟在后面没有换行

*/

