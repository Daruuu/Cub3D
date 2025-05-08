/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:25:51 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/08 13:25:17 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_parser	*my_parser;
	// argv[1] = "maps/correct_maps/matrix.cub";

	printf("map dir: [%s]\n", argv[1]);
	//check valid file.cub 
	if (argc != 2 || argv[1] == NULL || validate_path_map(argv[1]) != 0)
	{
		printf("error args\n");
		return (1);
	}
	else
	{
		my_parser = init_struct_parser();
		if (read_file(argv[1], my_parser) == 0)
		{
			fill_parser_info(my_parser);
			printar_parser_struct(my_parser);
		}
		// else
		// 	printf("error read file\n");
	}
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
