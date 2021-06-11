// useheader.c -- 使用 names_st 结构
#include <stdio.h>
#include "6-names_st.h"
// 记住要链接 names_st.c

int main(void)
{
    names candidate;
    get_names(&candidate);
    printf("Let's welcome");
    show_names(&candidate);
    printf(" to this program!\n"); 
    return 0;
}
//两个源代码文件都使用names_st类型结构，所以它们都必须包含 names_st.h头文件。 
// 必须编译和链接names_st.c和useheader.c源代码文件。 
// 声明和指令放在names_st.h头文件中，函数定义放在names_st.c源代码文 件中。

