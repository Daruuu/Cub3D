#include "../includes/cub3d.h"

// MAIN FUNCTION PARSINGGGGGGGGG
//TODO: here call functions from check_extension and check_items

int	check_correct_parsing_map(char **argv)
{
	t_parser	*parser;

	parser = NULL;

	if (map_format_border_check(argv[1], parser) == 1)
	{
		// free_map2d(game->map);
		// free(game->map);
		// free(game);
		handle_exit(ERROR_INVALID_MAP);
	}
	/*
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
	*/
	return (0);
}