/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/10 15:49:48 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_KEYBINDS_H
# define CUB_KEYBINDS_H

# include "cub_vec.h"
# include "../cub3D.h"
# include "../render/raycast_engine.h"
# include "cub_cleaner.h"
# include <stdbool.h>

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

void			set_keystate(t_keybinds *keybinds, int key, bool pressed);
int				key_press(int keycode, t_game *game);
int				key_lift(int keycode, t_game *game);
void			update_keybinds(t_game *game);
t_keybinds		make_keybinds(void);

#endif
