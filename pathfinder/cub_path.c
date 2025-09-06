/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:23:46 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:23:46 by yamir            ###   ########.fr       */
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
