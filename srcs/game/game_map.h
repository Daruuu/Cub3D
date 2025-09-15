/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:57:33 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MAP_H
# define GAME_MAP_H

# define MAP_EMPTY 10
# define MAP_AIR 0
# define MAP_BLOCK 1
# define MAP_NOENTRY 4

# include <stdlib.h>
# include "../math/vector_math.h"

typedef struct s_map
{
	t_vec			size;
	int				buf_size;
	unsigned char	*data;
}					t_map;

t_map				make_empty(t_vec size);
void				map_set(t_map *map, int x, int y, int value);
int					map_get(t_map *map, int x, int y);
int					map_get_val(t_map *map, int x, int y);
void				clear_map(t_map *map);
#endif
