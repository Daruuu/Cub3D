/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_collision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 01:07:14 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_collision.h"

void	init_obj(t_vec3d *vec, double x, double y)
{
	vec->x = x;
	vec->y = y;
	vec->z = 0;
}

bool	collide_object(t_game *game, double x, double y, t_sprite *goomba)
{
	t_vec3d		vec;
	t_sprite	*curr;

	init_obj(&vec, x, y);
	curr = game->sprites;
	while (curr)
	{
		if (goomba && curr != goomba && curr->kind == GOOMBA && !curr->dead
			&& square_dist(vec, curr->pos) < 0.45)
			return (true);
		else if (!goomba && curr->kind == HEALTH && !curr->dead
			&& square_dist(vec, curr->pos) < .14 && game->player.health < 1)
		{
			curr->dead = true;
			game->player.health = fmin(1, game->player.health + 0.35);
			play_sound(game->sounds.heal);
		}
		else if (curr->kind == OBJ && square_dist(vec, curr->pos) < 0.26)
			return (game->bonus);
		else if (curr->kind == DOOR && curr->last_hurt != 25
			&& square_dist_mid(vec, curr->pos) < 0.5)
			return (true);
		curr = curr->next;
	}
	return (false);
}

void	collidex(t_game *game, t_player *player)
{
	int			side;
	t_cardinal	card;
	t_portal	*pt;

	side = floor(player->pos.x + player->motion.x);
	card = SOUTH;
	if (player->motion.x > 0)
		card = NORTH;
	pt = get_portal(game, side, floor(player->pos.y), card);
	if (pt)
		translate_portal_3(&(player->pos), card, pt);
	side = floor(player->pos.x + player->motion.x);
	if (!map_get(&game->map, side, floor(player->pos.y)) && !collide_object(
			game, player->pos.x + player->motion.x, player->pos.y, NULL))
		player->pos.x += player->motion.x;
	else
	{
		player->motion.x = 0;
		game->bob = -0.04;
	}
}

void	collidey(t_game *game, t_player *player)
{
	int			side;
	t_cardinal	card;
	t_portal	*pt;

	side = floor(player->pos.y + player->motion.y);
	card = WEST;
	if (player->motion.y > 0)
		card = EAST;
	pt = get_portal(game, floor(player->pos.x), side, card);
	if (pt)
		translate_portal_3(&(player->pos), card, pt);
	side = floor(player->pos.y + player->motion.y);
	if (!map_get(&game->map, floor(player->pos.x), side) && !collide_object(
			game, player->pos.x, player->pos.y + player->motion.y, NULL))
		player->pos.y += player->motion.y;
	else
	{
		player->motion.y = 0;
		game->bob = -0.04;
	}
}

void	add_nocollide(t_game *game, t_vecd *pos, t_vecd mov, t_sprite *s)
{
	if (collide_object(game, pos->x, pos->y, s))
	{
		pos->x += mov.x;
		pos->y += mov.y;
		return ;
	}
	if (!map_get(&game->map, floor(pos->x + mov.x), floor(pos->y)) && \
		!collide_object(game, pos->x + mov.x, pos->y, s))
	{
		pos->x += mov.x;
	}
	if (!map_get(&game->map, floor(pos->x), floor(pos->y + mov.y)) && \
		!collide_object(game, pos->x, pos->y + mov.y, s))
	{
		pos->y += mov.y;
	}
}
