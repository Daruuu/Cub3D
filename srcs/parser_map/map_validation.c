/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:29:45 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/30 15:01:03 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_player(char c)
{
	return (c == NORTH || c == SOUTH || c == WEST || c == EAST);
}

static int	is_valid_player_count(int count, t_position *pos)
{
	if (count == 0)
		return (printf(ERROR_PLAYER_NOT_EXIST), 1);
	if (count > 1)
	{
		pos->x = -1;
		pos->y = -1;
		return (printf(ERROR_COUNT_PLAYER_INVALID), 1);
	}
	return (0);
}

static int	validate_player(char **map, int rows, int columns, t_position *pos)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < rows)
	{
		j = 1;
		while (j < columns)
		{
			if (is_player(map[i][j]))
			{
				count ++;
				pos->x = i;
				pos->y = j;
			}
			j++;
		}
		i++;
	}
	return (is_valid_player_count(count, pos));
}

int	validate_map(t_parser *parser)
{
	if (validate_player(parser->validation_map, \
			parser->rows, parser->columns, &parser->position_player))
		return (1);
	if (!validate_walls(parser->validation_map, parser->rows, \
		parser->columns))
		return (printf(ERROR_WALLS_IN_MAP), 1);
	if (check_map_dimensions(parser) == 1)
		return (printf(INVALID_LATERALS_MAP), 1);
	return (0);
}
