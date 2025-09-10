/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/08 17:15:01 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_KEYBINDS_STRUCT_H
# define CUB_KEYBINDS_STRUCT_H

# include "../srcs/utils/cub_vec.h"

typedef struct s_keybinds
{
	bool			forwards;
	bool			backwards;
	bool			left;
	bool			right;
	bool			rotate_left;
	bool			rotate_right;
	bool			rotate_up;
	bool			rotate_down;
	bool			jump;
	bool			sneak;
	t_vecd			move;
}					t_keybinds;

#endif
