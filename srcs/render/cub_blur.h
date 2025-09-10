/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_blur.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/10 15:10:03 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BLUR_H
# define CUB_BLUR_H

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
