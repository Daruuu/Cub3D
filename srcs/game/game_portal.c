/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_portal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 01:09:29 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_portal.h"

bool	link_portal(t_game *game, int x, int y, t_portal *portal)
{
	t_vec		vec;

	portal->card = get_opposite(game->first_portal->card);
	vec = get_direction(portal->card);
	if (!map_get(&game->map, x - vec.x, y - vec.y)
		&& !(game->first_portal->pos.x == x && game->first_portal->pos.y == y))
	{
		game->first_portal->link = portal;
		game->second_portal = portal;
		game->second_portal->link = game->first_portal;
		return (true);
	}
	free(portal);
	return (false);
}

bool	create_portal(t_game *game, int x, int y, t_cardinal card)
{
	t_portal	*portal;

	portal = malloc(sizeof(t_portal));
	if (!portal)
		return (false);
	portal->pos.x = x;
	portal->pos.y = y;
	portal->card = card;
	portal->link = NULL;
	play_sound(game->sounds.portal);
	if (game->first_portal)
		return (link_portal(game, x, y, portal));
	game->first_portal = portal;
	return (true);
}

t_portal	*get_portal(t_game *game, int x, int y, t_cardinal card)
{
	if (game->second_portal && game->second_portal->card == card
		&& game->second_portal->pos.x == x && game->second_portal->pos.y == y
		&& game->second_portal->link != NULL)
		return (game->second_portal);
	if (game->first_portal && game->first_portal->card == card
		&& game->first_portal->pos.x == x && game->first_portal->pos.y == y
		&& game->first_portal->link != NULL)
		return (game->first_portal);
	return (NULL);
}

t_portal	*get_empty_portal(t_game *game, int x, int y, t_cardinal card)
{
	if (game->first_portal && game->first_portal->card == card
		&& game->first_portal->pos.x == x && game->first_portal->pos.y == y
		&& game->first_portal->link == NULL)
		return (game->first_portal);
	return (NULL);
}
