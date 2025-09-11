/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:48:54 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 16:18:42 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx/mlx.h"
#include "srcs/parser/parser_file_loader.h"
#include "srcs/render/cub_hud.h"
#include "srcs/render/render_floor.h"
#include "srcs/utils/cub_checker.h"
#include "srcs/utils/cub_error.h"
#include "srcs/utils/cub_keybinds.h"
#include "srcs/utils/cub_setup.h"
#include "srcs/game/game_player.h"

/**
* Updates the game world state:
*
* Processes player input (keybinds).
* Manages timing and delays if bonus mode is enabled.
* Updates player motion and sprite rendering.
* Refreshes pathfinding logic for enemies/objects.
 */

void	update_world(t_vars *vars)
{
	update_keybinds(vars);
	if (vars->bonus)
	{
		get_delay(true, FPS_BONUS, !LINUX);
		while (vars->delay > FPS_BONUS)
		{
			update_motion(&(vars->player), vars);
			draw_sprites(vars, true);
			vars->time++;
			vars->delay -= FPS_BONUS;
			// refresh_pathfinding(vars);
		}
	}
	update_motion(&(vars->player), vars);
	// refresh_pathfinding(vars);
}

/**
* Renders one frame of the game:
* If the player is dead, shows the death screen.
* Otherwise, updates the world, draws floor, skybox, walls (raycasting),
* sprites, HUD, cursor, and hand.
* Handles saving mode (--save) and frame timing for bonus mode.
* Syncs with the display before returning.
 */

int	render_next_frame(t_vars *vars)
{
	if (vars->player.health <= 0)
		draw_death(vars);
	else
	{
		update_world(vars);
		draw_floor(vars);
		if (!vars->bmp)
			draw_skybox(vars);
		ray(vars, &(vars->img));
		draw_sprites(vars, false);
		if (!vars->bmp)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
			draw_cursor(vars);
			draw_hud(vars);
			render_hand(vars);
		}
		if (vars->bonus)
			vars->delay += get_delay(false, FPS_BONUS, !LINUX);
		vars->time++;
	}
	mlx_do_sync(vars->mlx);
	return (0);
}

/**
* Prepares rendering resources:
* Sets the field of view and camera width.
* Creates the main rendering image.
* Configures render distance and lighting based on bonus mode and assets.
* Allocates the depth buffer.
* Initializes the blur effect for rendering.
 * @param vars
 */
void	setup_render(t_vars *vars)
{
	t_shape	shape;

	vars->fov = (double)vars->resy / (double)vars->resx;
	vars->cam_width = (1 / (cos(atan2(-0.5, vars->fov))));
	vars->img = make_image(vars->mlx, vars->resx, vars->resy);
	if (!vars->bonus || ((!vars->floor.img && vars->bottom_color != 0) \
		|| (!vars->skybox.img && vars->top_color != 0)))
	{
		vars->should_dim = false;
		vars->render_distance = 50;
	}
	vars->depth = malloc(sizeof(double) * vars->resx);
	if (!vars->depth)
		handle_error(vars, "Failed to allocate depth buffer.", NULL);
	shape.width = 210;
	shape.height = 150;
	shape.x = 20;
	shape.y = vars->resy - shape.height - 45;
	vars->blur = make_blur_struct(vars->mlx, vars->img, shape);
}

/**
* Loads program arguments and configuration:
* Validates command-line arguments (expects .cub file and optional --save).
* Enables saving mode if --save is specified.
* Verifies file extension and loads map configuration.
* Raises errors for invalid input.
 */
void	load_args(int argc, char **argv, t_vars *vars)
{
	if (argc == 2)
	{
		if (!check_iscub(argv[1]))
			handle_error(vars, ERROR_FILE_TYPE, argv[1]);
		load_f(argv[1], vars);
	}
	else
		handle_error(vars, ERROR_USAGE_CUB, NULL);
}

/**
* Loads arguments and validates configuration.
* Prepares rendering and checks save mode.
* Creates the game window, starts ambient sound if available.

 */
int	main(int argc, char **argv)
{
	t_vars	vars;

	init_default(&vars);
	set_bonus(&(vars.bonus));
	vars.mlx = mlx_init();
	if (!vars.mlx)
		handle_error(&vars, FAIL_MLX, NULL);
	load_args(argc, argv, &vars);
	check_define(&vars);
	setup_render(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.resx, vars.resy, TITLE_WINDOWS);
	if (vars.sounds.ambient)
		play_sound_alt(vars.sounds.ambient, true, true);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_lift, &vars);
	mlx_hook(vars.win, 33, 1L << 17, clean_and_exit_z, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
