/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:48:54 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/12 16:41:15 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx/mlx.h"
#include "srcs/parser/parser_file_loader.h"
#include "srcs/render/render_hud.h"
#include "srcs/render/render_floor.h"
#include "srcs/parser/parser_map_validator.h"
#include "srcs/init_game/error_handler.h"
#include "srcs/input/input_handler.h"
#include "srcs/init_game/init_game.h"
#include "srcs/game/game_player.h"
#include "srcs/file_loader/check_file_map.h"

/**
* Updates the game world state:
*
* Processes player input (keybinds).
* Manages timing and delays if bonus mode is enabled.
* Updates player motion and sprite rendering.
* Refreshes pathfinding logic for enemies/objects.
 */

void	update_world(t_game *game)
{
	update_keybinds(game);
	if (game->bonus)
	{
		get_delay(true, FPS_BONUS, !LINUX);
		while (game->delay > FPS_BONUS)
		{
			update_motion(&(game->player), game);
			draw_sprites(game, true);
			game->time++;
			game->delay -= FPS_BONUS;
		}
	}
	update_motion(&(game->player), game);
}

/**
* Renders one frame of the game:
* Otherwise, updates the game, draws floor, skybox, walls (raycasting),
* sprites, HUD, cursor, and hand.
* Handles saving mode (--save) and frame timing for bonus mode.
* Syncs with the display before returning.
 */

int	render_next_frame(t_game *game)
{
	if (game->player.health <= 0)
		draw_death(game);
	else
	{
		update_world(game);
		draw_floor(game);
		if (!game->bmp)
			draw_skybox(game);
		ray(game, &(game->img));
		draw_sprites(game, false);
		if (!game->bmp)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
			draw_cursor(game);
			draw_hud(game);
			render_hand(game);
		}
		if (game->bonus)
			game->delay += get_delay(false, FPS_BONUS, !LINUX);
		game->time++;
	}
	mlx_do_sync(game->mlx);
	return (0);
}

/**
* Prepares rendering resources:
* Sets the field of view and camera width.
* Creates the main rendering image.
* Configures render distance and lighting based on bonus mode and assets.
* Allocates the depth buffer.
* Initializes the blur effect for rendering.
 * @param game
 */
void	setup_render(t_game *game)
{
	t_shape	shape;

	game->fov = (double)game->resy / (double)game->resx;
	game->cam_width = (1 / (cos(atan2(-0.5, game->fov))));
	game->img = make_image(game->mlx, game->resx, game->resy);
	if (!game->bonus || ((!game->floor.img && game->bottom_color != 0) \
		|| (!game->skybox.img && game->top_color != 0)))
	{
		game->should_dim = false;
		game->render_distance = 50;
	}
	game->depth = malloc(sizeof(double) * game->resx);
	if (!game->depth)
		handle_error(game, "Failed to allocate depth buffer.", NULL);
	shape.width = 210;
	shape.height = 150;
	shape.x = 20;
	shape.y = game->resy - shape.height - 45;
	game->blur = make_blur_struct(game->mlx, game->img, shape);
}

/**
* Loads program arguments and configuration:
* Validates command-line arguments (expects .cub file and optional --save).
* Enables saving mode if --save is specified.
* Verifies file extension and loads map configuration.
* Raises errors for invalid input.
 */
void	load_args(int argc, char **argv, t_game *game)
{
	if (argc == 2)
	{
		if (!check_iscub(argv[1]))
			handle_error(game, ERROR_FILE_TYPE, argv[1]);
		load_f(argv[1], game);
	}
	else
		handle_error(game, ERROR_USAGE_CUB, NULL);
}

/**
* Loads arguments and validates configuration.
* Prepares rendering and checks save mode.
* Creates the game window, starts ambient sound if available.

 */
int	main(int argc, char **argv)
{
	t_game	game;

	init_default(&game);
	set_bonus(&(game.bonus));
	game.mlx = mlx_init();
	if (!game.mlx)
		handle_error(&game, FAIL_MLX, NULL);
	load_args(argc, argv, &game);
	check_define(&game);
	setup_render(&game);
	game.win = mlx_new_window(game.mlx, game.resx, game.resy, TITLE_WINDOWS);
	if (game.sounds.ambient)
		play_sound_alt(game.sounds.ambient, true, true);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_lift, &game);
	mlx_hook(game.win, 33, 1L << 17, clean_and_exit_z, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
