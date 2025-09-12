/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/12 00:27:15 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_memory_cleanup.h"

void	destroy_img(t_game *game, t_img *img)
{
	if (img->img)
	{
		mlx_destroy_image(game->mlx, img->img);
		img->img = NULL;
	}
}

void	clean_images(t_game *game)
{
	destroy_img(game, &(game->walls.north));
	destroy_img(game, &(game->walls.south));
	destroy_img(game, &(game->walls.west));
	destroy_img(game, &(game->walls.east));
	destroy_img(game, &(game->floor));
	destroy_img(game, &(game->portal));
	destroy_img(game, &(game->skybox));
	destroy_img(game, &(game->gun));
	destroy_img(game, &(game->dash));
	destroy_img(game, &(game->sprite_img));
	destroy_img(game, &(game->health_img));
	destroy_img(game, &(game->goomba_img));
	destroy_img(game, &(game->door_img));
	destroy_img(game, &(game->img));
	destroy_img(game, &(game->blur.dest));
	destroy_img(game, &(game->blur.temp));
	empty_sprites(&(game->sprites));
}

void	clean_all(t_game *game)
{
	clean_images(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (LINUX)
		mlx_destroy_display(game->mlx);
	clear_map(&(game->map));
	clear_sounds(&(game->sounds));
	free_file(&game->file);
	if (game->depth)
		free(game->depth);
	if (game->mlx)
		free(game->mlx);
	if (game->last_path)
		free(game->last_path);
}

void	clean_and_exit(int code, t_game *game)
{
	clean_all(game);
	game = NULL;
	exit(code);
}

int	clean_and_exit_z(t_game *game)
{
	clean_and_exit(0, game);
	return (0);
}
