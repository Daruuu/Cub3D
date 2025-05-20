# include "../includes/cub3d.h"

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

void	get_player_init_pos(t_parser *map_data)
{
	int	y;
	int	x;
	int	c;

	x = 1;
	while (x < map_data->rows)
	{
		y = 1;
		while (y < map_data->columns)
		{
			c = map_data->map[x][y];
			if (c == NORTH \
				|| c == SOUTH || c == EAST || c == WEST)
			{
				map_data->position_player.y = y;
				map_data->position_player.x = x;
				return ;
			}
			y++;
		}
		x++;
	}
}
