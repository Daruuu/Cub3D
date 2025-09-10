/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_xquartz_layer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/10 16:08:27 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_xquartz_layer.h"

#include "../mlx/mlx.h"

int	put_alpha_window(t_vars *vars, t_img *img, int x, int y)
{
	int		b;
	int		color;
	t_vec	p;

	if (!LINUX)
		return (mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y));
	y++;
	p.y = fmax(0, -y);
	while (p.y < img->height && y + p.y <= vars->resy)
	{
		p.x = fmax(0, -x) - 1;
		while (++p.x < img->width && x + p.x < vars->resx)
		{
			color = get_pixel(img, p.x, p.y);
			if ((color & 0xFF000000) == 0xFF000000)
				continue ;
			b = get_pixel(&vars->img, x + p.x, y + p.y);
			set_pixel(&vars->img, x + p.x, y + p.y, blend_colors(b, color));
		}
		p.y++;
	}
	return (0);
}
