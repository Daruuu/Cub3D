/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:29:44 by yamir             #+#    #+#             */
/*   Updated: 2025/06/01 19:35:50 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITES_H
# define CUB_SPRITES_H

# include "../cub3D.h"
# include "../world/cub_collide.h"
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
