/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprite_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:14:44 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_sprite_renderer.h"

/*
** Renders the actual sprite, which was setup in draw_sprite()
*/
static void	draw_sprite_column(t_img *img, t_game *game, t_sprite s,
		t_sprite_r *sp)
{
	while (++sp->v.y < sp->draw.height && sp->draw.y + sp->v.y < img->height)
	{
		if (sp->draw.y + sp->v.y < 0)
			sp->v.y = -sp->draw.y;
		if (sp->dist >= game->depth[sp->draw.x + sp->v.x])
			continue ;
		sp->offset.y = fmin(sp->v.y / (double)sp->draw.height
				* s.texture->height, s.texture->height - 1);
		if (!game->should_dim)
			sp->dim = 1;
		else
			sp->dim = fmax(0, fmin(1, 1 - fmin(1, (sp->dist - 1) / 9)));
		sp->color = get_pixel(s.texture, sp->offset.x, sp->offset.y);
		if (sp->color != 0)
			set_pixel(img, sp->draw.x + sp->v.x, sp->draw.y + sp->v.y,
				color_dim(sp->color, sp->dim));
	}
}

void	draw_sprite_line(t_img *img, t_game *game, t_sprite s, t_sprite_r sp)
{
	while (++sp.v.x < sp.draw.width && sp.draw.x + sp.v.x < img->width)
	{
		if (sp.draw.x + sp.v.x < 0)
			sp.v.x = -sp.draw.x;
		sp.v.y = -1;
		sp.offset.x = fmin(sp.v.x / (double)sp.draw.width * s.texture->width,
				s.texture->width - 1);
		if (s.last_hurt % 15 > 7)
			sp.offset.x = fmax(0, s.texture->width - sp.offset.x - 1);
		draw_sprite_column(img, game, s, &sp);
	}
}

/*
** Setups the sprite for render
*/

bool	draw_sprite(t_img *img, t_game *game, t_sprite s)
{
	t_sprite_r	sp;

	if (s.kind == DOOR)
		return (false);
	sp.pos.x = s.pos.x - game->player.render.x;
	sp.pos.y = s.pos.y - game->player.render.y;
	sp.dist = distance(sp.pos);
	if (sp.dist > game->render_distance)
		return (false);
	sp.sprite_angle = atan2(sp.pos.y, sp.pos.x) - game->player.yaw;
	sp.view_dist = game->resx * game->fov;
	sp.draw.width = sp.view_dist / (cos(sp.sprite_angle) * sp.dist);
	sp.draw.x = game->resx / 2 + (tan(sp.sprite_angle))
		* sp.view_dist - sp.draw.width / 2;
	sp.draw.height = sp.draw.width;
	sp.draw.y = (game->resy - sp.draw.height + game->player.pitch * 4) / 2
		+ sp.draw.height * game->player.render.z;
	sp.v.x = -1;
	if (sp.draw.height > 0)
		draw_sprite_line(img, game, s, sp);
	return (1);
}

/*
** Handles door opening and such
*/

void	handle_door(t_sprite *curr, t_game *game)
{
	t_sprite	*cur;

	if (curr->last_hurt == 25)
	{
		cur = game->sprites;
		while (cur)
		{
			if (!cur->dead && cur->kind == GOOMBA && \
				distancemid2(curr->pos, cur->pos) <= 0.9)
				return ;
			cur = cur->next;
		}
	}
	if (square_dist_mid(game->player.pos, curr->pos) < 8)
	{
		if (curr->last_hurt == 0)
			play_sound(game->sounds.door);
		curr->last_hurt = fmin(25, curr->last_hurt + 1);
	}
	else
		curr->last_hurt = fmax(0, curr->last_hurt - 1);
}

/*
** Calls all sprite drawing functions and handlers
*/

void	draw_sprites(t_game *game, bool skip)
{
	t_sprite	*curr;
	double		dist;

	sprite_sort(game, &(game->sprites));
	curr = game->sprites;
	while (curr)
	{
		dist = square_dist(game->player.pos, curr->pos);
		if (game->bonus && curr->kind == DOOR
			&& (skip || draw_door(&(game->img), game, *curr)))
			handle_door(curr, game);
		else if (!curr->dead && (skip || draw_sprite(&(game->img), game, *curr))
			&& curr->kind == GOOMBA && dist < 196)
			handle_goomba(curr, game);
		curr = curr->next;
	}
}
