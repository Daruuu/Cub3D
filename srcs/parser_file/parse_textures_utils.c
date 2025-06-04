#include "../includes/cub3d.h"

static int	is_valid_texture_path(char *path)
{
	int	fd;

	if (!path)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

static int	count_splits(char **splits)
{
	int	i;

	if (!splits)
		return (0);	//posble error
	i = 0;
	while (splits[i])
		i++;
	return (i);
}

void	free_splitss(char **splits)
{
	int	i;

	if (!splits)
		return ;
	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

int	is_valid_rgb_format(char *value)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (!value)
		return (1);
	rgb = ft_split(value, ',');
	if (!rgb || count_splits(rgb) != 3)
	{
		free_splitss(rgb);
		return (1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_splitss(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
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
	//	add validation format of floor and ceiling
	if (is_valid_rgb_format(parser->floor) == 1)
		return (printf(ERROR_INVALID_FLOOR_FORMAT), 1);
	if (is_valid_rgb_format(parser->ceiling) == 1)
		return (printf(ERROR_INVALID_CEILING_FORMAT), 1);
	
	return (0);
}