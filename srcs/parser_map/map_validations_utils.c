
#include "../includes/cub3d.h"

//	TODO: error with empty spaces at start of line.
void    normalize_map_lines(char **validation_map, int rows, int max_columns)
{
	char    *new_line;
	int     i;
	int		j;
	int		len;
	int		found_wall;

	i = 0;
	while (i < rows && validation_map[i] != NULL)
	{
		len = (int) ft_strlen(validation_map[i]);
		new_line = malloc(sizeof(char) * (max_columns + 1));
		if (!new_line)
			return ;

		j = 0;
		found_wall = 0;	
		while (j < max_columns)
		{
			if (j < len)
			{
				//	first row and last row, fill spaces with FILL_MAP
				if ((i == 0 || i == rows - 1) && validation_map[i][j] == ' ')
				{
					new_line[j] = FILL_MAP;
				}
				else if (!found_wall && validation_map[i][j] == ' ')
				{
					new_line[j] = FILL_MAP;
				}
				else
				{
					if (validation_map[i][j] == WALL)
					{
						found_wall = 1;
					}
					new_line[j] = validation_map[i][j];
				}
				
			}
			else
			{
				if (i == 0 || i == rows - 1)
					new_line[j] = FILL_MAP;
				else
					new_line[j] = ' ';
			}
			j++;
		}
		new_line[max_columns] = '\0';

		// Segunda pasada: desde el final hacia el inicio, reemplaza espacios finales con FILL_MAP
		// if (i > 0 && i < rows - 1)
		// {
		// 	int k = max_columns - 1;
		// 	while (k >= 0 && new_line[k] == ' ')
		// 	{
		// 		new_line[k] = FILL_MAP;
		// 		k--;
		// 	}
		// }

		free(validation_map[i]);
		validation_map[i] = new_line;
		i++;
	}
}

static int	is_valid_cell(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_outside_or_space(char c)
{
	return (c == FILL_MAP || c == ' ');
}

static int	flood_fill_check(char **map, int rows, int cols, int i, int j, char **visited)
{
	if (i < 0 || i >= rows || j < 0 || j >= cols)
		return (1); // Se salió del mapa → mapa abierto

	if (is_outside_or_space(map[i][j]))
		return (1); // Toca borde o vacío

	if (!is_valid_cell(map[i][j]))
		return (0); // Pared u otro símbolo válido

	if (visited[i][j])
		return (0); // Ya fue procesado
	visited[i][j] = 1;

	if (flood_fill_check(map, rows, cols, i + 1, j, visited))
        return (1);
	if (flood_fill_check(map, rows, cols, i - 1, j, visited))
        return (1);
	if (flood_fill_check(map, rows, cols, i, j + 1, visited))
        return (1);
	if (flood_fill_check(map, rows, cols, i, j - 1, visited))
        return (1);
	return (0);
}
// TODO: norminnete this function
int	validate_map_closed(t_parser *parser, char **validation_map)
{
	int		i, j;
	char	**visited;

	visited = malloc(sizeof(char *) * parser->rows);
	if (!visited)
		return (1);
	i = 0;
	while (i < parser->rows)
	{
		visited[i] = calloc(parser->columns, sizeof(char));
		if (!visited[i])
			return (1);
		i++;
	}

	for (i = 0; i < parser->rows; i++)
	{
		for (j = 0; j < parser->columns; j++)
		{
			if (is_valid_cell(validation_map[i][j]) && !visited[i][j])
			{
				if (flood_fill_check(validation_map, parser->rows, parser->columns, i, j, visited))
				{
					// Limpieza antes de salir
					for (int k = 0; k < parser->rows; k++)
						free(visited[k]);
					free(visited);
					return (1); // mapa abierto
				}
			}
		}
	}

	for (i = 0; i < parser->rows; i++)
		free(visited[i]);
	free(visited);
	return (0); // mapa está cerrado
}
