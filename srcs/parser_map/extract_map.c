/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:22:14 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/30 15:47:03 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	find_first_line_map(t_parser *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (map_info->file_map[i])
	{
		j = 0;
		while (map_info->file_map[i][j] == ' ')
			j++;
		if (map_info->file_map[i][j] == '1')
			return (i);
		i++;
	}
	return (-1);
}

static int	find_last_line_map(t_parser *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (map_info->file_map[i])
		i++;
	i--;
	while (i >= 0)
	{
		j = 0;
		while (map_info->file_map[i][j] == ' ')
			j++;
		if (map_info->file_map[i][0] == '1')
			return (i);
		i--;
	}
	return (-1);
}

int	cp_trim_line_to_matrix(char **matrix, char *trimmed_line, int row)
{
	int	len_line;
	int	i;

	len_line = (int) ft_strlen(trimmed_line);
	matrix[row] = malloc(sizeof(char) * (len_line + 1));
	if (!matrix[row])
		return (0);
	i = 0;
	while (i < len_line)
	{
		matrix[row][i] = trimmed_line[i];
		i++;
	}
	matrix[row][i] = '\0';
	return (1);
}

static char	**new_matrix_map(t_parser *parser, int first_line, int total_lines)
{
	char	**new_matrix;
	char	*trim_line;
	int		rows;

	new_matrix = malloc(sizeof(char *) * (total_lines + 1));
	if (!new_matrix)
		return (NULL);
	rows = 0;
	while (rows < total_lines)
	{
		trim_line = ft_strtrim(parser->file_map[first_line + rows], " ");
		if (!trim_line || !cp_trim_line_to_matrix(new_matrix, trim_line, rows))
		{
			free(trim_line);
			free_matrix(new_matrix);
			return (NULL);
		}
		free(trim_line);
		rows++;
	}
	new_matrix[rows] = NULL;
	parser->rows = rows;
	return (new_matrix);
}

/**
 * @brief Extracts the map portion from the complete file contents.
 *
 * This function locates the starting and ending lines of the map
 * within the file, validates their order, and stores the extracted
 * portion in `parser->original_map`.
 * It also calculates the number of columns based on the widest line.
 *
 * If the map cannot be found or memory allocation fails, it triggers
 * a handled error exit.
 *
 * @param parser Pointer to the parser structure containing the file content.
 *
 * @see find_first_line_map()
 * @see find_last_line_map()
 * @see new_matrix_map()
 * @see get_max_columns()
 * @see handle_error()
 */
void	extract_map_from_file_map(t_parser *parser)
{
	int	first_line;
	int	last_line;
	int	total_lines;

	first_line = find_first_line_map(parser);
	last_line = find_last_line_map(parser);
	if (first_line == -1 || last_line == -1 || last_line < first_line)
	{
		handle_error(ERR_INVALID_MAP_EXTRACT, \
			(int) ft_strlen(ERR_INVALID_MAP_EXTRACT), parser, NULL);
	}
	total_lines = last_line - first_line + 1;
	parser->original_map = new_matrix_map(parser, first_line, total_lines);
	if (!parser->original_map)
	{
		handle_error(ERROR_MAP_ALLOC_FAILED, \
			(int) ft_strlen(ERROR_MAP_ALLOC_FAILED), parser, NULL);
	}
	parser->columns = get_max_columns(parser->original_map, parser->rows);
}
