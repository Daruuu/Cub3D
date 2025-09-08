/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collide.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:34:38 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:34:38 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_COLLIDE_H
# define CUB_COLLIDE_H

# include "../utils/cub_vec.h"
# include "../utils/cub_keybinds.h"
# include "cub_map.h"
# include "cub_portal.h"

bool	collide_object(t_vars *vars, double x, double y, t_sprite *goomba);
void	collidex(t_vars *vars, t_player *player);
void	collidey(t_vars *vars, t_player *player);
void	add_nocollide(t_vars *vars, t_vecd *pos, t_vecd mov, t_sprite *s);

#endif
