#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>

typedef struct s_node
{
	int x;
	int y;
	struct s_node *next; 
} node;


void ft_pop_back(node *head);
void ft_push_back(node *head, node *next);
int	find(int x, int y, node *head,char **map, int wh[], char exit);
#endif