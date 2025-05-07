/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:25:51 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/07 13:45:46 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_parser	*my_parser;

	printf("map dir: %s\n", argv[1]);
	if (argc != 2)
	{
		printf("error args\n");
		return (1);
	}
	else
	{
		my_parser = init_struct_parser();

		//check valid file.cub 
		int	condition_1 = read_file(argv[1], my_parser);
		printf("read_map: [%i]\n", condition_1);
		if (condition_1 == 0)
		{
		}
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
