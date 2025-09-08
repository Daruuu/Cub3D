/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:22:02 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 19:29:42 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

int	load_map(t_vars *vars, t_line *file)
{
	t_vec	p;

	p.y = 0;
	while (file)
	{
		p.x = 0;
		while (p.x < file->size)
		{
			if (!set_map(vars, file->line[p.x], p))
				handle_error(vars, "Cub is unproperly formated.", file->line);
			p.x++;
		}
		p.y++;
		file = file->next;
	}
	if (!is_map_valid(&(vars->map)))
		handle_error(vars, "Map is not enclosed.", NULL);
	handle_door_rotation(vars);
	return (0);
}

int	load_f(char *filepath, t_vars *vars)
{
	t_line	*file;
	t_vec	size;

	file = NULL;
	load_file(filepath, &(file), 0);
	vars->file = file;
	if (!vars->file)
		handle_error(vars, "Could not load file.", filepath);
	while (file)
	{
		if (!file->line[0] || read_argument(vars, file))
			file = file->next;
		else
			break ;
	}
	size = get_map_size(file);
	if (size.x == 0)
		handle_error(vars, "Map grid is empty.", NULL);
	vars->map = make_empty(size);
	if (!vars->map.data)
		handle_error(vars, "Failed to initialize map.", NULL);
	return (load_map(vars, file));
}
