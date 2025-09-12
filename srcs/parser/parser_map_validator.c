/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_validator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:18:55 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 03:13:29 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_map_validator.h"
#include "../init_game/error_handler.h"

void	check_textures_custom(t_game *game)
{
	if (!game->skybox.img)
		handle_warning(game, "Missing skybox texture, using color instead.");
	if (!game->gun.img)
		handle_warning(game, "Missing gun texture, hiding it.");
	if (!game->dash.img)
		handle_warning(game, "Missing dashboard overlay texture, ignoring.");
	if (!game->floor.img)
		handle_warning(game, "Missing floor texture, using color instead.");
	if (!game->door_img.img)
		handle_error(game, "Missing door texture.", "DOOR [.xpm]");
	if (!game->portal.img)
		handle_warning(game, "Missing portal texture, disabling them.");
	if (!game->goomba_img.img)
		handle_error(game, "Missing goomba texture.", "GOOMBA [.xpm]");
	if (!game->health_img.img)
		handle_error(game, "Missing health kit texture.", "HK [.xpm]");
	if (game->walls.north.width != game->portal.width || \
		game->walls.north.height != game->portal.height || \
		game->walls.south.width != game->portal.width || \
		game->walls.south.height != game->portal.height || \
		game->walls.west.width != game->portal.width || \
		game->walls.west.height != game->portal.height || \
		game->walls.east.width != game->portal.width || \
		game->walls.east.height != game->portal.height)
		handle_error(game, "Portal and wall texture sizes differ!", NULL);
}

void	check_textures(t_game *game)
{
	if (!game->sprite_img.img)
		handle_error(game, "Missing sprite texture.", NULL);
	if (!game->walls.north.img)
		handle_error(game, "Missing north wall texture.", NULL);
	if (!game->walls.south.img)
		handle_error(game, "Missing south wall texture.", NULL);
	if (!game->walls.west.img)
		handle_error(game, "Missing west wall texture.", NULL);
	if (!game->walls.east.img)
		handle_error(game, "Missing east wall texture.", NULL);
}

void	check_define(t_game *game)
{
	if (game->resx <= 0 || game->resy <= 0)
		handle_error(game, "Resolution not properly set.", NULL);
	if (game->resx > 5218 || game->resy > 5218)
		handle_error(game, "Resolution too big for mlx...", NULL);
	if ((unsigned int)(game->top_color) == 0xDB000000)
		handle_error(game, "Ceeling color not set.", NULL);
	if ((unsigned int)(game->bottom_color) == 0xDB000000)
		handle_error(game, "Bottom color not set.", NULL);
	if (game->player.health == 0x0)
		handle_error(game, "Player not set.", NULL);
	check_textures(game);
	if (game->bonus)
		check_textures_custom(game);
}
