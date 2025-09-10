/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:07:03 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HUD_H
# define CUB_HUD_H

# include "../cub3D.h"
# include "cub_minimap.h"
# include "cub_xquartz_layer.h"

void	draw_hud(t_vars *vars);
void	draw_death(t_vars *vars);
void	draw_cursor(t_vars *vars);
void	render_hand(t_vars *vars);
void	draw_skybox(t_vars *vars);

#endif
