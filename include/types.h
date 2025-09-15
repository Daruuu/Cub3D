/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/XX XX:XX:XX by dasalaza          #+#    #+#             */
/*   Updated: 2025/01/XX XX:XX:XX by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include <math.h>

// ===================== FORWARD DECLARATIONS ===================== //
typedef struct s_img		t_img;
typedef struct s_vec		t_vec;
typedef struct s_vecd		t_vecd;
typedef struct s_vec3d		t_vec3d;
typedef struct s_shape		t_shape;
typedef struct s_rot		t_rot;
typedef struct s_keybinds	t_keybinds;
typedef struct s_blur		t_blur;
typedef struct s_map		t_map;
typedef struct s_sprite		t_sprite;
typedef struct s_line		t_line;
typedef struct s_walls		t_walls;
typedef struct s_portal		t_portal;
typedef struct s_sounds		t_sounds;

// ===================== ENUMS ===================== //
typedef enum e_cardinal
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}					t_cardinal;

typedef enum e_sprite_k
{
	OBJ,
	GOOMBA,
	DOOR,
	HEALTH
}				t_sprite_k;

// ===================== CORE STRUCTURES ===================== //
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

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_player		player;
	t_blur			blur;
	t_map			map;
	t_sprite		*sprites;
	double			resx;
	double			resy;
	t_line			*file;
	t_walls			walls;
	t_img			floor;
	t_img			portal;
	t_img			skybox;
	t_img			gun;
	t_img			dash;
	t_img			sprite_img;
	t_img			health_img;
	t_img			goomba_img;
	t_img			door_img;
	t_portal		*first_portal;
	t_portal		*second_portal;
	double			fov;
	double			cam_width;
	double			*depth;
	int				shoot;
	int				time;
	int				top_color;
	int				bottom_color;
	int				render_distance;
	bool			should_dim;
	t_vec			*last_path;
	t_vec			pathfinder;
	float			bob;
	bool			bonus;
	bool			bmp;
	t_sounds		sounds;
	unsigned long	delay;
}					t_game;

// ===================== RENDER STRUCTURES ===================== //
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

typedef struct s_mouseover
{
	bool			found;
	t_vec			pos;
	t_cardinal		card;
}					t_mouseover;

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

#endif // TYPES_H
