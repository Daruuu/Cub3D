/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 00:44:33 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CLEANER_H
# define CUB_CLEANER_H

# include "../cub3D.h"
# include "../sprites/cub_sprites.h"
# include "cub_line_reader.h"

void	destroy_img(t_vars *vars, t_img *img);
void	clean_images(t_vars *vars);
void	clean_all(t_vars *vars);
void	clean_and_exit(int code, t_vars *vars);
int		clean_and_exit_z(t_vars *vars);
int		mlx_destroy_display(void *mlx_ptr);

#endif
