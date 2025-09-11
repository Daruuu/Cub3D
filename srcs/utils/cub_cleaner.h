/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 16:19:57 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CLEANER_H
# define CUB_CLEANER_H

# include "../cub3D.h"
# include "../game_sprites/game_sprite_renderer.h"
# include "cub_line_reader.h"

void	destroy_img(t_game *game, t_img *img);
void	clean_images(t_game *game);
void	clean_all(t_game *game);
void	clean_and_exit(int code, t_game *game);
int		clean_and_exit_z(t_game *game);
int		mlx_destroy_display(void *mlx_ptr);

#endif
