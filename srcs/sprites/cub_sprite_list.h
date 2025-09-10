/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:14:27 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITE_LIST_H
# define CUB_SPRITE_LIST_H

# include "../cub3D.h"

void		swap_sprite(t_sprite **prevnext, t_sprite *last);
void		sprite_sort(t_vars *vars, t_sprite **begin_list);
t_sprite	*make_sprite(t_vecd pos, t_sprite_k kind, t_img *img);
t_sprite	*sprite_pf(t_sprite **begin_list, t_vecd pos,
				t_sprite_k kind, t_img *img);
void		empty_sprites(t_sprite **begin_list);

#endif
