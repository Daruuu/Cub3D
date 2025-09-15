/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_memory_cleanup.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:18:55 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 00:30:48 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_MEMORY_CLEANUP_H
# define PARSER_MEMORY_CLEANUP_H

# include "../cub3D.h"

void	destroy_img(t_game *game, t_img *img);
void	clean_images(t_game *game);
void	clean_all(t_game *game);
void	clean_and_exit(int code, t_game *game);
int		clean_and_exit_z(t_game *game);
int		mlx_destroy_display(void *mlx_ptr);

#endif
