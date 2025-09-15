/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/XX XX:XX:XX by dasalaza          #+#    #+#             */
/*   Updated: 2025/01/XX XX:XX:XX by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

// ===================== WINDOW CONFIG ===================== //
# define TITLE_WINDOWS			"Cub3D Ana & Daru"
# define COLOR_UNSET			0xDB000000

// ===================== ERROR MESSAGES ===================== //
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

// ===================== PERFORMANCE CONSTANTS ===================== //
# define FPS60 16666
# define FPS50 20000
# define FPS_BONUS 25000	//	using this default
# define FPS30 33333

// ===================== GAME CONSTANTS ===================== //
# define PLAYER_SPEED_DEFAULT 0.0015
# define PLAYER_SPEED_BONUS   0.0085
# define ROTATION_SPEED_DEFAULT 0.0010
# define ROTATION_SPEED_BONUS   0.009

#endif // CONSTANTS_H
