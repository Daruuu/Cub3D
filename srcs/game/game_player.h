/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 15:02:22 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_PLAYER_H
# define GAME_PLAYER_H

# include "../utils/cub_vec.h"
# include "../utils/cub_keybinds.h"
# include "game_map.h"
# include "game_collision.h"
# include "game_portal.h"

t_player	make_player(void);
void		update_motion(t_player *player, t_vars *vars);
bool		should_bob(t_player *player);

#endif
