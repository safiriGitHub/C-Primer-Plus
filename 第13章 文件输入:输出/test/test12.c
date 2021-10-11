/* 
12.创建一个文本文件，内含20行，每行30个整数。这些整数都在0～9 
之间，用空格分开。该文件是用数字表示一张图片，0～9表示逐渐增加的灰 
度。编写一个程序，把文件中的内容读入一个20×30的int数组中。一种把这 
些数字转换为图片的粗略方法是：该程序使用数组中的值初始化一个20×31 
的字符数组，用值0 对应空格字符，1 对应点字符，以此类推。数字越大表 
示字符所占的空间越大。例如，用#表示9。每行的最后一个字符（第31个） 
是空字符，这样该数组包含了20个字符串。最后，程序显示最终的图片 
（即，打印所有的字符串），并将结果储存在文本文件中。例如，下面是开 
始的数据：
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
根据以上描述选择特定的输出字符，最终输出如下：

 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define LEVELS 10
const char trans[LEVELS + 1] = " .':~*=&%#";

void makePic(int data[][COLS], char pic[][COLS], int rows);
void init(char arr[][COLS], char ch);
char *s_gets(char *st, int len);

int main(void)
{
    int row, col;
	int picIn[ROWS][COLS];
	char picOut[ROWS][COLS];
	char szFileName[81];
	FILE * inFile;

    init(picOut, 'S');

    printf("Enter name of file: ");
	s_gets(szFileName, 80);

    if ((inFile = fopen(szFileName, "r")) == NULL)
    {
        fprintf(stderr, "Could not open data file.\n");
		exit(EXIT_FAILURE);
    }
    for (row = 0; row < ROWS; row++)
        for (col = 0; col < COLS; col++)
            fscanf(inFile, "%d", &picIn[row][col]);
    if (ferror(inFile))
	{
		fprintf(stderr, "Error getting data from file.\n");
		exit(EXIT_FAILURE);
	}
    makePic(picIn, picOut, ROWS);
    for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
			putchar(picOut[row][col]);
		putchar('\n');
	}
    return 0;
}

void makePic(int data[][COLS], char pic[][COLS], int rows)
{
	int row, col;
	for (row = 0; row < rows; row++)
		for (col = 0; col < COLS; col++)
			pic[row][col] = trans[data[row][col]];
}

void init(char arr[][COLS], char ch)
{
	int r, c;
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			arr[r][c] = ch;
	}
}

char *s_gets(char *st, int len)
{
    char *ret_val = NULL;
    int i = 0;

    if ((ret_val = fgets(st, len, stdin)) != NULL)
    {
        while (st[i] != '\0' && st[i] != '\n')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;            
    }
    return ret_val;
}