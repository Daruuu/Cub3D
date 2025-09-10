/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 00:47:33 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utils.h"

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

bool	check_iscub(char *file)
{
	int		len;

	len = stringlen(file);
	if (len < 4)
		return (false);
	return ((file[len - 1] == 'b' || file[len - 1] == 'B')
		&& (file[len - 2] == 'u' || file[len - 2] == 'U')
		&& (file[len - 3] == 'c' || file[len - 3] == 'C')
		&& file[len - 4] == '.');
}

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
