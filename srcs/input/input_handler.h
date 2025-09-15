/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/12 03:12:40 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H

# include <stdbool.h>
# include <stdlib.h>
# include "../math/vector_math.h"

// Forward declaration
typedef struct s_game	t_game;

// Key definitions
# if (LINUX)
#  define ROTATE_LEFT 0xff51
#  define ROTATE_RIGHT 0xff53
#  define ROTATE_UP 0xff52
#  define ROTATE_DOWN 0xff54
#  define FORWARD_W_Z 0x0077
#  define BACK_S_S 0x0073
#  define RIGHT_D_D 0x0064
#  define LEFT_A_Q 0x0061
#  define JUMP_SPACE 0x0020
#  define SNEAK_MAJ 0xffe1
#  define MAKE_PORTAL 0xff0d
#  define ESC 0xff1b
# else
#  define ROTATE_LEFT 123
#  define ROTATE_RIGHT 124
#  define ROTATE_UP 126
#  define ROTATE_DOWN 125
#  define FORWARD_W_Z 13
#  define BACK_S_S 1
#  define RIGHT_D_D 2
#  define LEFT_A_Q 0
#  define JUMP_SPACE 49
#  define SNEAK_MAJ 3
#  define MAKE_PORTAL 36
#  define ESC 53
# endif

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
