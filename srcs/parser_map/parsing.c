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
	printf("parser->rows: [%i]\n", parser->rows);
	while (i < parser->rows)
	{
		len_line = (int) ft_strlen(parser->map[i]);
		printf("len line: [%d]: [%d]\n", i + 1, len_line);
		new_matrix[i] = malloc(sizeof(char) * (len_line + 1));
		if (!new_matrix[i])
		{
			free_matrix(new_matrix);
			return (NULL);
		}
		col = 0;
		while (col < len_line)
		{
			new_matrix[i][col] = parser->map[i][col];
			col++;
		}
		new_matrix[i][col] = '\0';
		i++;
	}
	new_matrix[i] = NULL;
	return (new_matrix);
}


// fill all the positions that have spaces with spaces in the matrix.
void	normalize_map_lines(char **map_copy, int rows, int max_columns)
{
	int   i = 0;
	int   len;
	char *new_line;

	while (i < rows && map_copy[i])
	{
		len = (int) ft_strlen(map_copy[i]);
		if (len <= max_columns)
		{
			new_line = malloc(sizeof(char) * (max_columns + 1));
			if (!new_line)
				return; // Manejo de error si quieres
			ft_memcpy(new_line, map_copy[i], len);               // Copia lo que había
			ft_memset(new_line + len, '/', max_columns - len);   // Rellena con '/'
			new_line[max_columns] = '\0';
			free(map_copy[i]);            // Libera la línea antigua
			map_copy[i] = new_line;       // Sustituye por la nueva
		}
		i++;
	}
}

int	validate_map_after_extract(t_parser *parser)
{
	char	**copy_map;

	if (!parser->map)
		return (1);
	copy_map = duplicate_map_matrix(parser);
	if (!copy_map)
	{
		free_matrix(copy_map);
		return (1);
	}
	normalize_map_lines(copy_map, parser->rows, parser->columns);

	print_map_2d(copy_map);
	return (0);
}

// TODO: call all the validations here about parser_file and parser_map
void    parsing(char **argv, t_parser *parser)
{
	(void) argv;
	if (!parser->file_map)
		return ;
	fill_parser_info(parser);

	// TODO: dont know how manage this function
	if (check_textures_and_colors(parser) == 0)
		printf("VALID syntax in TEXTURES | FLOOR | CEIL in map\n");
	else
		printf("INVALID syntax in TEXTURES | FLOOR | CEIL in map\n");

	extract_map_from_file_map(parser);
	if (!parser->map)
	{
		printf("Error: Fail extract map\n");
		return ;
	}
	// TODO: copy the map and validate if exists a island 
	// or empty positions inside the map
	// check how manage tabs inside de file.cub ???
	validate_map_after_extract(parser);

	printf("------------------- -----------------------\n");
	print_map_2d(parser->map);
	printf("------------------------------------------\n");

	// print_parser_struct(parser);
}
