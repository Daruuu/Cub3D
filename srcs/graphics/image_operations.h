/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 23:29:50 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_OPERATIONS_H
# define IMAGE_OPERATIONS_H

# include "../mlx/mlx.h"
# include <stdbool.h>
# include <stdlib.h>
# include "../math/vector_math.h"

typedef struct s_img
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			pixel_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_shape
{
	int			x;
	int			y;
	int			width;
	int			height;
	bool		mirror;
	double		dim;
	t_img		*img;
}				t_shape;

// Pixel operations
void			set_pixel(t_img *data, int x, int y, int color);
void			set_big_pixel(t_img *d, int x, int y, int color);
int				get_pixel(t_img *data, int x, int y);

// Image creation and loading
t_img			make_image(void *mlx, int w, int h);
t_img			load_image(void *mlx, char *path);

// Image filling
void			fill_img(t_img img, int c, int start, int stop);

#endif
