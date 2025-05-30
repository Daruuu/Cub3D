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

static char	**new_matrix_map(t_parser *parser, int first_line, int total_lines)
{
	char	**new_matrix;
	int		len_line;
	int		rows;
	int		col;

	new_matrix = malloc(sizeof(char *) * (total_lines + 1));
	if (!new_matrix)
		return (NULL);
	rows = 0;
	while (rows < total_lines)
	{
		len_line = (int) ft_strlen(parser->file_map[first_line + rows]);
		new_matrix[rows] = malloc(sizeof(char) * (len_line + 1));
		if (!new_matrix[rows])
			return (free_matrix(new_matrix), NULL);
		col = 0;
		while (col < len_line)
		{
			new_matrix[rows][col] = parser->file_map[first_line + rows][col];
			col++;
		}
		new_matrix[rows][col] = '\0';
		rows++;
	}
	return (new_matrix[rows] = NULL, parser->rows = rows, new_matrix);
}

void	extract_map_from_file_map(t_parser *parser)
{
	int	first_line;
	int	last_line;
	int	total_lines;

	first_line = find_first_line_map(parser);
	last_line = find_last_line_map(parser);
	if (first_line == -1 || last_line == -1 || last_line < first_line)
	{
		handle_error(ERROR_MAP_CANT_EXTRACT_FROM_FILE, \
			(int) ft_strlen(ERROR_MAP_CANT_EXTRACT_FROM_FILE), parser, NULL);
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
