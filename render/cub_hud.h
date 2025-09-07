/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:27:02 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:27:02 by yamir            ###   ########.fr       */
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
