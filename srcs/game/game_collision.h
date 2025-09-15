/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_collision.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:39:50 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_COLLISION_H
# define GAME_COLLISION_H

# include "../math/vector_math.h"
# include "../input/input_handler.h"
# include "game_map.h"
# include "game_portal.h"

bool	collide_object(t_game *game, double x, double y, t_sprite *goomba);
void	collidex(t_game *game, t_player *player);
void	collidey(t_game *game, t_player *player);
void	add_nocollide(t_game *game, t_vecd *pos, t_vecd mov, t_sprite *s);

#endif
