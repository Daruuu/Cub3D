/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:43:24 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 15:33:42 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_setter.h"
#include "../utils/cub_error.h"

void	set_resolution(t_vars *vars, char *input)
{
	int		i;
	t_vec	size;

	if (vars->resx != 0 || vars->resy != 0)
		handle_error(vars, "Duplicate resolution paramater.", NULL);
	i = 0;
	while (input[i] >= '0' && input[i] <= '9')
		vars->resx = vars->resx * 10 + (input[i++] - '0');
	while (input[i] == ' ')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		vars->resy = vars->resy * 10 + (input[i++] - '0');
	if (input[i] || (vars->resx <= 0 || vars->resy <= 0))
		handle_error(vars, "Error parsing resolution.", input);
	if (!vars->bmp)
	{
		mlx_get_screen_size(vars->mlx, &size.x, &size.y);
		vars->resx = fmin(vars->resx, size.x);
		vars->resy = fmin(vars->resy, size.y);
	}
}

void	set_texture(t_img *img, t_vars *vars, char *path)
{
	if (img->img)
		handle_error(vars, "Duplicate texture paramater.", path);
	*img = load_image(vars->mlx, path);
	if (!img->img)
		handle_error(vars, "Failed to load texture.", path);
}

int	atoirgb(char **start, bool skip)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (**start >= '0' && **start <= '9')
	{
		res = res * 10 + (**start - '0');
		(*start)++;
		i++;
	}
	if (i > 3 || i == 0 || res > 255 || res < 0)
		return (-1);
	if (skip && **start == ',')
		(*start)++;
	else if (skip)
		return (-1);
	if (!skip && **start)
		return (-1);
	while (**start == ' ')
		(*start)++;
	return (res);
}

void	set_color(t_vars *vars, int *val, char *input)
{
	int		r;
	int		g;
	int		b;
	char	*backup;

	backup = input;
	if ((unsigned int)*val != 0xDB000000)
		handle_error(vars, "Color was set twice.", backup);
	r = atoirgb(&input, true);
	if (r == -1)
		handle_error(vars, "Error reading color.", backup);
	g = atoirgb(&input, true);
	if (g == -1)
		handle_error(vars, "Error reading color.", backup);
	b = atoirgb(&input, false);
	if (b == -1)
		handle_error(vars, "Error reading color.", backup);
	*val = (r << 16) | (g << 8) | b;
}

void	set_sound(uint32_t *s, t_vars *vars, char *path)
{
	if (!load_sound(s, path))
		handle_error(vars, "Could not read audio...", path);
}
