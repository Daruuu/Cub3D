/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_setter.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:22:38 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:22:39 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_SETTER_H
# define CUB_MAP_SETTER_H

# include "../cub3D.h"
# include "../world/cub_player.h"
# include "../utils/cub_error.h"
# include "../sprites/cub_sprites.h"

int		set_player(t_vars *vars, char c, t_vec p);
int		set_sprite(t_vars *vars, char c, t_vec p);
int		set_entity(t_vars *vars, char c, t_vec p);
int		set_pathfinder(t_vars *vars, char c, t_vec p);

#endif
