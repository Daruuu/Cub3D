#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		handle_exit(ERROR_INVALID_ARG, 26);
	/*else
	{
		game = init_game();
		if (game != NULL)
		{
			map_format_border_check(argv[1], game->map);
			map_items(game->map);
			validation_player(&ccoins, game->map);
			init_sprite(game);
			// mlx_key_hook(game->win_ptr, handle_input, game);
			// mlx_hook(game->win_ptr, 17, 0, close_window, game);
			mlx_loop(game->mlx_ptr);
		}
		free_game(game);
	}*/
	return (0);
}