/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:23:09 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:23:09 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SETTER_H
# define CUB_SETTER_H

# include "../cub3D.h"
# include "../utils/cub_error.h"

void	set_resolution(t_vars *vars, char *input);
void	set_texture(t_img *img, t_vars *vars, char *path);
void	set_color(t_vars *vars, int *val, char *input);
void	set_sound(uint32_t *s, t_vars *vars, char *path);

#endif
