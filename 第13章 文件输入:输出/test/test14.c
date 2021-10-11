/* 
14.数字图像，尤其是从宇宙飞船发回的数字图像，可能会包含一些失 
真。为编程练习12添加消除失真的函数。该函数把每个值与它上下左右相邻 
的值作比较，如果该值与其周围相邻值的差都大于1，则用所有相邻值的平 
均值（四舍五入为整数）代替该值。注意，与边界上的点相邻的点少于4 
个，所以做特殊处理。
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 30
#define LEVELS 10
const char trans[LEVELS + 1] = " .':~*=&%#";

void makePic(int data[][COLS], char pic[][COLS], int rows);
void init(char arr[][COLS], char ch);
void deal_distortion(int rows, int cols, int data[rows][cols]);
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
    deal_distortion(ROWS, COLS, picIn);
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
void deal_distortion(int rows, int cols, int data[rows][cols])
{
    for (int row = 0; row < rows; row++)
	{
        if (row-1 < 0 || row+1 >= rows)
            continue;
           
		for (int col = 0; col < cols; col++)
		{
            if (col-1 < 0 || col+1 >= cols)
                continue;
            int l, r, u, d; //左右上下
            int del_l, del_r, del_u, del_d; // 左右上下差值的绝对值
            int current = data[row][col];
            l = data[row][col-1];
            r = data[row][col+1];
            u = data[row-1][col];
            d = data[row+1][col];
            del_l = abs(l-current);
            del_r = abs(r-current);
            del_u = abs(u-current);
            del_d = abs(d-current);
            if (del_l > 1 && del_r > 1 && del_u > 1 && del_d > 1)
                data[row][col] = (int)((l+r+u+d)/4.0+0.5);
        }
	}
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
/* 

处理前
 #         *%##%*'           
    #       *%##%**'          
            *%.#%*~*'         
    #       *%##%* ~*'        
  #         *%##%*  ~*'       
            *%#.%*   ~*'      
            *%##%*    ~*'     
*************%##%*************
%%%%%%%%%%%%*%##%*%%%%%%%%%%%%
#### #################:#######
%%%%%%%%%%%%*%##%*%%%%%%%%%%%%
*************%##%*************
            *%##%*            
            *%##%*    ==      
    ''      *%##%*  *=  =*    
    ::      *%##%* *=....=*   
    ~~      *%##%*  *=  =*    
    **      *%##%*    ==      
            *%##%*            
            *%##%*  

处理后：
  #         *%##%*'           
            *%##%**:          
            *%##%*~*:         
            *%##%* ~*:        
            *%##%*  ~*:       
            *%##%*   ~*:      
            *%##%*    ~*:     
*************%##%*************
%%%%%%%%%%%%*%##%*%%%%%%%%%%%%
##############################
%%%%%%%%%%%%*%##%*%%%%%%%%%%%%
*************%##%*************
            *%##%*            
            *%##%*    ==      
    ''      *%##%*  *=  =*    
    ::      *%##%* *=....=*   
    ~~      *%##%*  *=  =*    
    **      *%##%*    ==      
            *%##%*            
            *%##%*  

 */