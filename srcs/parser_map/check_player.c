#include "../includes/cub3d.h"

/*
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
*/

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
