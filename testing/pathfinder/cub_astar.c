/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_astar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:04:10 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_astar.h"

/*
** Adds a node if they're not closed, doesn't loop through the linked list
** to do so as it's very slow, instead it uses an allocated true/false table
*/

t_node	*add_node(t_astar *star, t_node *parent, t_vec new)
{
	t_node	*newnode;

	if (star->closed_map[star->map->size.x * new.y + new.x])
		return (NULL);
	newnode = make_node(parent, star->end_pos, new);
	if (star->end_pos.x == new.x && star->end_pos.y == new.y)
		return (newnode);
	node_insert(&star->list_open, newnode);
	star->closed_map[star->map->size.x * new.y + new.x] = 1;
	return (NULL);
}

/*
** Check if a position is valid (no blocks)
*/

bool	is_valid(t_map *map, t_vec pos)
{
	int	val;

	if (pos.x < 0 || pos.y < 0)
		return (false);
	if (pos.x >= map->size.x || pos.y >= map->size.y)
		return (false);
	val = map_get_val(map, pos.x, pos.y);
	return (!(val == MAP_BLOCK || val == MAP_NOENTRY));
}

/*
** Removes the current node from the open list and adds it to the closed list,
** then adds all of it's valid neighbor nodes to the open list if they're not
** the goal, if a node is the goal, it sets the goal node and returns
*/

void	add_neighbors(t_astar *star, t_node *cur)
{
	int		i;
	t_vec	pos;
	t_node	*next;

	while (cur)
	{
		next = cur->next;
		node_remove(&star->list_open, cur);
		node_push(&star->list_closed, cur);
		i = 0;
		while (i < 4)
		{
			pos = get_neighbor(i++, cur->pos);
			if (is_valid(star->map, pos))
			{
				star->goal = add_node(star, cur, pos);
				if (star->goal)
					return ;
			}
		}
		cur = next;
	}
}

/*
** Clears all the nodes allocated for the pathfinding
*/

void	clear_list(t_astar *star, t_node *a, t_node *b, t_node *goal)
{
	t_node	*t;

	while (a)
	{
		t = a->next;
		free(a);
		a = t;
	}
	while (b)
	{
		t = b->next;
		free(b);
		b = t;
	}
	free(star->closed_map);
	free(goal);
}

/*
** Begins the pathfinding
*/

t_vec	*astar(t_map *map, t_vec start, t_vec end, unsigned int maxtries)
{
	(void)map;
	(void)start;
	(void)end;
	(void)maxtries;
	// Implementación vacía - algoritmo A* deshabilitado temporalmente
	return (NULL);
}
