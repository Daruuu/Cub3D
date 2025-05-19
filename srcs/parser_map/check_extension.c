#include "../includes/cub3d.h"

int	validate_path_map(char *argv)
{
	char	*file_extension;
	int		len_file_extension;
	int		len_argv;
	int		i;

	file_extension = ".cub";
	len_file_extension = (int) ft_strlen (file_extension);
	len_argv = (int) ft_strlen(argv);
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

	//get first line map in file_map
int	find_first_line_map(t_parser *map_info)
{
	int i;

	i = 0;
	while (map_info->file_map[i])
	{
		if (ft_(map_info->file_map[i][0], '1') == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	find_last_and_last_line(t_parser *map_info)
{
	int i;

	i = 0;
	while (map_info->file_map[i])
	{
		if (ft_strcmp(map_info->file_map[i][0], '1'))
			return (i);
		i++;
	}
	return (-1);
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

char	**extract_map_from_file_map(t_parser *parser)
{
	int	first_line_map;
	int	last_line_map;
	int	i;
	
	first_line_map = find_first_line_map(parser);
	last_line_map = find_last_and_last_line(parser);
	i = 0;
	while (parser->file_map[i] != NULL)
	{
		if (i == first_line_map)
		{
		}
	}




}

int	map_format_border_check(char *path, t_parser *map_info)
{
	// if (check_first_and_last_line(map_info) == 1 || check_laterals_map(map_info) == 1)
	// 	return (1);
	// if (validate_path_map(path) == 0)
	{
		// if (read_map(path, map_info) == 1)
		// 	return (1);
		// if (check_first_and_last_line(map_info) == 1 || check_laterals_map(map_info) == 1)
		// 	return (1);
	}
	return (0);
}