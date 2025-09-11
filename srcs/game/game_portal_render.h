/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:38:28 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:55:56 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORTAL_LIST_H
# define PORTAL_LIST_H

# include "../cub3D.h"
# include "game_directions.h"
# include <stdlib.h>

t_portal_render	*make_portal_render(t_shape line, float offset);
void			portal_render_pf(t_portal_render **begin_list, t_shape line,
					float offset);
void			portal_foreach_free(t_portal_render *begin_list,
					void (*f)(t_shape, float, t_vars*), t_vars *vars);

#endif
