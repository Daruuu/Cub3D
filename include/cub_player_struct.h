/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:20:24 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 18:59:53 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PLAYER_STRUCT_H
# define CUB_PLAYER_STRUCT_H

# include "cub_keybinds_struct.h"
# include "../utils/cub_vec.h"

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
