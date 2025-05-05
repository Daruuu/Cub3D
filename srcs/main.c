/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:25:51 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/05 10:33:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	printf("map dir: %s\n", argv[1]);
	if (argc != 2)
		printf("error args\n");//handle_exit(ERROR_INVALID_ARG, 26);
	else
	{
		if (check_correct_parsing_map(argv) != 0)
		{
			printf("invalid mappppp\n");
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
		free_game(game);*/
	}
	return (0);
}
