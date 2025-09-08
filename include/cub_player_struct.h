/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/08 17:16:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PLAYER_STRUCT_H
# define CUB_PLAYER_STRUCT_H

# include "cub_keybinds_struct.h"
# include "../srcs/utils/cub_vec.h"

typedef struct s_player
{
	t_vec3d			pos;
	t_vecd			s_pos;
	t_vec3d			render;
	t_vec3d			motion;
	t_keybinds		keybinds;
	float			health;
	double			yaw;
	double			pitch;
	double			motion_yaw;
	double			motion_pitch;
}					t_player;

#endif
