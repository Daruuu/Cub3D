/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:20:48 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 19:15:48 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITE_STRUCT_H
# define CUB_SPRITE_STRUCT_H

# include "cub_sprite_type.h"

typedef struct s_sprite
{
	t_sprite_k		kind;
	t_vecd			pos;
	t_img			*texture;
	int				last_hurt;
	bool			dead;
	int				path_index;
	t_vec			*path;
	struct s_sprite	*next;
}					t_sprite;

#endif
