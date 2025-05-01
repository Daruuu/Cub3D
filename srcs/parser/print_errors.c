#include "../includes/cub3d.h"

void	handle_error(char *str, int size, t_map *map, t_game *game)
{
	if (str && size > 0)
		write(2, str, size);
	if (map != NULL)
	{
		free_map2d(map);
	}
	if (game != NULL)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	handle_exit(char *str, int size)
{
	write(2, str, size);
	exit(EXIT_FAILURE);
}

