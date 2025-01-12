#include <stdlib.h>
// int x and int y for player's x and y coordinates.
// char **map should not be an array of literal strings or it will produce a segmentation fault.
// int *wh an array where wh[0] is width and wh[1] is height of the map.
// char exit is the character that your are searching for.
// '0' is considered floor and '1' wall.
// !! borders are necessary !!

#include "header.h"

void ft_push_back(node *head, node *next)
{
	while (head->next)
	{
		head = head->next;
	}
	head->next = next;
}

node	*new_node(int x, int y)
{
	node *new;

	new = malloc(sizeof(node));
	new->x = x;
	new->y = y;
	new->next = NULL;
	return (new); 
}

void ft_pop_back(node *head)
{
	node *prev;

	prev = NULL;
	if (head == NULL || head->next == NULL)
	{
		head = NULL;
		return;
	}
	while (head->next)
	{
		prev = head; 
		head = head->next;
	}
	prev->next = NULL;
	free(head); 
}

int	find(int x, int y, node *head, char **map, int wh[], char exit)
{
	if (y - 1 < 0 || x - 1 < 0 || x + 1 >= wh[0] || y + 1 >= wh[1])
		return (-1);
	map[y][x] = 'X';
	if (map[y - 1][x] == '0')
	{
		ft_push_back(head, new_node(x, y - 1));
		if (find(x, y - 1, head, map, wh, exit) == 1)
			return (1);
		ft_pop_back(head);
	}
	else if (map[y - 1][x] == exit)
	{
		ft_push_back(head, new_node(x, y - 1));
		return (1);
	}
	if (map[y + 1][x] == '0')
	{
		ft_push_back(head, new_node(x, y + 1));
		if (find(x, y + 1, head, map, wh, exit) == 1)
			return (1);
		ft_pop_back(head);
	}
	else if (map[y + 1][x] == exit)
	{
		ft_push_back(head, new_node(x, y + 1));
		return (1);
	}
	if (map[y][x + 1] == '0')
	{
		ft_push_back(head, new_node(x + 1, y));
		if (find(x + 1, y, head, map, wh, exit) == 1)
			return (1);
		ft_pop_back(head);
	}
	else if (map[y][x + 1] == exit)
	{
		ft_push_back(head, new_node(x + 1, y));
		return (1);
	}
	if (map[y][x - 1] == '0')
	{
		ft_push_back(head, new_node(x - 1, y));
		if (find(x - 1, y, head, map, wh, exit) == 1)
			return (1);
		ft_pop_back(head);
	}
	else if (map[y][x - 1] == exit)
	{
		ft_push_back(head, new_node(x - 1, y));
		return (1);
	}
	return (-1);
}
