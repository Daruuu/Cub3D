/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_engine.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:12:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 14:49:02 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_ENGINE_H
# define RAYCAST_ENGINE_H

# include "../cub3D.h"
# include "../game/game_directions.h"
# include "../game/game_portal.h"
# include "../utils/cub_vec.h"

void			ray(t_game *game, t_img *img);
t_vec			get_collide_pos(t_trace trace);
t_mouseover		get_mouseover(t_game *game);
int				check_colide(t_game *game, t_vec pos);
void			render_portal(t_shape line, float offset, t_game *game);
t_ray			get_init_ray(t_rot *rot, double x, double y);
void			cast_forward(t_ray *ray, t_ray step);
t_img			*get_texture(t_game *game, t_cardinal card);

#endif
