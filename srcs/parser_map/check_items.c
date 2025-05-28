/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:29:45 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/28 19:20:32 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_player_exists(char c)
{
	if (c == NORTH || c == SOUTH || c == WEST || c == EAST)
		return (1);
	return (0);
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
			if (is_player_exists(map->map[x][y]))
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
			if (is_player_exists(map_data->map[i][j]) == 1)
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
		if (map_data->map[i][0] != WALL \
			&& map_data->map[i][0] != FILL_MAP)
		{
			return (1);
		}
		if (map_data->map[i][map_data->columns - 1] != WALL \
			&& map_data->map[i][map_data->columns - 1] != FILL_MAP)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_top_bottom_map(t_parser *map_data)
{
	int	j;

	j = 0;
	while (j < map_data->columns)
	{
		if (map_data->map[0][j] != WALL || map_data->map[0][j] != FILL_MAP)
			return (1);
		if (map_data->map[map_data->rows - 1][j] != WALL \
			|| map_data->map[map_data->rows - 1][j] != FILL_MAP)
			return (1);
		j++;
	}
	return (0);
}

int	check_map_dimensions(t_parser *map_info)
{
	int	i;
	int	line;

	i = 0;
	while (map_info->map[i] != NULL)
	{
		line = (int)ft_strlen(map_info->map[i]);
		if (map_info->columns != line)
			return (1);
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
		return (printf(ERROR_COUNT_PLAYER_INVALID), 1);
	if (check_player_in_map(map_info) == 0)
		return (printf(ERROR_PLAYER_NOT_EXIST), 1);
	if (check_laterals_map(map_info) == 1)
		return (printf(ERROR_WALLS_IN_MAP), 1);
	if (check_map_dimensions(map_info) == 1)
		return (printf(INVALID_LATERALS_MAP), 1);
	if (check_top_bottom_map(map_info) == 1)
		return (printf(INVALID_TOP_BOTTOM_MAP), 1);
	return (0);
}

/*
int	set_map_dimensions(t_parser *map_info)
{
	int	i;
	int	j;
	int	count_line;
	int	max_line;

	if (map_info->map[0] == NULL)
		return (1);
	i = 0;
	while (map_info->map[i] != NULL)
		i++;
	map_info->rows = i;
	i = 0;
	count_line = 0;
	max_line = 0;
	while (map_info->map[i] != NULL)
	{
		j = 0;
		count_line = 0;
		while (map_info->map[i][j] != '\0')
		{
			j++;
			count_line++;
		}
		if (count_line > max_line)
			max_line = count_line;
		i++;
	}
	printf("max linee: [%d]\n", max_line);
	map_info->columns = max_line;
	return (0);
}
*/
