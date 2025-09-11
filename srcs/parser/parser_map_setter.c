/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_setter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 21:46:12 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_map_setter.h"

int	set_player(t_game *game, char c, t_vec p)
{
	int	val;

	if (c == 'E')
		val = 0;
	else if (c == 'S')
		val = 1;
	else if (c == 'W')
		val = 2;
	else if (c == 'N')
		val = 3;
	else
		return (0);
	if (game->player.health != 0)
		handle_error(game, ERROR_DUPLICATE_PLAYER, NULL);
	game->player = make_player();
	game->player.pos.x = p.x + 0.50001;
	game->player.pos.y = p.y + 0.50001;
	game->player.s_pos.x = game->player.pos.x;
	game->player.s_pos.y = game->player.pos.y;
	game->player.yaw = M_PI / 2.0 * val;
	return (1);
}

int	set_sprite(t_game *game, char c, t_vec p)
{
	t_vecd		pos;

	pos.x = p.x + 0.5;
	pos.y = p.y + 0.5;
	if (c == '2')
		sprite_pf(&(game->sprites), pos, OBJ, &(game->sprite_img));
	else if (game->bonus && c == 'D')
	{
		pos.x = p.x;
		pos.y = p.y;
		sprite_pf(&(game->sprites), pos, DOOR, &(game->door_img));
	}
	else
		return (0);
	return (1);
}

int	set_entity(t_game *game, char c, t_vec p)
{
	t_vecd		pos;

	pos.x = p.x + 0.5;
	pos.y = p.y + 0.5;
	if (game->bonus && c == 'G')
		sprite_pf(&(game->sprites), pos, GOOMBA, &(game->goomba_img));
	else if (game->bonus && c == 'H')
		sprite_pf(&(game->sprites), pos, HEALTH, &(game->health_img));
	else
		return (0);
	return (1);
}

int	set_pathfinder(t_game *game, char c, t_vec p)
{
	if (game->bonus && c == 'P')
	{
		if (game->pathfinder.x != -1)
			handle_error(game, ERROR_DUPLICATE_PATHFINDER, NULL);
		game->pathfinder = p;
		return (1);
	}
	return (0);
}
