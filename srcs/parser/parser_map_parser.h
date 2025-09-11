/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 15:30:12 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MAP_PARSER_H
# define PARSER_MAP_PARSER_H

# include "../cub3D.h"
# include "parser_map_setter.h"
# include "../utils/cub_error.h"

t_vec	get_map_size(t_line *start);
int		set_map(t_vars *vars, char c, t_vec p);
void	handle_door_rotation(t_vars *vars);
bool	is_map_valid(t_map *map);

#endif
