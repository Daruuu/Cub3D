/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 00:30:34 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SETTER_H
# define CUB_SETTER_H

# include "../cub3D.h"
# include "../mlx/mlx.h"

void	set_resolution(t_vars *vars, char *input);
void	set_texture(t_img *img, t_vars *vars, char *path);
void	set_color(t_vars *vars, int *val, char *input);
void	set_sound(uint32_t *s, t_vars *vars, char *path);

#endif
