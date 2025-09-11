/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:12:44 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/10 16:08:49 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_engine.h"

t_vec	get_collide_pos(t_trace trace)
{
	t_vec	pos;

	if (trace.ray.ln_cos > trace.ray.ln_sin)
	{
		pos.x = floor(trace.ref.x + trace.ray.st_sin.x);
		pos.y = floor(trace.ref.y + trace.ray.st_sin.y + trace.rot.sin / 2);
		return (pos);
	}
	pos.x = floor(trace.ref.x + trace.ray.st_cos.x + trace.rot.cos / 2);
	pos.y = floor(trace.ref.y + trace.ray.st_cos.y);
	return (pos);
}

int	check_colide(t_game *game, t_vec pos)
{
	return (map_get(&game->map, pos.x, pos.y));
}

void	render_portal(t_shape line, float offset, t_game *game)
{
	set_portal_strip(&(game->img), line, &(game->portal), offset);
}

t_img	*get_texture(t_game *game, t_cardinal card)
{
	if (card == EAST)
		return (&(game->walls.north));
	if (card == WEST)
		return (&(game->walls.south));
	if (card == NORTH)
		return (&(game->walls.west));
	return (&(game->walls.east));
}

/*
** Does a simple raycast to get the mouseover block, used by the portal gun
*/

t_mouseover	get_mouseover(t_game *game)
{
	t_trace		trace;
	t_mouseover	over;

	over.found = false;
	trace.rot = make_rot(game->player.yaw);
	trace.ray = get_init_ray(&(trace.rot), \
		game->player.pos.x, game->player.pos.y);
	trace.step = get_init_ray(&(trace.rot), 0, 0);
	trace.ref.x = game->player.pos.x;
	trace.ref.y = game->player.pos.y;
	trace.i = 0;
	while (trace.i < 15)
	{
		trace.pos = get_collide_pos(trace);
		if (check_colide(game, trace.pos))
		{
			over.card = get_cardinal(trace);
			over.pos = trace.pos;
			over.found = true;
			break ;
		}
		cast_forward(&(trace.ray), trace.step);
		trace.i++;
	}
	return (over);
}
