/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 21:17:48 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/07 21:17:51 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

# include "srcs/utils/cub_vec.h"
# include "srcs/utils/cub_rot.h"
# include "srcs/utils/cub_utils.h"
# include "srcs/render/cub_blur.h"
# include "srcs/world/cub_map.h"
# include "srcs/utils/cub_line_reader.h"
# include "srcs/other/cub_sound.h"
# include "include/cub_sprite_type.h"
# include "include/cub_cardinal_enum.h"
# include "include/cub_keybinds_struct.h"
# include "include/cub_sprite_struct.h"
# include "include/cub_player_struct.h"
# include "include/cub_raycast_struct.h"
# include "include/cub_mouseover_struct.h"
# include "include/cub_floor_render.h"
# include "include/bmp_partial_alligned_header.h"
# include "include/cub_walls.h"

#define  TITLE_WINDOWS "Cub3D Ana & Daru"
# define COLOR_UNSET 0xDB000000

#define  FAIL_MLX "Failed to initialize mlx."
# define ERROR_FORMAT "Cub is unproperly formated."
# define ERROR_MAP_UNCLOSED "Map is not enclosed."
# define ERROR_INVALID_DOOR_POS "Invalid door position."
# define ERROR_FILE_TYPE   "Unknown file type."
# define ERROR_USAGE_CUB       "Usage: cub3D [cub file]"


# define FPS60 16666
# define FPS50 20000
# define FPS_BONUS 25000	//	using this default
# define FPS30 33333

typedef struct s_vars
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
}					t_vars;

int					render_next_frame(t_vars *vars);

#endif
