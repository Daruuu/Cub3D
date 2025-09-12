/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_primitives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 22:00:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering_primitives.h"

void	set_strip(t_img *data, t_shape shape, int color)
{
	char	*dst;
	int		i;
	int		len;
	int		y;

	if (shape.x < 0)
		return ;
	y = shape.y;
	if (shape.y < 0)
		y = 0;
	i = 0;
	dst = data->addr + ((y - 1)
			* data->line_length + shape.x * (data->pixel_len));
	len = fmin(shape.height, data->height - y);
	while (i++ < len)
	{
		dst += data->line_length;
		*(unsigned int *)dst = color;
	}
}

void	set_img_strip(t_img *data, t_shape shape, float offset)
{
	t_vec		v;
	int			t;
	double		o;
	double		cur;
	char		*dst;

	if (shape.x < 0)
		return ;
	v.y = fmax(0, shape.y);
	v.x = (shape.img->width - 1) * offset;
	o = shape.img->height / (double)shape.height;
	cur = o * (v.y - shape.y);
	dst = data->addr + (v.y * data->line_length
			+ shape.x * (data->pixel_len));
	while (v.y < shape.y + shape.height && v.y < data->height)
	{
		t = get_pixel(shape.img, v.x, (int)cur);
		if (shape.dim < 0.98)
			t = color_dim(t, shape.dim);
		*(unsigned int *)dst = t;
		dst += data->line_length;
		cur += o;
		++v.y;
	}
}

void	set_portal_strip(t_img *d, t_shape shape, t_img *tex, float offset)
{
	t_vec		v;
	int			t;
	double		o;
	double		cur;
	char		*dst;

	v.y = fmax(0, shape.y);
	v.x = (shape.img->width - 1) * offset;
	o = shape.img->height / (double)shape.height;
	cur = o * (v.y - shape.y);
	dst = d->addr + ((v.y - 1) * d->line_length + shape.x * (d->pixel_len));
	while (++v.y <= shape.y + shape.height && v.y < d->height)
	{
		t = get_pixel(tex, v.x, cur);
		dst += d->line_length;
		cur += o;
		if (t == 0)
			continue ;
		if (t == 0x00FFFFFF)
			t = get_pixel(shape.img, v.x, cur - o);
		if (shape.dim < 0.98)
			t = color_dim(t, shape.dim);
		*(unsigned int *)dst = t;
	}
}

void	e_portal_strip(t_img *data, t_shape shape, t_img *tex, float offset)
{
	int		y;
	int		x;
	int		t;
	int		o;

	if (shape.x < 0)
		return ;
	y = fmax(0, shape.y);
	x = (tex->width - 1) * offset;
	if (shape.dim <= 0.01)
		return ;
	while (y < shape.y + shape.height && y < data->height)
	{
		o = (int)((y - shape.y) / (double)shape.height * tex->height);
		t = get_pixel(tex, x, o);
		y++;
		if (t == 0x00FFFFFF)
			t = get_pixel(shape.img, x, o);
		if (shape.dim < 0.98)
			t = color_dim(t, shape.dim);
		set_pixel(data, shape.x, y - 1, t);
	}
}

void	rect(t_img *data, t_shape shape, int color)
{
	int	i;
	int	j;
	int	b;

	i = fmax(shape.x, 0);
	while (i < shape.x + shape.width && i < data->width)
	{
		j = fmax(shape.y, 0);
		while (j < shape.y + shape.height && j < data->height)
		{
			b = get_pixel(data, i, j);
			set_pixel(data, i, j, blend_colors(b, color));
			++j;
		}
		++i;
	}
}
