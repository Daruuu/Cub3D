/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprite_renderer.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 16:16:29 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SPRITES_RENDERER_H
# define GAME_SPRITES_RENDERER_H

# include "../cub3D.h"
# include "../game/game_collision.h"
# include "game_sprite_manager.h"
# include "game_sprite_door.h"
# include "game_sprite_enemy.h"

typedef struct s_sprite_r
{
	t_shape		draw;
	t_vec		v;
	t_vec		offset;
	int			color;
	t_vecd		pos;
	double		dist;
	double		sprite_angle;
	double		view_dist;
	float		dim;
}				t_sprite_r;

void			draw_sprites(t_vars *vars, bool skip);

#endif
