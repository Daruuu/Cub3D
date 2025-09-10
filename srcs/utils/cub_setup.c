/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 00:47:18 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_setup.h"

void	init_void(t_vars *vars)
{
	vars->img.img = NULL;
	vars->floor.img = NULL;
	vars->portal.img = NULL;
	vars->skybox.img = NULL;
	vars->gun.img = NULL;
	vars->dash.img = NULL;
	vars->sprite_img.img = NULL;
	vars->health_img.img = NULL;
	vars->goomba_img.img = NULL;
	vars->door_img.img = NULL;
	vars->last_path = NULL;
	vars->first_portal = NULL;
	vars->second_portal = NULL;
	vars->sprites = NULL;
	vars->depth = NULL;
	vars->map.data = NULL;
	vars->walls.north.img = NULL;
	vars->walls.south.img = NULL;
	vars->walls.west.img = NULL;
	vars->walls.east.img = NULL;
	vars->blur.temp.img = NULL;
	vars->blur.dest.img = NULL;
	vars->file = NULL;
	init_sound_empty(&(vars->sounds));
}

void	init_default(t_vars *vars)
{
	vars->resx = 0;
	vars->resy = 0;
	vars->win = NULL;
	vars->time = 0;
	vars->bob = 0;
	vars->shoot = 0;
	vars->top_color = COLOR_UNSET;
	vars->bottom_color = COLOR_UNSET;
	vars->player.health = 0;
	vars->pathfinder.x = -1;
	vars->should_dim = true;
	vars->render_distance = 11;
	vars->bmp = false;
	vars->delay = 0;
	init_void(vars);
}
