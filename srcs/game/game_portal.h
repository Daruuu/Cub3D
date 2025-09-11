/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 14:55:46 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PORTAL_H
# define CUB_PORTAL_H

# include "../cub3D.h"
# include "game_directions.h"
# include "game_portal_render.h"
# include <stdlib.h>

bool		create_portal(t_vars *vars, int x, int y, t_cardinal card);
t_portal	*get_portal(t_vars *vars, int x, int y, t_cardinal card);
t_portal	*get_empty_portal(t_vars *vars, int x, int y, t_cardinal card);
void		translate_portal(t_vecd *ref, t_cardinal card, t_portal *pt);
void		translate_portal_3(t_vec3d *ref, t_cardinal card, t_portal *pt);
void		handle_portal_creation(t_vars *vars);

#endif
