#include "../includes/cub3d.h"

void    print_parser_struct(t_parser *parser)
{
    if (parser != NULL)
    {
        printf("NORTH: [%s]\n", parser->north);
        printf("SOUTH: [%s]\n", parser->south);
        printf("WEST: [%s]\n", parser->west);
        printf("EAST: [%s]\n", parser->east);
        printf("FLOOR: [%s]\n", parser->floor);
        printf("CEILING: [%s]\n", parser->ceiling);
    }
    else
        printf("parser is NULL\n");
}

void	print_map_2d(char** matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		printf("line[%i]: [%s]\n", i, matrix[i]);
		i++;
	}
	// free_parser_map(matrix);
	free_matrix(matrix);
}
