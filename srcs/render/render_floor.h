/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:13:44 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:57:53 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_FLOOR_H
# define RENDER_FLOOR_H

# include "../cub3D.h"

void	setup_floor(t_vars *vars, t_floor_render *f);
void	draw_floor(t_vars *vars);
void	render_row_floor(t_vars *vars, t_floor_render *f);

#endif
