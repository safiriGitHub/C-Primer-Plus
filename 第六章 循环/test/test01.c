/* 1.编写一个程序，创建一个包含26个元素的数组，并在其中储存26个小 
写字母。然后打印数组的所有内容。 */
#include <stdio.h>

int main()
{
    char array[26];
    char ch = 'a';
    for (int i = 0; i < 26; i++)
    {
        array[i] = ch;
        ch++;
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%c", array[i]);
    }
    
    
    return 0;
}