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

# include "../includes/cub3d.h"

static int	is_player_exists(char c)
{
	return (c == NORTH || c == SOUTH || c == WEST || c == EAST);
}

static	int	check_player_in_map(t_parser *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->columns)
		{
			if (is_player_exists(map->map[x][y]) != 0)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

static int	count_player_positions(t_parser *map_data)
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
			if (is_player_exists(map_data->map[i][j]))
				count ++;
			j++;
		}
		i++;
	}
	return (count);
}


static int	check_laterals_map(t_parser *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->rows)
	{
		if (map_data->map[i][0] != '1' \
			|| map_data->map[i][map_data->columns - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < map_data->rows)
	{
		if (map_data->map[i][map_data->columns - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/************************VALIDATION MAIN **************************/

int	validation_items_in_map(t_parser *map_info)
{
	int	player_count;

	player_count = count_player_positions(map_info);
	if (player_count != 1)
	{
		printf("error more items than mandatory\n");
		return (1);
	}
	if (check_player_in_map(map_info) == 0)
	{
		printf("error: player position NOT exists in map\n");
		return (1);
	}
	if (check_laterals_map(map_info) == 1)
	{
		printf("error: invalid laterals in map\n");
		return (1);
	}
	return (0);
}
