/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 21:52:04 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_HUD_H
# define RENDER_HUD_H

# include "../cub3D.h"
# include "render_minimap.h"
# include "render_macos_layer.h"

void	draw_hud(t_game *game);
void	draw_death(t_game *game);
void	draw_cursor(t_game *game);
void	render_hand(t_game *game);
void	draw_skybox(t_game *game);

#endif
