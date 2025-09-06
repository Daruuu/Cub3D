/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:19:59 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 18:59:20 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_KEYBINDS_STRUCT_H
# define CUB_KEYBINDS_STRUCT_H

# include "../utils/cub_vec.h"

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
