/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:05:11 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_path.h"

/*
** Allocates a table of t_vec based on the pathfinder result
*/

t_vec	*make_path(t_node *end)
{
	int		size;
	t_vec	*path;

	size = node_path_size(end);
	if (!end || size == 0)
		return (NULL);
	path = malloc(sizeof(t_vec) * (size + 1));
	if (!path)
		return (NULL);
	path[size].x = -999;
	path[size].y = -999;
	while (end)
	{
		path[--size] = end->pos;
		end = end->parent;
	}
	return (path);
}
