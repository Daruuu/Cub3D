/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 18:38:10 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_hud.h"
#include "../graphics/rendering_primitives.h"
#include "../graphics/color_operations.h"

/*
** Draws the minimap and it's background shadow / blur
*/

void	draw_hud(t_game *game)
{
	t_shape	shape;

	if (!game->dash.img || game->resx < 420 || game->resy < 230)
		return ;
	shape.width = 210;
	shape.height = 15;
	shape.x = 20;
	shape.y = game->resy - 35;
	rect(&(game->img), shape, 0);
	shape.width = 210 * game->player.health;
	rect(&(game->img), shape, 0x00CD3D24);
	shape.height = 5;
	shape.y += 10;
	rect(&(game->img), shape, 0x00B22D17);
	make_blur_opt(game->blur, false);
	draw_minimap(game);
	render_mac_os_image(game, &game->dash, 0,
		game->resy - game->dash.height - (1));
	mlx_put_image_to_window(game->mlx, game->win, game->blur.dest.img,
		game->blur.shape.x, game->blur.shape.y);
}

/*
** Draws the gameover screen, which shows up when you die
*/

void	draw_death(t_game *game)
{
	if (game->player.health == -1000)
		return ;
	fill_img(game->img, 0x50BE3F3B, 0, game->img.height);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_string_put(game->mlx, game->win, game->img.width / 2 - 45,
		game->img.height / 2 - 10, 0x00FFFFFF, "GAME OVER");
	game->player.health = -1000;
}

/*
** Draws the crosshair at the center of the screen,
** warning: absolute hacky values
*/

void	draw_cursor(t_game *game)
{
	t_shape	shape;
	int		color;

	if (!game->gun.img)
		return ;
	color = color_dim(0xFFFFFF, 1 - fmin(game->shoot, 40) / 40.0) | 0xBB << 24;
	shape.width = 1;
	shape.height = 4;
	shape.x = (game->resx - 30) / 2 + 1;
	shape.y = (game->resy - 30) / 2 - 2;
	rect(&(game->img), shape, color);
	shape.x += 28;
	rect(&(game->img), shape, color);
	shape.x -= 16;
	shape.width = 4;
	shape.height = 1;
	shape.y -= 13;
	rect(&(game->img), shape, color);
	shape.y += 28;
	rect(&(game->img), shape, color);
	shape.y -= 14;
	shape.x += 1;
	shape.width = 2;
	shape.height = 2;
	rect(&(game->img), shape, color);
}

/*
** Renders the portal gun in your hand, matching your view bobbing
*/

void	render_hand(t_game *game)
{
	t_vec	pos;

	if (!game->gun.img || game->resx < 420)
		return ;
	pos.y = 3 + cos(game->time / 4.0 + 34) * 3 * game->bob \
			+ game->player.pos.z * 14;
	pos.x = 3 + sin(game->time / 4.8 + 56) * 3 * game->bob \
			- game->player.motion_yaw * 200;
	render_mac_os_image(game, &game->gun, game->resx \
	- game->gun.width + pos.x, game->resy - game->gun.height + pos.y);
}

void	draw_skybox(t_game *game)
{
	t_vec	pos;

	if (game->skybox.img && !LINUX)
		fill_img(game->img, 0xFF000000, 0, fmax(0, game->img.height / 2 + \
			game->player.pitch * 2 + 1));
	else if (!game->skybox.img)
	{
		fill_img(game->img, game->top_color, 0, fmax(0, game->img.height / 2 + \
			game->player.pitch * 2 + 1));
		return ;
	}
	pos.y = game->player.pitch * 2 - game->resy / 2 + 2;
	pos.x = fmod(-game->player.yaw / 2 * game->resx, game->resx * 3.14);
	render_mac_os_image(game, &(game->skybox), pos.x, pos.y);
	if (pos.x > 0)
		render_mac_os_image(game, &(game->skybox), \
		pos.x - game->skybox.width + 4, pos.y);
	if (pos.x < 0 && pos.x + game->skybox.width > 0)
		render_mac_os_image(game, &(game->skybox), \
		pos.x + game->skybox.width - 4, pos.y);
}
