/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collide.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 01:07:18 by dasalaza         ###   ########.fr       */
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
