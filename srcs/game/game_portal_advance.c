/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_portal_advance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 15:07:58 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_portal.h"

void	translate_portal(t_vecd *ref, t_cardinal card, t_portal *pt)
{
	t_vec	vec;

	ref->x += (pt->link->pos.x - pt->pos.x);
	ref->y += (pt->link->pos.y - pt->pos.y);
	if (get_opposite(card) == pt->link->card)
	{
		vec = get_direction(card);
		ref->x += vec.x;
		ref->y += vec.y;
	}
}

void	translate_portal_3(t_vec3d *ref, t_cardinal card, t_portal *pt)
{
	t_vec	vec;

	ref->x += (pt->link->pos.x - pt->pos.x);
	ref->y += (pt->link->pos.y - pt->pos.y);
	if (get_opposite(card) == pt->link->card)
	{
		vec = get_direction(card);
		ref->x += vec.x;
		ref->y += vec.y;
	}
}

void	handle_portal_creation(t_game *game)
{
	t_mouseover	over;

	over = get_mouseover(game);
	if (game->first_portal && !game->second_portal)
	{
		if (over.card != get_opposite(game->first_portal->card))
		{
			free(game->first_portal);
			game->first_portal = NULL;
		}
	}
	if (game->first_portal && game->second_portal)
	{
		free(game->first_portal);
		free(game->second_portal);
		game->first_portal = NULL;
		game->second_portal = NULL;
	}
	if (over.found)
		if (create_portal(game, over.pos.x, over.pos.y, over.card))
			game->shoot = 50;
}
