/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_blur.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 18:41:37 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BLUR_H
# define RENDER_BLUR_H

# include "../utils/cub_utils.h"

typedef struct s_blur
{
	void		*mlx;
	t_img		src;
	t_img		temp;
	t_img		dest;
	t_shape		shape;
	int			opt;
	int			x;
	int			y;
	int			i;
	double		kernel[21];
	int			kernel_size;
}				t_blur;

t_blur			make_blur_struct(void *mlx, t_img orig, t_shape shape);
t_img			make_blur_opt(t_blur blur, bool yb);

#endif
