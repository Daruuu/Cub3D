/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 15:00:09 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/10 15:40:07 by dasalaza         ###   ########.fr       */
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

void	handle_keys(t_player *player, bool bonus)
{
	float	ratio;

	ratio = 0.88;
	if (player->keybinds.rotate_left && !player->keybinds.rotate_right)
		player->motion_yaw -= ROTATION_SPEED;
	else if (player->keybinds.rotate_right && !player->keybinds.rotate_left)
		player->motion_yaw += ROTATION_SPEED;
	else
		player->motion_yaw *= 0.895;
	if (player->keybinds.rotate_up && bonus)
		player->motion_pitch += 4;
	if (player->keybinds.rotate_down && bonus)
		player->motion_pitch -= 4;
	if (player->keybinds.jump && player->pos.z <= 0.0001 && bonus)
		player->motion.z = 0.128;
	if (player->keybinds.sneak && bonus)
		ratio *= 0.67;
	else if (player->pos.z > 0.001)
		ratio = 0.9;
	player->motion.x *= ratio;
	player->motion.y *= ratio;
}

bool	should_bob(t_player *player)
{
	if (player->pos.z >= 0.0001)
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
		game->bob = fmin(1, game->bob + 0.04);
	else
		game->bob = fmax(0, game->bob - 0.04);
	play_sound_alt(game->sounds.walk, should_bob(player)
		&& player->render.z == 0 && !player->keybinds.jump, true);
	if (player->keybinds.sneak && bonus)
		player->render.z -= 0.05;
	player->render.y += cos(game->time / 6.0 + 34) * 0.01 * game->bob;
	player->render.x += sin(game->time / 4.8 + 56) * 0.01 * game->bob;
	player->render.z += fabs(cos(game->time / 7.5) * 0.03 * game->bob);
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
