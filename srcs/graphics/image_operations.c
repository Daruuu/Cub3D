/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 22:00:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image_operations.h"

void	set_pixel(t_img *data, int x, int y, int color)
{
	*(unsigned int*)(data->addr + \
		(y * data->line_length + x * data->pixel_len)) = color;
}

int	get_pixel(t_img *data, int x, int y)
{
	return (*(int *)(data->addr + (y * data->line_length + x \
		* (data->pixel_len))));
}

void	set_big_pixel(t_img *d, int x, int y, int color)
{
	int	addr;

	addr = (y * d->line_length + x * d->pixel_len);
	*(unsigned int *)(d->addr + addr) = color;
	if (x < d->width - 1 && y < d->height - 1)
		*(unsigned int *)(d->addr + addr + d->pixel_len + \
			d->line_length) = color;
	if (y < d->height - 1)
		*(unsigned int *)(d->addr + addr + d->line_length) = color;
	if (x < d->width - 1)
		*(unsigned int *)(d->addr + addr + d->pixel_len) = color;
}

t_img	make_image(void *mlx, int w, int h)
{
	t_img	img;

	img.width = w;
	img.height = h;
	img.img = mlx_new_image(mlx, w, h);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	img.pixel_len = img.bits_per_pixel / 8;
	return (img);
}

t_img	load_image(void *mlx, char *path)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(mlx, path, &(img.width), &(img.height));
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.pixel_len = img.bits_per_pixel / 8;
	return (img);
}
