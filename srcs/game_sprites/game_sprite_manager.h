/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sprite_manager.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 16:17:51 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SPRITE_MANAGER_H
# define GAME_SPRITE_MANAGER_H

# include "../cub3D.h"

void		swap_sprite(t_sprite **prevnext, t_sprite *last);
void		sprite_sort(t_vars *vars, t_sprite **begin_list);
t_sprite	*make_sprite(t_vecd pos, t_sprite_k kind, t_img *img);
t_sprite	*sprite_pf(t_sprite **begin_list, t_vecd pos,
				t_sprite_k kind, t_img *img);
void		empty_sprites(t_sprite **begin_list);

#endif
