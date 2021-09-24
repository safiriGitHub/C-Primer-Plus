/* 
9.编写一个符合以下描述的函数。首先，询问用户需要输入多少个单 
词。然后，接收用户输入的单词，并显示出来，使用malloc()并回答第1个问 
题（即要输入多少个单词），创建一个动态数组，该数组内含相应的指向 
char的指针（注意，由于数组的每个元素都是指向char的指针，所以用于储 
存malloc()返回值的指针应该是一个指向指针的指针，且它所指向的指针指
向char）。在读取字符串时，该程序应该把单词读入一个临时的char数组， 
使用malloc()分配足够的存储空间来储存单词，并把地址存入该指针数组 
（该数组中每个元素都是指向 char 的指针）。然后，从临时数组中把单词 
拷贝到动态分配的存储空间中。因此，有一个字符指针数组，每个指针都指 
向一个对象，该对象的大小正好能容纳被储存的特定单词。下面是该程序的 
一个运行示例：
How many words do you wish to enter? 5 
Enter 5 words now: 
I enjoyed doing this exerise 
Here are your words: 
I
enjoyed 
doing 
this 
exercise
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int words_num = 0;
    char **words_arr;

    printf("How many words do you wish to enter? \n");
    while (scanf("%d", &words_num) == 1 && words_num > 0)
    {
        printf("Enter %d words now: \n", words_num);
        int count = 0;
        words_arr = (char **)malloc(sizeof(char**) * words_num);
        if (words_arr == NULL)
        {
            printf("指针错误");
            exit(EXIT_FAILURE);
        }
        
        while (count < words_num)
        {
            char *str = (char *)malloc(sizeof(char*));;
            if (scanf("%s", str) == 1)
            {
                *(words_arr+count) = str;
                count++;
            }
        }
        
        printf("Here are your words: \n");
        for (int i = 0; i < words_num; i++)
        {
            printf("%s\n", words_arr[i]);
        }
        free(words_arr);
        printf("How many words do you wish to enter? \n");
    }
    
    return 0;
}
