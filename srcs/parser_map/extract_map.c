# include "../includes/cub3d.h"

static int	find_first_line_map(t_parser *map_info)
{
	int i;
	int j;

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
	int i;
	int j;

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
		printf("len line: [%d]: [%d]\n", rows + 1, len_line);
		new_matrix[rows] = malloc(sizeof(char) * (len_line + 1));
		if (!new_matrix[rows])
		{
			free_matrix(new_matrix);
			return (NULL);
		}
		col = 0;
		while (col < len_line)
		{
			new_matrix[rows][col] = parser->file_map[first_line + rows][col];
			col++;
		}
		new_matrix[rows][col] = '\0';
		rows++;
	}
	new_matrix[rows] = NULL;
	parser->rows = rows;
	return (new_matrix);
}

void	extract_map_from_file_map(t_parser *parser)
{
	int	first_line;
	int	last_line;
	int	total_lines;

	first_line = find_first_line_map(parser);
	last_line = find_last_line_map(parser);
	if (first_line == -1 || last_line == -1 || last_line < first_line)
		handle_error("Error: Mapa no válido. No se pudo extraer desde file_map.\n", 30, parser, NULL);
	total_lines = last_line - first_line + 1;
	parser->map = new_matrix_map(parser, first_line, total_lines);
	parser->columns = get_max_columns(parser->map, parser->rows);
}

// MAIN FUNCTION PARSINGGGGGGGGG
//TODO: here call functions from check_extension and check_items

/*
int	check_correct_parsing_map(t_parser *parser)
{

	if (map_format_border_check(argv[1], parser) == 1)
	{
		// free_map2d(game->map);
		// free(game->map);
		// free(game);
		handle_exit(ERROR_INVALID_MAP);
	}
	else if (items_errors(game->map) == 1)
	{
		free_map2d(game->map);
		free(game->map);
		free(game);
		handle_exit(ERROR_ITEMS, 21);
	}
	else if (validation_player(&ccoins, game->map) == 1)
	{
		free_map2d(game->map);
		free(game->map);
		free(game);
		handle_exit(ERROR_ITEMS, 21);
	}
	return (0);

}
*/