/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:28:12 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 09:28:12 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_TEXTURE_H
# define CUB_TEXTURE_H

# include "../cub3D.h"
# include "../utils/cub_cleaner.h"

t_img	make_skybox(t_vars *vars, t_img *img, char *path);
t_img	make_gun(t_vars *vars, t_img *img, char *path);
t_img	make_dash(t_vars *vars, t_img *img, char *path);

#endif
