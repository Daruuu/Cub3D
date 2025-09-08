/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:35:37 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:35:37 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PORTAL_H
# define CUB_PORTAL_H

# include "../cub3D.h"
# include "cub_cardinal.h"
# include "cub_portal_list.h"
# include <stdlib.h>

bool		create_portal(t_vars *vars, int x, int y, t_cardinal card);
t_portal	*get_portal(t_vars *vars, int x, int y, t_cardinal card);
t_portal	*get_empty_portal(t_vars *vars, int x, int y, t_cardinal card);
void		translate_portal(t_vecd *ref, t_cardinal card, t_portal *pt);
void		translate_portal_3(t_vec3d *ref, t_cardinal card, t_portal *pt);
void		handle_portal_creation(t_vars *vars);

#endif
