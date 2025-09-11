/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:13:44 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:58:56 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_floor.h"

/*
** Renders a single floor row, called by setup_floor() which setups the
** t_floor_render struct
*/

void	render_row_floor(t_game *game, t_floor_render *f)
{
	if (f->row_len < 0)
	{
		fill_img(game->img, 0x0, game->resy - f->s.y - 2, game->resy - f->s.y);
		f->s.y += 2;
		return ;
	}
	f->s.x = 0;
	while (f->s.x < game->resx)
	{
		f->tex.x = modabs(f->start_pos.x) * game->floor.width;
		f->tex.y = modabs(f->start_pos.y) * game->floor.height;
		f->color = get_pixel(&(game->floor), (int)f->tex.x, (int)f->tex.y);
		f->dim = 1 - fmin(1, square_dist(game->player.render, f->start_pos) \
			/ 81);
		set_big_pixel(&(game->img), f->s.x, game->resy - f->s.y - 2,
			color_dim(f->color, f->dim));
		f->start_pos.x += f->step.x;
		f->start_pos.y += f->step.y;
		f->s.x += 2;
	}
	f->s.y += 2;
}

/*
** Sets up initial rotation angles and loops through the needed
** screen rows (y)
*/

void	setup_floor(t_game *game, t_floor_render *f)
{
	if (game->resy < 8)
		return ;
	f->ang = atan2(0.5, game->fov);
	f->start = make_rot(game->player.yaw - f->ang);
	f->end = make_rot(game->player.yaw + f->ang);
	f->mid = game->resy / 2;
	f->midpi = fmin(game->resy, f->mid - game->player.pitch * 2);
	f->s.y = 0;
	while (f->s.y < f->midpi)
	{
		f->row_len = f->mid / (f->mid - f->s.y - game->player.pitch * 2);
		f->row_len *= (game->cam_width + (game->player.render.z * \
			game->cam_width * 2));
		f->step.x = ((f->end.cos - f->start.cos) * f->row_len) / game->resx * 2;
		f->step.y = ((f->end.sin - f->start.sin) * f->row_len) / game->resx * 2;
		f->start_pos.x = game->player.render.x + f->start.cos * f->row_len;
		f->start_pos.y = game->player.render.y + f->start.sin * f->row_len;
		render_row_floor(game, f);
	}
}

/*
** Draws the whole textured or untextured floor
*/

void	draw_floor(t_game *game)
{
	t_floor_render	floor;
	int				mid;

	if (!game->floor.img)
	{
		mid = fmax(0, game->img.height / 2 + game->player.pitch * 2);
		fill_img(game->img, game->bottom_color, mid, game->img.height);
		return ;
	}
	setup_floor(game, &floor);
}
