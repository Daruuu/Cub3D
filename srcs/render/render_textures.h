/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:13:44 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:10:32 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TEXTURES_H
# define RENDER_TEXTURES_H

# include "../cub3D.h"
# include "../utils/cub_cleaner.h"

t_img	make_skybox(t_game *game, t_img *img, char *path);
t_img	make_gun(t_game *game, t_img *img, char *path);
t_img	make_dash(t_game *game, t_img *img, char *path);

#endif
