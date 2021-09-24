#include <stdio.h>
#include <string.h>


#define Q "His Hamlet was funny without being vulgar."
int main(void) {
    // 2.假设下列示例都是完整程序中的一部分，它们打印的结果分别是什么？
    printf("He sold the painting for $%2.2f.\n", 2.345e2);
    printf("%c%c%c\n", 'H', 105, '\41');
    printf("%s\nhas %zd characters.\n", Q, strlen(Q));
    printf("Is %2.2e the same as %2.2f?\n", 1201.0, 1201.0);

    //3.在第2题的c中，要输出包含双引号的字符串Q，应如何修改？
    printf("\"%s\" has %zd characters.\n", Q, strlen(Q));

    
}