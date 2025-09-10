/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 01:09:19 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PLAYER_H
# define CUB_PLAYER_H

# include "../utils/cub_vec.h"
# include "../utils/cub_keybinds.h"
# include "cub_map.h"
# include "cub_collide.h"
# include "cub_portal.h"

t_player	make_player(void);
void		update_motion(t_player *player, t_vars *vars);
bool		should_bob(t_player *player);

#endif
