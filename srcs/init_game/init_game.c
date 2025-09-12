/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:48:54 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 00:00:13 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_game.h"

void	init_void(t_game *game)
{
	game->img.img = NULL;
	game->floor.img = NULL;
	game->portal.img = NULL;
	game->skybox.img = NULL;
	game->gun.img = NULL;
	game->dash.img = NULL;
	game->sprite_img.img = NULL;
	game->health_img.img = NULL;
	game->goomba_img.img = NULL;
	game->door_img.img = NULL;
	game->last_path = NULL;
	game->first_portal = NULL;
	game->second_portal = NULL;
	game->sprites = NULL;
	game->depth = NULL;
	game->map.data = NULL;
	game->walls.north.img = NULL;
	game->walls.south.img = NULL;
	game->walls.west.img = NULL;
	game->walls.east.img = NULL;
	game->blur.temp.img = NULL;
	game->blur.dest.img = NULL;
	game->file = NULL;
	init_sound_empty(&(game->sounds));
}

void	init_default(t_game *game)
{
	game->resx = 0;
	game->resy = 0;
	game->win = NULL;
	game->time = 0;
	game->bob = 0;
	game->shoot = 0;
	game->top_color = COLOR_UNSET;
	game->bottom_color = COLOR_UNSET;
	game->player.health = 0;
	game->pathfinder.x = -1;
	game->should_dim = true;
	game->render_distance = 11;
	game->bmp = false;
	game->delay = 0;
	init_void(game);
}
