/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:23:52 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/30 01:05:29 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**duplicate_map_matrix(t_parser *parser)
{
	char	**new_matrix;
	int		len_line;
	int		i;
	int		col;

	new_matrix = malloc(sizeof(char *) * (parser->rows + 1));
	if (!new_matrix)
		return (NULL);
	i = 0;
	while (i < parser->rows)
	{
		len_line = (int) ft_strlen(parser->original_map[i]);
		new_matrix[i] = malloc(sizeof(char) * (len_line + 1));
		if (!new_matrix[i])
			return (free_matrix(new_matrix), NULL);
		col = 0;
		while (col < len_line)
		{
			new_matrix[i][col] = parser->original_map[i][col];
			col++;
		}
		new_matrix[i][col] = '\0';
		i++;
	}
	new_matrix[i] = NULL;
	return (new_matrix);
}

// fill all the positions that have spaces with spaces in the matrix.
static void	normalize_map_lines(char **map_copy, int rows, int max_columns)
{
	char	*new_line;
	int		i;
	int		len;

	i = 0;
	while (i < rows && map_copy[i])
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

void	normalize_and_fill_map(t_parser *parser)
{
	int	i;
	int	j;

	if (!parser->validation_map)
		return ;
	normalize_map_lines(parser->validation_map, parser->rows, parser->columns);
	i = 0;
	while (i < parser->rows)
	{
		j = 0;
		while (j < parser->columns)
		{
			if (parser->validation_map[i][j] == ' ')
				parser->validation_map[i][j] = '/';
			j++;
		}
		i++;
	}
}

int	validate_map_after_extract(t_parser *parser)
{
	char	**copy_map_validation;
	int		i;

	if (!parser->original_map)
		return (1);
	copy_map_validation = duplicate_map_matrix(parser);
	if (!copy_map_validation)
		return (free_matrix(copy_map_validation), 1);
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
	normalize_and_fill_map(parser);
	validate_map(parser);
	return (0);
}

int	parsing(t_parser *parser)
{
	if (!parser || !parser->file_map)
		return (1);
	parse_lines_of_textures(parser);
	if (check_textures_and_colors(parser) == 0)
	{
		extract_map_from_file_map(parser);
		validate_map_after_extract(parser);
	}
	else
		return (1);
	return (0);
}
