/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_directions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:35:53 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DIRECTIONS_H
# define GAME_DIRECTIONS_H

# include "../render/raycast_engine.h"

t_cardinal	get_cardinal(t_trace trace);
t_cardinal	get_opposite(t_cardinal card);
t_vec		get_direction(t_cardinal card);

#endif
