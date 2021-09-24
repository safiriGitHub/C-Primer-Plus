//2.编写一个程序，要求提示输入一个ASCII码值（如，66），然后打印 输入的字符。
#include <stdio.h>

int main(void) {
    int input_char_code;
    printf("请输入一个ASCII码值（如，66）：");
    printf("___\b\b\b");
    scanf("%d", &input_char_code);
    printf("ASCII码为%c\n", input_char_code);

    return 0;
}