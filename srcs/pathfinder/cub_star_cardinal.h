/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_star_cardinal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:05:54 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STAR_CARDINAL_H
# define CUB_STAR_CARDINAL_H

# include "../utils/cub_vec.h"
# include "cub_node.h"
# include "../world/cub_map.h"
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

t_vec	get_neighbor(int rot, t_vec origin);
bool	is_empty(t_map *map, t_node *start, t_node *end);
bool	is_in_map(t_map *map, t_vec pos);

#endif
