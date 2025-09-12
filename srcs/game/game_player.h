/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 15:02:22 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_PLAYER_H
# define GAME_PLAYER_H

# include "../math/vector_math.h"
# include "../input/input_handler.h"
# include "game_map.h"
# include "game_collision.h"
# include "game_portal.h"

// ===================== PLAYER MOVEMENT CONSTANTS ===================== //
// Friction and damping values
# define FRICTION_BASE_RATIO			0.88f		// Base movement friction (88% retained)
# define FRICTION_ROTATION_YAW			0.895f		// Yaw rotation damping
# define FRICTION_ROTATION_PITCH			0.82f		// Pitch rotation damping
# define FRICTION_VERTICAL_MOTION		0.97f		// Vertical motion damping (gravity)
# define FRICTION_YAW_MOTION			0.914f		// Additional yaw motion damping

// Speed modifiers
# define SPEED_SNEAK_MODIFIER			0.67f		// Speed reduction when sneaking
# define SPEED_AIR_MODIFIER				0.9f		// Speed modifier when in air
# define PITCH_ROTATION_SPEED			4.0f		// Pitch rotation speed
# define JUMP_IMPULSE					0.128f		// Jump impulse strength

// Position thresholds
# define GROUND_LIMIT				0.0001f		// Ground detection threshold
# define AIR_LIMIT					0.001f		// Air detection threshold
# define MAX_JUMP_HEIGHT				0.42f		// Maximum jump height
# define GRAVITY_FORCE					0.078f		// Gravity force applied each frame

// Render and animation values
# define BOB_SPEED_INCREASE				0.04f		// Bob animation speed increase
# define BOB_SPEED_DECREASE				0.04f		// Bob animation speed decrease
# define SNEAK_HEIGHT_OFFSET			0.05f		// Height offset when sneaking
# define BOB_X_AMPLITUDE					0.01f		// Bob X-axis amplitude
# define BOB_Y_AMPLITUDE					0.01f		// Bob Y-axis amplitude
# define BOB_Z_AMPLITUDE					0.03f		// Bob Z-axis amplitude
# define BOB_X_FREQUENCY					4.8f		// Bob X-axis frequency
# define BOB_Y_FREQUENCY					6.0f		// Bob Y-axis frequency
# define BOB_Z_FREQUENCY					7.5f		// Bob Z-axis frequency
# define BOB_X_PHASE						56.0f		// Bob X-axis phase offset
# define BOB_Y_PHASE						34.0f		// Bob Y-axis phase offset

// Player initialization values
# define INITIAL_PITCH					-40.0f		// Initial pitch angle
# define INITIAL_MOTION_PITCH			8.0f		// Initial pitch motion
# define INITIAL_HEALTH					1.0f		// Initial player health

t_player	make_player(void);
void		update_motion(t_player *player, t_game *game);
bool		should_bob(t_player *player);

#endif
