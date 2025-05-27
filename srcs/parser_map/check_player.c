# include "../includes/cub3d.h"

/*
int	is_surrounded_by_walls(char **map, int x, int y)
{
	if (map[x - 1][y] != '1' && map[x - 1][y] != '/')
		return (0);
	if (map[x + 1][y] != '1' && map[x + 1][y] != '/')
		return (0);
	if (map[x][y - 1] != '1' && map[x][y - 1] != '/')
		return (0);
	if (map[x][y + 1] != '1' && map[x][y + 1] != '/')
		return (0);
	return (1);
}
*/

int is_surrounded_by_walls(char **map, int x, int y, int rows, int cols)
{
	if (x - 1 < 0 || x + 1 >= rows || y - 1 < 0 || y + 1 >= cols)
		return (0);

	if (map[x - 1][y] != '1' && map[x - 1][y] != '/')
		return (0);
	if (map[x + 1][y] != '1' && map[x + 1][y] != '/')
		return (0);
	if (map[x][y - 1] != '1' && map[x][y - 1] != '/')
		return (0);
	if (map[x][y + 1] != '1' && map[x][y + 1] != '/')
		return (0);
	return (1);
}

void	flood_fill(char **map, int rows, int cols, int x, int y)
{
	if (x < 0 || y < 0 || x >= rows || y >= cols)
		return ;
	//	si es pared o ya visitado no continuar
	if (map[x][y] == '1' || map[x][y] == '/' || map[x][y] == '0')
		return ;

	if (map[x][y] == FLOOR || map[x][y] == NORTH || map[x][y] == SOUTH
		|| map[x][y] == WEST || map[x][y] == EAST)
	{
		printf("Mapa no cerrado! Fuga detectada en (%d, %d)\n", x, y);
		exit(1); // o return error code
	}

	// if (map[x][y] == ' ' && is_surrounded_by_walls(map, x, y, rows, cols))
	// 	return ;

	map[x][y] = '/';

	flood_fill(map, rows, cols, x + 1, y);
	flood_fill(map, rows, cols, x - 1, y);
	flood_fill(map, rows, cols, x, y + 1);
	flood_fill(map, rows, cols, x, y - 1);
}


/*******************	CHECK_EMPTY FUNCTION	*******************************/
//TODO: retake in this file

/*
int	validation_player(t_parser *map_info)
{
	t_parser	copy_map;
	t_parser	copy_map2;

	get_player_init_pos(map_info);
	copy_map.rows = map_info->rows;
	copy_map.columns = map_info->columns;
	copy_map2.rows = map_info->rows;
	copy_map2.columns = map_info->columns;
	// copy_map_matrix(&copy_map, map_info);
	// copy_map_matrix(&copy_map2, map_info);
	// flood_fill(&copy_map, map_info->position_player.x, map_info->position_player.y, ccoins);
	// flood_exit(&copy_map2, map_info->position_player.x, map_info->position_player.y);
	if (*ccoins == map_info->coins \
			&& (copy_map2.matrix[map_info->exit_pos.x][map_info->exit_pos.y] == 'V'))
		ft_printf("¡CCOINS Ok y Exit Ok!\n");
	else
	{
		free_map2d(&copy_map);
		free_map2d(&copy_map2);
		return (1);
	}#1#
	free_parser_map(&copy_map);
	free_parser_map(&copy_map2);
	return (0);
}
*/
