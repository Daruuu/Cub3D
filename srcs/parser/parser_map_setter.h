/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_setter.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 19:51:44 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MAP_SETTER_H
# define PARSER_MAP_SETTER_H

# include "../cub3D.h"
# include "../game/game_player.h"
# include "../init_game/error_handler.h"
# include "../game_sprites/game_sprite_renderer.h"

int		set_player(t_game *game, char c, t_vec p);
int		set_sprite(t_game *game, char c, t_vec p);
int		set_entity(t_game *game, char c, t_vec p);
int		set_pathfinder(t_game *game, char c, t_vec p);

#endif
