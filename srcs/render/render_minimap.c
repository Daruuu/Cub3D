/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 18:35:48 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_minimap.h"

/*
** Draws a cube, used by the minimap drawer: draw_minimap()
*/

void	draw_rects(t_vec v, t_shape rec, t_game *game)
{
	int	i;

	if (map_get(&game->map, v.x + (int)(game->player.s_pos.x), v.y
		+ (int)(game->player.s_pos.y)))
		rect(&(game->blur.dest), rec, 0xA0143B6A);
	i = 0;
	while (game->last_path && game->last_path[i].x != -999)
	{
		if ((v.x + (int)(game->player.s_pos.x)) == game->last_path[i].x &&
			(v.y + (int)(game->player.s_pos.y)) == game->last_path[i].y)
		{
			rect(&(game->blur.dest), rec, 0x300A0A1E);
		}
		i++;
	}
}

/*
** Draws the actual minimap overlay to the blur buffer
*/

void	draw_minimap(t_game *game)
{
	t_vec	v;
	t_shape	rec;

	game->player.s_pos.x -= (game->player.s_pos.x - game->player.pos.x) * 0.17;
	game->player.s_pos.y -= (game->player.s_pos.y - game->player.pos.y) * 0.17;
	rec.width = 12;
	rec.height = 12;
	rec.x = -fabs(fmod(game->player.s_pos.x, 1)) * rec.width;
	v.x = -9;
	while (++v.x <= 8)
	{
		v.y = -6;
		rec.y = -fabs(fmod(game->player.s_pos.y, 1)) * rec.height;
		while (v.y <= 7)
		{
			draw_rects(v, rec, game);
			rec.y += rec.height + 1;
			v.y++;
		}
		rec.x += rec.width + 1;
	}
	draw_minidot(game);
}

/*
** Draws the player at the center of the map
*/

void	draw_minidot(t_game *game)
{
	t_shape	rec;
	float	f;

	f = 0;
	rec.height = 2;
	rec.width = 2;
	while (f < 1)
	{
		f += 0.1f;
		rec.x = 105 + (cos(game->player.yaw) * f) * 10;
		rec.y = 77 + (sin(game->player.yaw) * f) * 10;
		rect(&(game->blur.dest), rec, 0xD02DF9FF);
	}
	rec.x = 104;
	rec.y = 77;
	rect(&(game->blur.dest), rec, 0xFFFFFFFF);
}
