/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:18:16 by dasalaza          #+#    #+#             */
/*   Updated: 2025/06/04 21:22:56 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	trimmed line: [NO                  textures/test/north.xpm]
	trimmed line: [WE textures/test/west.xpm]
	trimmed line: [EA          textures/test/east.xpm]
	trimmed line: [SO          textures/test/south.xpm]
	trimmed line: [C           0,0,0]
	trimmed line: [F 0,0,0]
*/

/*
char	*extract_path_from_line_texture(char *trimmed_line, char *type)
{
	char	*line_updated;
	int		len_line;
	int		i;
	int		len_of_type;

	len_line = (int) ft_strlen(trimmed_line);
	i = 0;
	//	NO
	if (i < len_line)
	{
		len_of_type = (int) ft_strlen(type);
		if (ft_strncmp(trimmed_line, type, ft_strlen(type)) == 0)
			i = len_of_type + 1;
	}
	//	NO[x]
	while (i < len_line)
	{
		if (trimmed_line[i] == ' ' || trimmed_line[i] == '\t')
			i++;
		if (i == len_line)
			return ("invalid texture");
	}

	line_updated = NULL;
	return (line_updated);
}
*/

static int	set_texture_field(char **field, char *trim_line,
								int *counter, const char *error_msg)
{
	char	*tmp_clean_line;

	if ((*counter)++)
		return (printf("%s", error_msg), 1);

	tmp_clean_line = ft_strrchr(trim_line, ' ');
	if (!tmp_clean_line || *(tmp_clean_line + 1) == '\0')
		return (1);
	*field = ft_strdup(tmp_clean_line + 1);
	if (!*field)
		return (printf(ERROR_MEMORY_ALLOCATION), 1);
	return (0);
}

static int	type_of_horientation(t_parser *map_info, char *trim_line,
								t_assets *counter)
{
	if (!trim_line || !map_info || !counter)
		return (1);

	if (ft_strncmp(trim_line, "NO ", 3) == 0)
		return (set_texture_field(&map_info->north, trim_line, &counter->no, \
			ERROR_DUPLICATE_NORTH_TEXTURE));
	if (ft_strncmp(trim_line, "SO ", 3) == 0)
		return (set_texture_field(&map_info->south, trim_line, &counter->so, \
			ERROR_DUPLICATE_SOUTH_TEXTURE));
	if (ft_strncmp(trim_line, "WE ", 3) == 0)
		return (set_texture_field(&map_info->west, trim_line, &counter->we, \
			ERROR_DUPLICATE_WEST_TEXTURE));
	if (ft_strncmp(trim_line, "EA ", 3) == 0)
		return (set_texture_field(&map_info->east, trim_line, &counter->ea, \
			ERROR_DUPLICATE_EAST_TEXTURE));
	if (ft_strncmp(trim_line, "F ", 2) == 0)
		return (set_texture_field(&map_info->floor, trim_line, &counter->f, \
			ERROR_DUPLICATE_FLOOR_COLOR));
	if (ft_strncmp(trim_line, "C ", 2) == 0)
		return (set_texture_field(&map_info->ceiling, trim_line, &counter->c, \
			ERROR_DUPLICATE_CEILING_COLOR));
	return (0);
}

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

static int	trim_line_and_set_type(char *line, t_parser *parser, \
		t_assets *counter)
{
	char	*trim_line;
	int		result;

	trim_line = ft_strtrim(line, " ");
	// printf("trimmed line: [%s]\n", trim_line);
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

int	validate_texture_and_color(t_parser *parser)
{
	t_assets	counter;
	int			i;

	if (!parser || !parser->file_map)
		return (1);
	ft_memset(&counter, 0, sizeof(counter));
	i = 0;
	while (parser->file_map[i] != NULL)
	{
		if (trim_line_and_set_type(parser->file_map[i], parser, &counter) == 1)
			return (1);
		i++;
	}
	return (0);
}
