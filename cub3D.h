/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:37:01 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 21:37:02 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include "mlx/mlx.h"

// ===================== LEGACY INCLUDES (CURRENTLY ACTIVE) ================ //
# include "srcs/math/vector_math.h"
# include "srcs/math/rotation_math.h"
# include "srcs/graphics/image_operations.h"
# include "srcs/render/render_blur.h"
# include "srcs/game/game_map.h"
# include "srcs/file_loader/load_file.h"
# include "srcs/sound/audio_system.h"
# include "include/includes_cub.h"

# define TITLE_WINDOWS			"Cub3D Ana & Daru"
# define COLOR_UNSET			0xDB000000
# define FAIL_MLX				"Failed to initialize mlx."
# define ERROR_FORMAT			"Cub is unproperly formated."
# define ERROR_MAP_UNCLOSED		"Map is not enclosed."
# define ERROR_INVALID_DOOR_POS	"Invalid door position."
# define ERROR_FILE_TYPE		"Unknown file type."
# define ERROR_USAGE_CUB		"Usage: cub3D [cub file]"

// ===================== PARSER ERROR MESSAGES ===================== //
# define ERROR_DUPLICATE_RESOLUTION	"Duplicate resolution paramater."
# define ERROR_PARSING_RESOLUTION	"Error parsing resolution."
# define ERROR_DUPLICATE_TEXTURE		"Duplicate texture paramater."
# define ERROR_FAILED_LOAD_TEXTURE	"Failed to load texture."
# define ERROR_COLOR_SET_TWICE		"Color was set twice."
# define ERROR_READING_COLOR		"Error reading color."
# define ERROR_COULD_NOT_READ_AUDIO	"Could not read audio..."
# define ERROR_COULD_NOT_LOAD_FILE	"Could not load file."
# define ERROR_MAP_GRID_EMPTY		"Map grid is empty."
# define ERROR_FAILED_INIT_MAP		"Failed to initialize map."
# define ERROR_DUPLICATE_PLAYER		"Duplicate player in map."
# define ERROR_DUPLICATE_PATHFINDER	"Duplicate pathfinder in map."

# define FPS60 16666
# define FPS50 20000
# define FPS_BONUS 25000	//	using this default
# define FPS30 33333

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

int		render_next_frame(t_game *game);
int		get_delay(bool startnow, int min, bool mac);
void	set_bonus(bool *bonus);

#endif
