/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:23:52 by dasalaza          #+#    #+#             */
/*   Updated: 2025/06/04 22:11:40 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	normalize_map_lines(char **map_copy, int rows, int max_columns)
{
	char	*new_line;
	int		i;
	int		len;

	i = 0;
	while (i < rows && map_copy[i] != NULL)
	{
		len = (int) ft_strlen(map_copy[i]);
		if (len <= max_columns)
		{
			new_line = malloc(sizeof(char) * (max_columns + 1));
			if (!new_line)
				return ;
			ft_memcpy(new_line, map_copy[i], len);
			ft_memset(new_line + len, '/', max_columns - len);
			new_line[max_columns] = '\0';
			free(map_copy[i]);
			map_copy[i] = new_line;
		}
		i++;
	}
}

int	validate_map_after_extract(t_parser *parser)
{
	int	i;

	if (!parser->original_map)
		return (1);
	i = 0;
	if (parser->validation_map == NULL)
	{
		parser->validation_map = malloc(sizeof(char *) * (parser->rows + 1));
		if (!parser->validation_map)
			return (1);
		while (i < parser->rows)
		{
			parser->validation_map[i] = ft_strdup(parser->original_map[i]);
			if (!parser->validation_map[i])
				return (free_matrix(parser->validation_map), 1);
			i++;
		}
		parser->validation_map[i] = NULL;
	}
	// print_map_2d(parser->validation_map);
	if (parser->validation_map)
	{
		// normalize_and_fill_map(parser);
		normalize_map_lines(parser->validation_map, parser->rows, parser->columns);
		printf("AFTER NORMIALIZE:\n");
		print_map_2d(parser->validation_map);
		if (validate_map(parser) == 1)
			return (free_matrix(parser->validation_map), parser->validation_map = NULL, 1);
	}
	return (0);
}

/**
 * @brief Executes the full parsing process of the `.cub`.
 *
 * 1. Parses texture and color definitions.
 * 2. Validates texture and color formatting.
 * 3. Extracts the map section from the file content.
 * 4. Validates the structure and correctness of the map.
 *
 * If any step in the process fails, the function exits and returns an error.
 *
 * @param parser A pointer to a `t_parser`.
 * @see parse_lines_of_textures()
 * @see check_textures_and_colors()
 * @see extract_map_from_file_map();
 *
 * @return int
 *         - 0 if the parsing and validation complete successfully.
 *         - 1 if an error occurs during any phase of the parsing process.
 */

static int check_texture_extension_xpm(char *texture_path)
{
	int	len;

	if (!texture_path)
		return (1);
	len = (int) ft_strlen(texture_path);
	if (len < 4)
		return (1);
	if (ft_strncmp(texture_path + len - 4, EXTENSION_TEXTURE, 4) != 0)
		return (1);
	return (0);
}

int	validate_extension_texture_xpm(t_parser* parser)
{
	if (check_texture_extension_xpm(parser->north) == 1)
		return (printf(ERROR_EXTENSION_NORTH_TEXTURE), 1);
	if (check_texture_extension_xpm(parser->south) == 1)
		return (printf(ERROR_EXTENSION_SOUTH_TEXTURE), 1);
	if (check_texture_extension_xpm(parser->east) == 1)
		 return (printf(ERROR_EXTENSION_EAST_TEXTURE), 1);
	if (check_texture_extension_xpm(parser->west) == 1)
		return (printf(ERROR_EXTENSION_WEST_TEXTURE), 1);
	return (0);
}

int	parsing(t_parser *parser)
{
	if (!parser || !parser->file_map)
		return (1);

	if (validate_texture_and_color(parser) != 0)
		return (1);

	if (check_total_num_textures_and_colors(parser) != 0)
		return (1);

	// comment because CLion not accept file .xpm
	// if (validate_textures_paths(parser) != 0)
	// 	return (1);

	if (validate_extension_texture_xpm(parser) != 0)
		return (1);

	extract_map_from_file_map(parser);
	//	posible error here
	print_map_2d(parser->original_map);
	//	TODO: check this function
	if (validate_type_of_characters_in_map(parser) != 0)
		return (1);

	if (validate_map_after_extract(parser) != 0)
		return (1);
	return (0);
}
