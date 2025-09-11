/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_setter.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 15:36:33 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MAP_SETTER_H
# define PARSER_MAP_SETTER_H

# include "../cub3D.h"
# include "../game/game_player.h"
# include "../utils/cub_error.h"
# include "../sprites/cub_sprites.h"

int		set_player(t_vars *vars, char c, t_vec p);
int		set_sprite(t_vars *vars, char c, t_vec p);
int		set_entity(t_vars *vars, char c, t_vec p);
int		set_pathfinder(t_vars *vars, char c, t_vec p);

#endif
