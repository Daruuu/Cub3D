/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:35:04 by yamir             #+#    #+#             */
/*   Updated: 2025/06/01 19:38:44 by  yaramire        ###   ########.fr       */
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
