#include "../includes/cub3d.h"

static int	validate_path(char *argv)
{
	char	*file_extension;
	int		len_file_extension;
	int		len_argv;
	int		i;

	file_extension = ".cub";
	len_file_extension = ft_strlen (file_extension);
	len_argv = ft_strlen(argv);
	i = len_file_extension;
	while (i >= 0)
	{
		if (argv[len_argv] != file_extension[i])
			return (1);
		i--;
		len_argv--;
	}
	return (0);
}

static int	check_first_and_last_line(t_parser *map_info)
{
	int	j;

	j = 0;
	while (map_info->map[0][j] != '\0')
	{
		if (map_info->map[0][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (map_info->map[map_info->rows - 1][j] != '\0')
	{
		if (map_info->map[map_info->rows - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

static int	check_laterals_map(t_parser *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->rows)
	{
		if (map_info->map[i][0] != '1' \
			|| map_info->map[i][map_info->columns - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < map_info->rows)
	{
		if (map_info->map[i][map_info->columns - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/************************VALIDATION MAIN **************************/
//	TODO: change name: validation_map_format()
int	map_format_border_check(char *path, t_parser *map_info)
{
	if (validate_path(path) == 0)
	{
		// if (read_map(path, map_info) == 1)
		// 	return (1);
		if (check_first_and_last_line(map_info) == 1 || check_laterals_map(map_info) == 1)
			return (1);
	}
	return (0);
}