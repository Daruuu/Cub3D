/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_cub.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:30:39 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/10 13:42:49 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_CUB_H
#define INCLUDES_CUB_H

# include "../srcs/utils/cub_vec.h"
# include "../srcs/utils/cub_rot.h"
# include "../srcs/utils/cub_utils.h"

typedef enum e_cardinal
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}					t_cardinal;

typedef struct s_floor_render
{
	t_rot			start;
	t_rot			end;
	t_vecd			s;
	t_vecd			step;
	t_vecd			start_pos;
	t_vecd			tex;
	int				color;
	int				midpi;
	double			mid;
	double			row_len;
	double			dim;
	double			ang;
}					t_floor_render;

typedef struct s_keybinds
{
	bool			forwards;
	bool			backwards;
	bool			left;
	bool			right;
	bool			rotate_left;
	bool			rotate_right;
	bool			rotate_up;
	bool			rotate_down;
	bool			jump;
	bool			sneak;
	t_vecd			move;
}					t_keybinds;

typedef struct s_mouseover
{
	bool			found;
	t_vec			pos;
	t_cardinal		card;
}					t_mouseover;

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

typedef struct s_portal_render
{
	t_shape					line;
	float					offset;
	struct s_portal_render	*next;
}							t_portal_render;

typedef struct s_portal
{
	t_vec					pos;
	t_cardinal				card;
	struct s_portal			*link;
}							t_portal;

typedef struct s_ray
{
	t_vecd			st_cos;
	t_vecd			st_sin;
	double			ln_cos;
	double			ln_sin;
}					t_ray;

typedef struct s_trace
{
	t_ray			ray;
	t_ray			step;
	t_rot			rot;
	t_shape			line;
	t_vec			pos;
	t_vecd			ref;
	t_portal_render	*portal;
	t_cardinal		card;
	t_portal		*pt;
	int				i;
	double			newa;
	double			len;
	double			offset;
}					t_trace;

typedef enum e_sprite_k
{
	OBJ,
	GOOMBA,
	DOOR,
	HEALTH
}				t_sprite_k;

typedef struct s_sprite
{
	t_sprite_k		kind;
	t_vecd			pos;
	t_img			*texture;
	int				last_hurt;
	bool			dead;
	int				path_index;
	t_vec			*path;
	struct s_sprite	*next;
}					t_sprite;

typedef struct s_walls
{
	t_img			north;
	t_img			south;
	t_img			east;
	t_img			west;
}					t_walls;

#endif //INCLUDES_CUB_H