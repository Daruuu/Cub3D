/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprite_enemy.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 21:16:42 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SPRITE_ENEMY_H
# define GAME_SPRITE_ENEMY_H

# include "../cub3D.h"
# include "../game/game_collision.h"
# include "game_sprite_manager.h"
# include "game_sprite_door.h"

void	handle_goomba(t_sprite *curr, t_game *game);

#endif
