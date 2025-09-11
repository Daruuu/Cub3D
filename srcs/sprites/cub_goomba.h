/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_goomba.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:46:47 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GOOMBA_H
# define CUB_GOOMBA_H

# include "../cub3D.h"
# include "../game/game_collision.h"
# include "cub_sprite_list.h"
# include "cub_doors.h"
# include "../pathfinder/cub_astar.h"

void	handle_goomba(t_sprite *curr, t_vars *vars);

#endif
