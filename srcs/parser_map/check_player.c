#include "../includes/cub3d.h"

static	void	player_init_pos(t_parser *map_data)
{
	int	y;
	int	x;
	int	c;

	x = 1;
	while (x < map_data->rows)
	{
		y = 1;
		while (y < map_data->columns)
		{
			c = map_data->map[x][y];
			if (c == NORTH \
				|| c == SOUTH || c == EAST || c == WEST)
			{
				map_data->position_player.y = y;
				map_data->position_player.x = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	flood_fill(t_parser *map, int x, int y, int *ccoins)
{
	if (x < 0 || y < 0 || y >= map->columns|| x >= map->rows)
		return ;
	if (map->map[x][y] == '1' || map->map[x][y] == 'V' \
			|| map->map[x][y] == 'E')
		return ;
	if (map->map[x][y] == 'C')
		(*ccoins)++;
	map->map[x][y] = 'V';
	flood_fill(map, x + 1, y, ccoins);
	flood_fill(map, x - 1, y, ccoins);
	flood_fill(map, x, y + 1, ccoins);
	flood_fill(map, x, y - 1, ccoins);
}

/*
static	void	flood_exit(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || y >= map->cols || x >= map->rows)
		return ;
	if (map->matrix[x][y] == '1' || map->matrix[x][y] == 'V')
		return ;
	map->matrix[x][y] = 'V';
	flood_exit(map, x + 1, y);
	flood_exit(map, x - 1, y);
	flood_exit(map, x, y + 1);
	flood_exit(map, x, y - 1);
}
*/

static	void	copy_map_matrix(t_parser *copy_map, t_parser *map_info)
{
	int	i;
	int	j;

	copy_map->map = malloc(sizeof(char *) * map_info->rows);
	if (!copy_map->map)
		handle_error("Error: Memory allocation failed\n", 30, map_info, NULL);
	i = 0;
	while (i < map_info->rows)
	{
		copy_map->map[i] = malloc(sizeof(char) * map_info->columns);
		if (!copy_map->map[i])
			handle_error("Error: Memory allocation failed\n", 30, map_info, NULL);
		j = 0;
		while (j < map_info->columns)
		{
			copy_map->map[i][j] = map_info->map[i][j];
			j++;
		}
		i++;
	}
}

/*******************	CHECK_EMPTY FUNCTION	*******************************/
//TODO: retake in this file 
int	validation_player(t_parser *map_info)
{
	t_parser	copy_map;
	t_parser	copy_map2;

	player_init_pos(map_info);
	copy_map.rows = map_info->rows;
	copy_map.columns = map_info->columns;
	copy_map2.rows = map_info->rows;
	copy_map2.columns = map_info->columns;
	copy_map_matrix(&copy_map, map_info);
	copy_map_matrix(&copy_map2, map_info);
	// flood_fill(&copy_map, map_info->position_player.x, map_info->position_player.y, ccoins);
	// flood_exit(&copy_map2, map_info->position_player.x, map_info->position_player.y);
	/*
	if (*ccoins == map_info->coins \
			&& (copy_map2.matrix[map_info->exit_pos.x][map_info->exit_pos.y] == 'V'))
		ft_printf("¡CCOINS Ok y Exit Ok!\n");
	else
	{
		free_map2d(&copy_map);
		free_map2d(&copy_map2);
		return (1);
	}*/
	free_parser_map(&copy_map);
	free_parser_map(&copy_map2);
	return (0);
}
