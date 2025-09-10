/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_doors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:13:46 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DOORS_H
# define CUB_DOORS_H

# include "../cub3D.h"

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
