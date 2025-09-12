/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 12:19:22 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_player.h"

t_player	make_player(void)
{
	t_player	player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.pos.z = 0;
	player.s_pos.x = player.pos.x;
	player.s_pos.y = player.pos.y;
	player.motion.x = 0;
	player.motion.y = 0;
	player.motion.z = 0;
	player.health = 1;
	player.motion_yaw = 0;
	player.yaw = 0;
	player.pitch = -40;
	player.motion_yaw = 0;
	player.motion_pitch = 8;
	player.keybinds = make_keybinds();
	return (player);
}

/**
 * Handles player key inputs to update rotation, pitch, jump, sneak, and motion.
 * Applies speed modifiers and damping based on active keybinds and bonus mode.
 */
void	handle_keys(t_player *player, bool bonus)
{
	float	ratio;

	ratio = FRICTION_BASE_RATIO;
	if (player->keybinds.rotate_left && !player->keybinds.rotate_right)
		player->motion_yaw -= ROTATION_SPEED;
	else if (player->keybinds.rotate_right && !player->keybinds.rotate_left)
		player->motion_yaw += ROTATION_SPEED;
	else
		player->motion_yaw *= FRICTION_ROTATION_YAW;
	if (player->keybinds.rotate_up && bonus)
		player->motion_pitch += PITCH_ROTATION_SPEED;
	if (player->keybinds.rotate_down && bonus)
		player->motion_pitch -= PITCH_ROTATION_SPEED;
	if (player->keybinds.jump && player->pos.z <= GROUND_LIMIT && bonus)
		player->motion.z = JUMP_IMPULSE;
	if (player->keybinds.sneak && bonus)
		ratio *= SPEED_SNEAK_MODIFIER;
	else if (player->pos.z > AIR_LIMIT)
		ratio = SPEED_AIR_MODIFIER;
	player->motion.x *= ratio;
	player->motion.y *= ratio;
}

bool	should_bob(t_player *player)
{
	if (player->pos.z >= GROUND_LIMIT)
		return (false);
	if (player->keybinds.sneak)
		return (false);
	if (player->keybinds.forwards && !player->keybinds.backwards)
		return (true);
	if (player->keybinds.backwards && !player->keybinds.forwards)
		return (true);
	if (player->keybinds.left && !player->keybinds.right)
		return (true);
	if (player->keybinds.right && !player->keybinds.left)
		return (true);
	return (false);
}

void	update_render(t_player *player, t_game *game, bool bonus)
{
	player->render.x = player->pos.x;
	player->render.y = player->pos.y;
	player->render.z = player->pos.z;
	if (should_bob(player) && bonus)
		game->bob = fmin(1, game->bob + BOB_SPEED_INCREASE);
	else
		game->bob = fmax(0, game->bob - BOB_SPEED_DECREASE);
	play_sound_alt(game->sounds.walk, should_bob(player)
		&& player->render.z == 0 && !player->keybinds.jump, true);
	if (player->keybinds.sneak && bonus)
		player->render.z -= SNEAK_HEIGHT_OFFSET;
	player->render.y += cos(game->time / BOB_Y_FREQUENCY + BOB_Y_PHASE) * BOB_Y_AMPLITUDE * game->bob;
	player->render.x += sin(game->time / BOB_X_FREQUENCY + BOB_X_PHASE) * BOB_X_AMPLITUDE * game->bob;
	player->render.z += fabs(cos(game->time / BOB_Z_FREQUENCY) * BOB_Z_AMPLITUDE * game->bob);
	if (map_get(&game->map, floor(player->render.x), floor(player->render.y)))
	{
		player->render.x = player->pos.x;
		player->render.y = player->pos.y;
	}
}

/**
 * Updates the player's motion and position:
 * - Translates input into movement.
 * - Applies inertia, friction, and gravity.
 * - Checks and resolves collisions.
 * - Updates yaw (rotation) and pitch (view angle).
 * - Handles shooting cooldown.
 *
 * @param player Player state (position, motion, orientation).
 * @param game   Game context (world, settings, bonus).
 */
void	update_motion(t_player *player, t_game *game)
{
	double	cs;
	double	sn;
	t_vecd	move;

	move = player->keybinds.move;
	cs = cos(player->yaw);
	sn = sin(player->yaw);
	player->motion.x += move.x * cs - move.y * sn;
	player->motion.y += move.y * cs + move.x * sn;
	handle_keys(player, game->bonus);
	player->motion.z *= 0.97;
	player->motion_yaw *= 0.914;
	player->motion_pitch *= 0.82;
	collidex(game, player);
	collidey(game, player);
	player->pos.z = fmin(fmax(0, player->pos.z + player->motion.z - .078), .42);
	update_render(player, game, game->bonus);
	player->yaw += player->motion_yaw;
	player->pitch = fmin(game->resy / 4 - 4, fmax(-game->resy / 4, \
		player->pitch + player->motion_pitch));
	if (game->shoot > 0)
		game->shoot--;
}
