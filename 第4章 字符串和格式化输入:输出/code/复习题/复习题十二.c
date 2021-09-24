//12.假设要在程序中用圆括号代替花括号，以下方法是否可行？ 
// #define ( { 
// #define ) }
//不可行，已经报错了

//12.可以分别把(和)替换成{和}。
//但是预处理器无法区分哪些圆括号应替 换成花括号，
//哪些圆括号不能替换成花括号。因此， 
#define ( { 
#define ) } 
// int main(void) 
// (printf("Hello, O Great One!\n"); )将变成：

 int main{void} 
 {
    printf{"Hello, O Great One!\n"};
 }

 在当前编译器中不可行
