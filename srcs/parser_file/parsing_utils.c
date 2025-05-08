#include "../includes/cub3d.h"

int	ft_open_map(char *path)
{
	int	fd;

	if (!path)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_exit(ERROR_OPEN_FILE, 32);
	return (fd);
}

/*
int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_game(game);
	exit(0);
}*/

int	set_map_dimensions(t_parser *map_info)
{
	int	i;
	int	j;
	int	count_line;
	int	max_line;

	if (map_info->map[0] == NULL)
		return (1);
	i = 0;
	while (map_info->map[i] != NULL)
		i++;
	map_info->rows = i;
	i = 0;
	count_line = 0;
	max_line = 0;
	while (map_info->map[i] != NULL)
	{
		j = 0;
		count_line = 0;
		while (map_info->map[i][j] != '\0')
		{
			j++;
			count_line++;
		}
		if (count_line > max_line)
			max_line = count_line;
		i++;
	}
	printf("max linee: [%d]\n", max_line);
	map_info->columns = max_line;
	return (0);
}


int	check_map_dimensions(t_parser *map_info)
{
	int	i;
	int	line;

	i = 0;
	while (map_info->map[i] != NULL)
	{
		line = (int)ft_strlen(map_info->map[i]);
		if (map_info->columns != line)
			return (1);
		i++;
	}
	return (0);
}

void	print_map_2d(t_parser *map_info)
{
	int	i;

	i = 0;
	while (map_info->file_map[i] != NULL)
	{
		printf("line[%i]: [%s]\n", i, map_info->file_map[i]);
		i++;
	}
}
