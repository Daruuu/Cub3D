#include "../includes/cub3d.h"

int	check_textures_and_colors(t_parser *parser)
{
	if (!parser)
		return (1);
	if (!parser->north || !parser->south || !parser->east ||
		!parser->west || !parser->floor || !parser->ceiling)
		return (1);
	return (0);
}
