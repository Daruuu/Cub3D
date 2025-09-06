/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:35:29 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 20:09:02 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_portal.h"

bool	link_portal(t_vars *vars, int x, int y, t_portal *portal)
{
	t_vec		vec;

	portal->card = get_opposite(vars->first_portal->card);
	vec = get_direction(portal->card);
	if (!map_get(&vars->map, x - vec.x, y - vec.y)
		&& !(vars->first_portal->pos.x == x && vars->first_portal->pos.y == y))
	{
		vars->first_portal->link = portal;
		vars->second_portal = portal;
		vars->second_portal->link = vars->first_portal;
		return (true);
	}
	free(portal);
	return (false);
}

bool	create_portal(t_vars *vars, int x, int y, t_cardinal card)
{
	t_portal	*portal;

	portal = malloc(sizeof(t_portal));
	if (!portal)
		return (false);
	portal->pos.x = x;
	portal->pos.y = y;
	portal->card = card;
	portal->link = NULL;
	play_sound(vars->sounds.portal);
	if (vars->first_portal)
		return (link_portal(vars, x, y, portal));
	vars->first_portal = portal;
	return (true);
}

t_portal	*get_portal(t_vars *vars, int x, int y, t_cardinal card)
{
	if (vars->second_portal && vars->second_portal->card == card
		&& vars->second_portal->pos.x == x && vars->second_portal->pos.y == y
		&& vars->second_portal->link != NULL)
		return (vars->second_portal);
	if (vars->first_portal && vars->first_portal->card == card
		&& vars->first_portal->pos.x == x && vars->first_portal->pos.y == y
		&& vars->first_portal->link != NULL)
		return (vars->first_portal);
	return (NULL);
}

t_portal	*get_empty_portal(t_vars *vars, int x, int y, t_cardinal card)
{
	if (vars->first_portal && vars->first_portal->card == card
		&& vars->first_portal->pos.x == x && vars->first_portal->pos.y == y
		&& vars->first_portal->link == NULL)
		return (vars->first_portal);
	return (NULL);
}
