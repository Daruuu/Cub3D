/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:36:02 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:36:02 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "cub.h"
# include "world/cub_player.h"
# include "render/cub_raycast.h"
# include "render/cub_floor.h"
# include "render/cub_hud.h"
# include "render/cub_bitmap.h"

# include "parser/cub_file.h"
# include "pathfinder/cub_pathfinder.h"
# include "utils/cub_error.h"
# include "utils/cub_checker.h"
# include "utils/cub_setup.h"

int		get_delay(bool startnow, int min, bool mac);
void	set_bonus(bool *bonus);

#endif
