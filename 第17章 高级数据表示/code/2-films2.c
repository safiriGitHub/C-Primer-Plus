/* films2.c -- 使用结构链表 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film {
  char title[TSIZE];
  int rating;
  struct film *next;  
};
char *s_gets(char str[], int lim);

int main(void)
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    /*收集并储存信息*/
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film*)malloc(sizeof(struct film));
        if (head == NULL)
            head = current;
        else
            prev->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }
    
    /* 显示电影列表 */
    if (head == NULL)
        puts("No data entered.");
    else 
        puts("Here is the movie list:");
    current = head;
    while (current != NULL)
    {   
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }
    
    /* 完成任务， 释放已分配的内存 */
    current = head;
    while (current != NULL)
    {
        current = head;
        head = current->next;
        free(current);
    }

    puts("Bye!");
    return 0;
}


char *s_gets(char str[], int lim)
{
    char *ret_val;
    char *find;
    ret_val = fgets(str, lim, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}