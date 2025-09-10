/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:05:32 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_pathfinder.h"

void	refresh_pathfinding(t_vars *vars)
{
	t_vec	startp;

	if (vars->time % 60 != 0)
		return ;
	if (vars->pathfinder.x == -1)
		return ;
	startp.x = floor(vars->player.pos.x);
	startp.y = floor(vars->player.pos.y);
	if (vars->last_path)
		free(vars->last_path);
	vars->last_path = astar(&vars->map, startp, vars->pathfinder, 2000);
}
