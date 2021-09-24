/* 
7.编写一个程序，按照程序清单12.13输出示例后面讨论的内容，修改该 
程序。使其输出类似： 
Enter the number of sets; enter q to stop : 18
How many sides and how many dice? 6 3 
Here are 18 sets of 3 6-sided throws. 
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10 13 8 14 
How many sets? Enter q to stop: q
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "diceroll.h"

int main(void)
{
    int dice = 0;
    int roll = 0;
    int set = 0;
    int sides = 0;
    
    srand((unsigned int)time(0));
    printf("Enter the number of sets; enter q to stop : ");
    while (scanf("%d", &set) == 1 && set > 0)
    {
        printf("How many sides and how many dice? ");
        if (scanf("%d %d", &sides, &dice) == 2 && sides > 0 && dice > 0)
        {
            printf("Here are %d sets of %d %d-sided throws.\n",\
				set, dice, sides);
            for (int i = 0; i < set; i++)
            {
                roll = roll_n_dice(dice, sides);
                printf("%d ", roll);
            }
            set = 0;
            putchar('\n');
        }
        printf("Enter the number of sets; enter q to stop : ");
    }
    printf("The rollem() function was called %d times.\n", roll_count);
	printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}