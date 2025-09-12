/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/10 17:04:39 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_keybinds.h"

/*
** Updates the player keybinds
*/

void	set_keystate(t_keybinds *keybinds, int key, bool pressed)
{
	if (key == ROTATE_LEFT)
		keybinds->rotate_left = pressed;
	else if (key == ROTATE_RIGHT)
		keybinds->rotate_right = pressed;
	if (key == ROTATE_UP)
		keybinds->rotate_up = pressed;
	else if (key == ROTATE_DOWN)
		keybinds->rotate_down = pressed;
	else if (key == FORWARD_W_Z)
		keybinds->forwards = pressed;
	else if (key == BACK_S_S)
		keybinds->backwards = pressed;
	else if (key == LEFT_A_Q)
		keybinds->left = pressed;
	else if (key == RIGHT_D_D)
		keybinds->right = pressed;
	else if (key == JUMP_SPACE)
		keybinds->jump = pressed;
	else if (key == SNEAK_MAJ)
		keybinds->sneak = pressed;
}

/*
** Handles key presses and stuffed portal adding logic here too
*/

int	key_press(int keycode, t_game *game)
{
	set_keystate(&(game->player.keybinds), keycode, true);
	if (keycode == ESC)
		clean_and_exit(0, game);
	if (keycode == MAKE_PORTAL && game->portal.img)
	{
		return (0);
		handle_portal_creation(game);
	}
	return (0);
}

/*
** Handles key lifting
*/

int	key_lift(int keycode, t_game *game)
{
	set_keystate(&(game->player.keybinds), keycode, false);
	return (0);
}

/*
** Inits the keybinds
*/

t_keybinds	make_keybinds(void)
{
	t_keybinds	keys;

	keys.forwards = false;
	keys.backwards = false;
	keys.left = false;
	keys.right = false;
	keys.rotate_left = false;
	keys.rotate_right = false;
	keys.rotate_up = false;
	keys.rotate_down = false;
	keys.sneak = false;
	keys.jump = false;
	keys.move.x = 0;
	keys.move.y = 0;
	return (keys);
}

/*
** Handles the player moving based on the keybinds
** Different speeds for normal vs bonus mode:
** - Normal mode: Slower movement (0.0045/0.0035)
** - Bonus mode: Original faster movement (0.0085/0.0065)
*/

void	update_keybinds(t_game *game)
{
	t_keybinds	*keys;

	keys = &(game->player.keybinds);
	keys->move.x = 0;
	if (!(keys->forwards && keys->backwards))
	{
		if (keys->forwards)
			keys->move.x = 1;
		else if (keys->backwards)
			keys->move.x = -1;
	}
	keys->move.y = 0;
	if (!(keys->left && keys->right))
	{
		if (keys->left)
			keys->move.y = -1;
		else if (keys->right)
			keys->move.y = 1;
	}
	normalize(&(keys->move), PLAYER_SPEED);
}
