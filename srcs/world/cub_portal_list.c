/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpujades <cpujades@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:35:15 by yamir             #+#    #+#             */
/*   Updated: 2025/06/01 00:35:40 by cpujades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_portal_list.h"

t_portal_render	*make_portal_render(t_shape line, float offset)
{
	t_portal_render	*elem;

	elem = malloc(sizeof(t_portal_render));
	if (!elem)
		return (NULL);
	elem->line = line;
	elem->offset = offset;
	elem->next = NULL;
	return (elem);
}

void	portal_render_pf(t_portal_render **begin_list, t_shape line,
					float offset)
{
	t_portal_render	*first;

	first = make_portal_render(line, offset);
	if (!first)
		return ;
	first->next = *begin_list;
	*begin_list = first;
}

void	portal_foreach_free(t_portal_render *begin_list,
					void (*f)(t_shape, float, t_vars*), t_vars *vars)
{
	t_portal_render	*last;
	t_portal_render	*next;

	last = begin_list;
	while (last)
	{
		f(last->line, last->offset, vars);
		next = last->next;
		free(last);
		last = next;
	}
}
