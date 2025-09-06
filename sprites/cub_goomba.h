/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_goomba.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:28:59 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:28:59 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GOOMBA_H
# define CUB_GOOMBA_H

# include "../cub.h"
# include "../world/cub_collide.h"
# include "cub_sprite_list.h"
# include "cub_doors.h"
# include "../pathfinder/cub_astar.h"

void	handle_goomba(t_sprite *curr, t_vars *vars);

#endif
