/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_astar.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:04:23 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ASTAR_H
# define CUB_ASTAR_H

# include "cub_node.h"
# include "cub_star_cardinal.h"
# include "cub_path.h"
# include "../utils/cub_vec.h"
# include "../utils/cub_utils.h"
# include "../world/cub_map.h"
# include <unistd.h>

typedef struct s_astar	t_astar;
struct			s_astar
{
	t_node		*list_open;
	t_node		*list_closed;
	t_node		*goal;
	t_vec		start_pos;
	t_vec		end_pos;
	t_map		*map;
	char		*closed_map;
};

t_vec			*astar(t_map *map, t_vec start, t_vec end,
					unsigned int maxtries);

#endif
