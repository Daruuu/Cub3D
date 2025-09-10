/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:36:02 by yamir             #+#    #+#             */
/*   Updated: 2025/09/10 15:54:57 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#include "../cub3D.h"
#include "../srcs/world/cub_player.h"
#include "../srcs/render/raycast_engine.h"
#include "../srcs/render/render_floor.h"
#include "../srcs/render/cub_hud.h"

#include "../srcs/parser/cub_file.h"
#include "../srcs/pathfinder/cub_pathfinder.h"
#include "../srcs/utils/cub_error.h"
#include "../srcs/utils/cub_checker.h"
#include "../srcs/utils/cub_setup.h"

int		get_delay(bool startnow, int min, bool mac);
void	set_bonus(bool *bonus);

#endif
