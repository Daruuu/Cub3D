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

static int	type_of_horientation(t_parser *map_info, char *trim_line,
								t_assets_counter *counter)
{
	if (!trim_line || !map_info || !counter)
		return (1);
	if (ft_strncmp(trim_line, "NO", 2) == 0)
	{
		if (counter->no++)
			return (printf("Error: Duplicate NO texture\n"), 1);
		map_info->north = ft_strdup(trim_line);
	}
	else if (ft_strncmp(trim_line, "SO", 2) == 0)
	{
		if (counter->so++)
			return (printf("Error: Duplicate SO texture\n"), 1);
		map_info->south = ft_strdup(trim_line);
	}
	else if (ft_strncmp(trim_line, "WE", 2) == 0)
	{
		if (counter->we++)
			return (printf("Error: Duplicate WE texture\n"), 1);
		map_info->west = ft_strdup(trim_line);
	}
	else if (ft_strncmp(trim_line, "EA", 2) == 0)
	{
		if (counter->ea++)
			return (printf("Error: Duplicate EA texture\n"), 1);
		map_info->east = ft_strdup(trim_line);
	}
	else if (ft_strncmp(trim_line, "F ", 2) == 0)
	{
		if (counter->f++)
			return (printf("Error: Duplicate Floor color\n"), 1);
		map_info->floor = ft_strdup(trim_line);
	}
	else if (ft_strncmp(trim_line, "C ", 2) == 0)
	{
		if (counter->c++)
			return (printf("Error: Duplicate Ceiling color\n"), 1);
		map_info->ceiling = ft_strdup(trim_line);
	}
	return (0);
}

/*
static void	type_of_horientation(t_parser *map_info, char *trim_line)
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
*/

/**
 * @brief Trims the line and processes its texture or orientation type.
 *
 * This function removes leading and trailing spaces from a given line
 * and determines its type (NO, SO, WE, EA, F, C)
 *
 * @param line A raw line from the map file to be processed.
 * @param parser Pointer to the parser structure where parsed data is stored.
 * @param counter
 *
 * @see ft_strtrim()
 * @see type_of_horientation()
 */
static int trim_line_and_set_type(char* line, t_parser* parser,
								t_assets_counter* counter)
{
	char	*trim_line;
	int		result;

	trim_line = ft_strtrim(line, " ");
	if (!trim_line)
		return (1);
	result = 0;
	if (ft_strlen(trim_line) > 1)
		result = type_of_horientation(parser, trim_line, counter);
	free(trim_line);
	return (result);
}

/**
 * @brief Iterates over all file lines and parses texture.
 *
 * This function loops through each line of the map file stored in `parser->file_map`,
 * trimming and processing each line to extract texture paths and orientation settings.
 *
 * @param parser Pointer to the t_parser structure containing the map file lines.
 *
 * @see trim_line_and_set_type():
 * - It relies on `trim_line_and_set_type` to sanitize and categorize the input lines.
 */
int validate_texture_and_color(t_parser* parser)
{
	int	i;
	t_assets_counter	counter;

	if (!parser || !parser->file_map)
		return (1);
	ft_memset(&counter, 0, sizeof(counter));
	i = 0;
	while (parser->file_map[i] != NULL)
	{
		if (trim_line_and_set_type(parser->file_map[i], parser, &counter))
			return (1);
		i++;
	}
	return (0);
}