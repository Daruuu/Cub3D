/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:46:28 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITES_H
# define CUB_SPRITES_H

# include "../cub3D.h"
# include "../game/game_collision.h"
# include "cub_sprite_list.h"
# include "cub_doors.h"
# include "cub_goomba.h"

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
