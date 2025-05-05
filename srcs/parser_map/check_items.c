/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:29:45 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/05 16:08:21 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_player_exists(char to_find)
{
	return (to_find == NORTH || to_find == SOUTH \
		|| to_find == WEST || to_find == EAST);
}

static	int	check_items_in_map(t_parser *map_data)
{
	int	x;
	int	y;

	x = 0;
	while (x < map_data->rows)
	{
		y = 0;
		while (y < map_data->columns)
		{
			if (check_player_exists(map_data->map[x][y]) != 0)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

static int	count_map_items(t_parser *map_data)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < map_data->rows - 1)
	{
		j = 1;
		while (j < map_data->columns - 1)
		{
			if (map_data->map[i][j] == NORTH)
				count ++;
			else if (map_data->map[i][j] == SOUTH)
				count ++;
			else if (map_data->map[i][j] == WEST)
				count ++;
			else if (map_data->map[i][j] == EAST)
				count ++;
			j++;
		}
		i++;
	}
	return (count);
}

/************************VALIDATION MAIN **************************/

int	validation_items_in_map(t_parser *map_info)
{
	int	count_items_map;

	count_items_map = count_map_items(map_info);
	if (check_items_in_map(map_info) == 1 || count_items_map > 1)
		return (1);
	return (0);
}
