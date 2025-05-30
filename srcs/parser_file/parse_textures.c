/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:18:16 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/30 14:40:27 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_textures_and_colors(t_parser *parser)
{
	if (!parser->north)
		return (printf(ERROR_INVALID_NORTH_TEXTURE), 1);
	if (!parser->south)
		return (printf(ERROR_INVALID_SOUTH_TEXTURE), 1);
	if (!parser->east)
		return (printf(ERROR_INVALID_EAST_TEXTURE), 1);
	if (!parser->west)
		return (printf(ERROR_INVALID_WEST_TEXTURE), 1);
	if (!parser->floor)
		return (printf(ERROR_INVALID_FLOOR_TEXTURE), 1);
	if (!parser->ceiling)
		return (printf(ERROR_INVALID_CEILING_TEXTURE), 1);
	return (0);
}

static void	type_of_horientation(char *trim_line, t_parser *map_info)
{
	if (!trim_line || !map_info)
		return ;
	if (ft_strncmp(trim_line, "NO", 2) == 0)
		map_info->north = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "SO", 2) == 0)
		map_info->south = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "WE", 2) == 0)
		map_info->west = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "EA", 2) == 0)
		map_info->east = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "F ", 2) == 0)
		map_info->floor = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "C ", 2) == 0)
		map_info->ceiling = ft_strdup(trim_line);
}

static void	trim_line_and_set_type(char *line, t_parser *parser)
{
	char	*trim_line;

	trim_line = ft_strtrim(line, " ");
	if (!trim_line)
		return ;
	if (ft_strlen(trim_line) > 1)
		type_of_horientation(trim_line, parser);
	free(trim_line);
}

void	parse_lines_of_textures(t_parser *parser)
{
	int		i;

	i = 0;
	if (!parser || !parser->file_map)
		return ;
	while (parser->file_map[i] != NULL)
	{
		trim_line_and_set_type(parser->file_map[i], parser);
		i++;
	}
}