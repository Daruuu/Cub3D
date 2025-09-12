/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 23:47:35 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H

# include <stdbool.h>
# include <stdlib.h>
# include "../math/vector_math.h"

typedef struct s_keybinds
{
	bool		forwards;
	bool		backwards;
	bool		left;
	bool		right;
	bool		rotate_left;
	bool		rotate_right;
	bool		rotate_up;
	bool		rotate_down;
	bool		sneak;
	bool		jump;
	t_vecd		move;
}				t_keybinds;

// Input handling functions
void			set_keystate(t_keybinds *keybinds, int key, bool pressed);
int				key_press(int keycode, t_game *game);
int				key_lift(int keycode, t_game *game);
t_keybinds		make_keybinds(void);
void			update_keybinds(t_game *game);

#endif
