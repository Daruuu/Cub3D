/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprite_door.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 16:26:52 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SPRITE_DOORS_H
# define GAME_SPRITE_DOORS_H

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

bool			draw_door(t_img *img, t_game *game, t_sprite s);

#endif
