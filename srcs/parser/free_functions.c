#include "../includes/cub3d.h"

void    free_map(t_parser *map_info)
{
	int	i;

	if (map_info != NULL)
	{
		if (map_info->map != NULL)
		{
			i = 0;
			while (i < map_info->rows && map_info->map[i] != NULL)
			{
				free(map_info->map[i]);
				i++;
			}
			free(map_info->map);
		}
	}
    map_info->map = NULL;
}

void    free_parser_struct(t_parser *parser)
{
	if (parser != NULL)
	{
		if (parser->map != NULL)
			free_map2d(parser->map);
		free(parser);
	}
    if (parser->north != NULL)
        free(parser->north);
    if (parser->south != NULL)
        free(parser->south);
    if (parser->west != NULL)
        free(parser->west);
    if (parser->east != NULL)
        free(parser->east);
    if (parser->floor != NULL)
        free(parser->floor);
    if (parser->ceiling != NULL)
        free(parser->ceiling);
}