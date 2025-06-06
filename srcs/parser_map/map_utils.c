/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:45:06 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/30 15:45:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_valid_wall(char c)
{
	return (c == WALL || c == FILL_MAP);
}

int	validate_walls(char **map, int rows, int columns)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (!is_valid_wall(map[i][0]) || !is_valid_wall(map[i][columns - 1]))
			return (1);
		i++;
	}
	i = 0;
	while (i < columns)
	{
		if (!is_valid_wall(map[0][i]) || !is_valid_wall(map[rows - 1][i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_map_dimensions(t_parser *map_info)
{
	int	i;
	int	line;

	i = 0;
	while (map_info->validation_map[i] != NULL)
	{
		line = (int)ft_strlen(map_info->validation_map[i]);
		if (map_info->columns != line)
			return (1);
		i++;
	}
	return (0);
}
