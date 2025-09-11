/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file_loader.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:32 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 15:28:19 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_file_loader.h"

int	load_map(t_game *game, t_line *file)
{
	t_vec	p;

	p.y = 0;
	while (file)
	{
		p.x = 0;
		while (p.x < file->size)
		{
			if (!set_map(game, file->line[p.x], p))
				handle_error(game, ERROR_FORMAT, file->line);
			p.x++;
		}
		p.y++;
		file = file->next;
	}
	if (!is_map_valid(&(game->map)))
		handle_error(game, ERROR_MAP_UNCLOSED, NULL);
	handle_door_rotation(game);
	return (0);
}

int	load_f(char *filepath, t_game *game)
{
	t_line	*file;
	t_vec	size;

	file = NULL;
	load_file(filepath, &(file), 0);
	game->file = file;
	if (!game->file)
		handle_error(game, "Could not load file.", filepath);
	while (file)
	{
		if (!file->line[0] || read_argument(game, file))
			file = file->next;
		else
			break ;
	}
	size = get_map_size(file);
	if (size.x == 0)
		handle_error(game, "Map grid is empty.", NULL);
	game->map = make_empty(size);
	if (!game->map.data)
		handle_error(game, "Failed to initialize map.", NULL);
	return (load_map(game, file));
}
