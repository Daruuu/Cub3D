/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_doors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:28:44 by yamir             #+#    #+#             */
/*   Updated: 2025/06/01 19:36:56 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DOORS_H
# define CUB_DOORS_H

# include "../cub.h"

typedef struct s_door_r
{
	t_shape		draw;
	t_vecd		pos;
	t_vecd		end;
	double		dist;
	double		end_dist;
	double		sprite_angle;
	double		end_angle;
	double		view_dist;
	double		curr_angle;
	float		ratio;
	float		ratio2;
	bool		inverted;
	bool		rotated;
	t_sprite	*sprite;
	t_img		*img;
	float		dim;
	t_vec		offset;
	int			color;
}				t_door_r;

bool			draw_door(t_img *img, t_vars *vars, t_sprite s);

#endif
