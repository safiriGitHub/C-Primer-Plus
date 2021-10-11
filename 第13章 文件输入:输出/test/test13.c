/* 
13.用变长数组（VLA）代替标准数组，完成编程练习12。
 */
#include <stdio.h>
#include <stdlib.h>


#define ROWS 20
#define COLS 30
#define LEVELS 10
const char trans[LEVELS + 1] = " .':~*=&%#";

void makePic(int rows, int cols, int data[][cols], char pic[][cols]);
void init(int rows, int cols, char arr[][cols], char ch);
char *s_gets(char *st, int len);

int main(void)
{
    int row, col;
	int picIn[ROWS][COLS];
	char picOut[ROWS][COLS];
	char szFileName[81];
	FILE * inFile;

    init(ROWS, COLS, picOut, 'S');

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
    makePic(ROWS, COLS, picIn, picOut);
    for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
			putchar(picOut[row][col]);
		putchar('\n');
	}
    return 0;
}

void makePic(int rows, int cols, int data[][cols], char pic[][cols])
{
	int row, col;
	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++)
			pic[row][col] = trans[data[row][col]];
}

void init(int rows, int cols, char arr[][cols], char ch)
{
	int r, c;
	for (r = 0; r < rows; r++)
	{
		for (c = 0; c < cols; c++)
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