/* repeat.c -- 带参数的main() */

#include <stdio.h>

int main(int argc, char *argv[]) //1
{
    int count;
    printf("argc[0] = %s\n", argv[0]);
    printf("The command line has %d arguments:\n", argc - 1); //1
    for (count = 1; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");
    return 0;
}

/*
ex:
$31-repeat Resisrance is fytile
The command line has 3 arguments:
1: Resisrance
2: is
3: fytile
*/
/*
C编译器允许main()没有参数或者有两个参数（一些实现允许main()有更 多参数，属于对标准的扩展）。
上面的例子中 argc 等于 4，因为如果系统允许（一些操作系统不允许这样），就把程序本身的名称赋给 argv[0]，然后把随后的第1个字符串赋给argv[1]，以此类推。
在我们的例子 中，有下面的关系： 
argv[0] 指向 repeat （对大部分系统而言）
argv[1] 指向Resistance 
argv[2] 指向is 
argv[3] 指向futile

另外 main也可以这样声明 
int main(int argc, char **argv) 
char **argv与char *argv[]等价。也就是说，argv是一个指向指针的指 针，它所指向的指针指向 char。

另外 许多环境（包括UNIX和DOS）都允许用双引号把多个单词 括起来形成一个参数。例如：
repeat "I am hungry" now
这行命令把字符串"I am hungry"赋给argv[1]，把"now"赋给argv[2]。
*/