#include "../includes/cub3d.h"

static int	is_valid_texture_path(char *path)
{
	int	fd;

	if (!path)
		return (1);
	fd = open(path, O_RDONLY);
	printf("PATH : %s\n", path);
	if (fd == -1)
	{
		return (1);
	}
	close(fd);
	return (0);
}

int	check_total_num_textures_and_colors(t_parser *parser)
{
	if (!parser)
		return (1);
	if (!parser->north)
		return (printf(ERROR_MISSING_NORTH_TEXTURE), 1);
	if (!parser->south)
		return (printf(ERROR_MISSING_SOUTH_TEXTURE), 1);
	if (!parser->east)
		return (printf(ERROR_MISSING_EAST_TEXTURE), 1);
	if (!parser->west)
		return (printf(ERROR_MISSING_WEST_TEXTURE), 1);
	if (!parser->floor)
		return (printf(ERROR_MISSING_FLOOR_COLOR), 1);
	if (!parser->ceiling)
		return (printf(ERROR_MISSING_CEILING_COLOR), 1);
	return (0);
}

int	validate_textures_paths(t_parser *parser)
{
	if (!parser)
		return (1);
	if (is_valid_texture_path(parser->north) == 1)
		return (printf(ERROR_ACCESS_NORTH_PATH), 1);
	if (is_valid_texture_path(parser->south) == 1)
		return (printf(ERROR_ACCESS_SOUTH_PATH), 1);
	if (is_valid_texture_path(parser->east) == 1)
		return (printf(ERROR_ACCESS_EAST_PATH), 1);
	if (is_valid_texture_path(parser->west) == 1)
		return (printf(ERROR_ACCESS_WEST_PATH), 1);
	//add validation format of floor and ceiling
	return (0);
}