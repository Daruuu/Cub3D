#include "../includes/cub3d.h"

void    free_game(t_game *game)
{
	if (game)
	{
		if (game->map != NULL)
			free_map2d(game->map);
		free(game);
	}
}

void    check_empty(char **argv, t_game *game, int ccoins)
{
	if (map_format_border_check(argv[1], game->map) == 1)
	{
		free_map2d(game->map);
		free(game->map);
		free(game);
		handle_exit(ERROR_INVALID_MAP, 24);
	}
	else if (items_errors(game->map) == 1)
	{
		free_map2d(game->map);
		free(game->map);
		free(game);
		handle_exit(ERROR_ITEMS, 21);
	}
	else if (validation_player(&ccoins, game->map) == 1)
	{
		free_map2d(game->map);
		free(game->map);
		free(game);
		handle_exit(ERROR_ITEMS, 21);
	}
	else
		return ;
}