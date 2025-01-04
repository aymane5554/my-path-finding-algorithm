#include <stdio.h>
#include <string.h>
#include "header.h"

char **map_duplicate(char **map, int height)
{
    int  i = 0;
    char **map2;

    map2 = malloc((height + 1) * sizeof(char *));
    while (i < height)
    {
        map2[i] = strdup(map[i]); 
        i++;
    }
    map2[i] = NULL;
    return (map2);
}

int main(void)
{
    node *head = malloc(sizeof(node));
    head->x = 1;
    head->y = 1;
    head->next = NULL;
    char *map[] =
    {
        "111111111111111111111",
        "1P0000000000000000001",
        "111111001111100000111",
        "111111000111100011111",
        "111111100111110111111",
        "1000000000001000000E1",
        "111111111111111111111"
    };
    int wh[2] = {22,7};
    if (find(1, 1, head, map_duplicate(map, wh[1]), wh, 'E') == 1)
        printf("valid\n");
    else
        printf("not valid\n");
    int i = 0;
    int j = 0;
    while (head)
    {
        i = 0;
        while (i < 7)
        {
            j = 0;
            while (j < 22)
            {
                if (i == head->y && j == head->x)
                    printf("\e[31mX\e[37m");
                else
                    printf("%c", map[i][j]);
                j++;
            }
            printf("\n");
            i++;
        }
        printf("\n");
        head = head->next;
    }
}