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

/*if (!parser)
	return (1);
if (!parser->north)
	return (ERROR_INVALID_NORTH_TEXTURE, 1);
if (!parser->south)
	return (ERROR_INVALID_SOUTH_TEXTURE, 1);
if (!parser->east)
	return (ERROR_INVALID_EAST_TEXTURE, 1);
if (!parser->west)
	return (ERROR_INVALID_WEST_TEXTURE, 1);
if (!parser->floor)
	return (ERROR_INVALID_FLOOR_TEXTURE, 1);
if (!parser->ceiling)
	return (ERROR_INVALID_CEILING_TEXTURE, 1);
return (0);*/