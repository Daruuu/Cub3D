/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprite_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 21:43:39 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_sprite_enemy.h"

void	refresh_path(t_sprite *curr, t_game *game, int maxtries)
{
	(void) maxtries;
	(void) curr;
	(void) game;
}
	/*
	// t_vec	startp;
	// t_vec	endp;
	// t_vec	*new;
	startp.x = floor(curr->pos.x);
	startp.y = floor(curr->pos.y);
	endp.x = floor(game->player.pos.x);
	endp.y = floor(game->player.pos.y);
	new = astar(&game->map, startp, endp, maxtries);
	if (new)
	{
		if (curr->path)
			free(curr->path);
		curr->path = new;
		curr->path_index = 0;
	}
*/

t_vec3d	get_next_move(t_sprite *curr, t_game *game)
{
	t_vec	dest;
	t_vec3d	ret;

	while (curr->path)
	{
		dest = curr->path[curr->path_index];
		if (dest.x == -999 && dest.y == -999)
		{
			free(curr->path);
			curr->path = NULL;
			curr->path_index = 0;
		}
		else if (dist2di(curr->pos, dest) < 0.55 && ++curr->path_index)
			continue ;
		ret.x = dest.x + 0.5;
		ret.y = dest.y + 0.5;
		return (ret);
	}
	if (square_dist(game->player.pos, curr->pos) > 9)
	{
		ret.x = curr->pos.x;
		ret.y = curr->pos.y;
		return (ret);
	}
	return (game->player.pos);
}

void	handle_action(t_game *game, t_sprite *curr, t_vecd mov)
{
	if (curr->last_hurt > 20 && game->player.pos.z > \
		0.11 && game->player.motion.z < 0.085)
	{
		curr->dead = true;
		game->player.motion.z += 0.025;
		free(curr->path);
		curr->path = NULL;
		curr->path_index = 0;
		play_sound(game->sounds.stomp);
	}
	else
	{
		normalize(&mov, 0.2);
		game->player.motion.x += mov.x;
		game->player.motion.y += mov.y;
		game->player.motion.z = 0.12;
		game->player.health -= 0.101;
		curr->last_hurt = 0;
		play_sound(game->sounds.hurt);
	}
}

void	handle_goomba(t_sprite *curr, t_game *game)
{
	t_vecd	mov;
	t_vec3d	next;

	if (curr->last_hurt % 1000 == 20)
		refresh_path(curr, game, 350);
	else if (curr->last_hurt % 70 == 0)
		refresh_path(curr, game, 250);
	next = get_next_move(curr, game);
	curr->last_hurt++;
	mov.x = (next.x - curr->pos.x);
	mov.y = (next.y - curr->pos.y);
	normalize(&mov, 0.04);
	if (square_dist(game->player.pos, curr->pos) < 0.14 && curr->last_hurt > 50)
		handle_action(game, curr, mov);
	add_nocollide(game, &curr->pos, mov, curr);
}
