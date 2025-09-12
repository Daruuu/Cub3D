/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 23:07:54 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_operations.h"

int	color_add(int color, int current, float ratio)
{
	int	r;
	int	g;
	int	b;

	r = ((current >> 16) & 0xff) + (int)(((color & 0xff0000) >> 16) * ratio);
	g = ((current & 0xff00) >> 8) + (int)(((color & 0xff00) >> 8) * ratio);
	b = (current & 0xff) + (int)((color & 0xff) * ratio);
	return (r << 16 | g << 8 | b);
}

int	color_dim(int color, float ratio)
{
	int	r;
	int	g;
	int	b;

	r = (int)(((color & 0xff0000) >> 16) * ratio);
	g = (int)(((color & 0xff00) >> 8) * ratio);
	b = (int)((color & 0xff) * ratio);
	return (r << 16 | g << 8 | b);
}

int	blend_colors(int o, int n)
{
	float	a;
	int		r;
	int		g;
	int		b;

	a = 1 - ((n >> 24) & 0xFF) / 255.0f;
	if (a == 1)
		return (n);
	r = (int)(((o & 0xff0000) >> 16) * (1 - a) + ((n & 0xff0000) >> 16) * a);
	g = (int)(((o & 0xff00) >> 8) * (1 - a) + ((n & 0xff00) >> 8) * a);
	b = (int)((o & 0xff) * (1 - a) + (n & 0xff) * a);
	return (0 << 24 | r << 16 | g << 8 | b);
}
