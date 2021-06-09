/* booksave.c -- 在文件中保存结构中的内容 
也许该例是把结构写入文件和检索它们的最简单的方法，
但是这种方法浪费存储空间，因为这还保存了结构中未使用的部分。
该结构的大小是 2×40×sizeof(char)+sizeof(float)，在我们的系统中共84字节。
实际上不是每个输入项都需要这么多空间。但是，让每个输入块的大小相同在检索数据时很方便。

另一个方法是使用可变大小的记录。为了方便读取文件中的这种记录， 每个记录以数值字段规定记录的大小。
这比上一种方法复杂。通常，这种方 法涉及“链式结构”和动态内存分配。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
char *s_gets(char *st, int n);

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS]; //结构数组
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    if ((pbooks = fopen("book.dat", "a+b")) == NULL) //a+在文件末尾添加内容 b二进制文件格式
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    
    rewind(pbooks); //定位到文件开始
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
        //第1个while循环每次把一个结构读到结构数组中，当数组已满或读完文件时停止。
        //变量filecount统计已读结构的数量。
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
        && library[count].title[0] != '\0')
        {
            puts("Now enter the author.");
            s_gets(library[count].author, MAXAUTL);
            puts("Now enter the value.");
            scanf("%f",&library[count++].value);
            while (getchar() != '\n')
                continue; //清理输入行
            if (count < MAXBKS)
                puts("Enter the nex title.");
        //第2个while按下循环提示用户进行输入，并接受用户的输入。
        //该循环把新输 入项添加到数组的末尾。
        }
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
        {
            printf("%s by %s: $%.2f\n", 
            library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[filecount], size, count-filecount, pbooks);
        /*我们本可以用一个循环在文件末尾一次添加一个结构，
        但还是决定用 fwrite()一次写入一块数据。
        对表达式count - filecount求值得新添加的书籍数量，然后调用fwrite()把结构大小的块写入文件。
        由于表达式 &library[filecount]是数组中第1个新结构的地址，所以拷贝就从这里开始。
        */
    }
    else 
    puts("No books? Too bad.\n"); 
    puts("Bye.\n"); 
    fclose(pbooks); 
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}



