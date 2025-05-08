#include "../includes/cub3d.h"

void    printar_parser_struct(t_parser *parser)
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