/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:12:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:09:06 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_engine.h"
#include "../graphics/rendering_primitives.h"
#include "includes_cub.h"

t_ray	get_init_ray(t_rot *rot, double x, double y)
{
	t_ray	ray;

	if (rot->cos > 0)
		ray.st_cos.x = floor(x + 1) - x;
	else
		ray.st_cos.x = ceil(x - 1) - x;
	ray.st_cos.y = ray.st_cos.x * (rot->sin / rot->cos);
	ray.ln_cos = calc_sqrtlen(ray.st_cos);
	if (rot->sin > 0)
		ray.st_sin.y = floor(y + 1) - y;
	else
		ray.st_sin.y = ceil(y - 1) - y;
	ray.st_sin.x = ray.st_sin.y * (rot->cos / rot->sin);
	ray.ln_sin = calc_sqrtlen(ray.st_sin);
	return (ray);
}

/*
** Calculates the texture offset for the main ray hit
*/

double	tex_offset(t_trace trace)
{
	double	offset;

	if (trace.ray.ln_cos < trace.ray.ln_sin)
	{
		offset = trace.ref.x + trace.ref.y + trace.ray.st_cos.x
			+ trace.ray.st_cos.y;
		offset -= (int)offset;
		if (trace.rot.cos < 0)
			offset = 1 - offset;
	}
	else
	{
		offset = trace.ref.x + trace.ref.y + trace.ray.st_sin.x
			+ trace.ray.st_sin.y;
		offset -= (int)offset;
		if (trace.rot.sin > 0)
			offset = 1 - offset;
	}
	return (offset);
}

/*
** Setups the t_shape of the row (x) that'll be drawn to the main buffer,
** and some other stuff like the texture offset for it etc...
*/

void	setup_line(t_game *game, t_trace *tr)
{
	tr->card = get_cardinal(*tr);
	tr->len = fmin(tr->ray.ln_cos, tr->ray.ln_sin);
	game->depth[tr->line.x] = fmin(tr->len, game->depth[tr->line.x]);
	tr->line.height = game->resy / (tr->len * cos(tr->newa));
	tr->line.y = (game->resy - tr->line.height) / 2;
	tr->line.y += game->player.pitch * 2;
	tr->line.y += tr->line.height * game->player.render.z;
	tr->line.dim = 1 - fmin(1, (tr->len - 1) / 9);
	tr->line.img = get_texture(game, tr->card);
	tr->offset = tex_offset(*tr);
	tr->pt = get_portal(game, tr->pos.x, tr->pos.y, tr->card);
	if (!game->should_dim)
		tr->line.dim = 1;
}

/*
** Handles the casting forward of the ray, and calls the draw functions if it
** does hit
*/

void	do_ray(t_game *game, t_trace *tr, t_img *img)
{
	tr->pos = get_collide_pos(*tr);
	if (check_colide(game, tr->pos))
	{
		setup_line(game, tr);
		if (tr->pt)
		{
			translate_portal(&(tr->ref), tr->card, tr->pt);
			portal_render_pf(&tr->portal, tr->line, tr->offset);
			cast_forward(&(tr->ray), tr->step);
			tr->i++;
			return ;
		}
		tr->pt = get_empty_portal(game, tr->pos.x, tr->pos.y, tr->card);
		if (tr->pt)
			e_portal_strip(img, tr->line, &(game->portal), tr->offset);
		else
			set_img_strip(img, tr->line, tr->offset);
		tr->i += 99;
		return ;
	}
	cast_forward(&(tr->ray), tr->step);
	tr->i++;
}

/*
** Starts all the ray casting for every row on the screen
*/

void	ray(t_game *game, t_img *img)
{
	t_trace	trace;
	int		max;

	trace.line.width = 1;
	trace.line.x = -1;
	max = (int)(game->render_distance * 1.41) + 1;
	while (++trace.line.x < game->resx)
	{
		game->depth[trace.line.x] = 999;
		trace.newa = atan2((trace.line.x / (double)game->resx) - .5, game->fov);
		trace.rot = make_rot(game->player.yaw + trace.newa);
		trace.ref.x = game->player.render.x;
		trace.ref.y = game->player.render.y;
		trace.ray = get_init_ray(&(trace.rot), trace.ref.x, trace.ref.y);
		trace.step = get_init_ray(&(trace.rot), 0, 0);
		trace.portal = NULL;
		trace.i = 0;
		while (trace.i < max)
			do_ray(game, &trace, img);
		portal_foreach_free(trace.portal, &render_portal, game);
	}
}
