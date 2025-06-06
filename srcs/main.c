/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:25:51 by dasalaza          #+#    #+#             */
/*   Updated: 2025/06/04 21:24:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_parser	*my_parser;

	if (argc != 2 || argv[1] == NULL)
		return (printf(ERROR_INVALID_ARGS), 1);
	printf("av[0]: [%s]\n", argv[0]);
	printf("map dir: [%s]\n", argv[1]);
	if (validate_map_filename(argv[1]) != 0)
		return (1);
	my_parser = init_struct_parser();
	if (!my_parser)
		return (1);
	if (read_file(my_parser, argv[1]) == 0)
	{
		parsing(my_parser);

		// printf("ROWS MAP: %d\n", my_parser->rows);
		// printf("COLUMNS MAP: %d\n", my_parser->columns);

		// print_parser_struct(my_parser);
	}
	else
		printf("Error: failed to read or parse the map file.\n");
	free_parser_struct(my_parser);
	return (0);
}

/*
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
*/
