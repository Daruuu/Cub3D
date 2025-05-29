/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension_and_player.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:20:38 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/28 19:21:26 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	validate_extension_map(char *argv)
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

static int	has_invalid_chars(char *filename)
{
	while (*filename)
	{
		if (*filename == '*' || *filename == '?' || *filename == ':' \
			|| *filename == '<' || *filename == '>' || *filename == '|')
			return (1);
		filename++;
	}
	return (0);
}

int	validate_map_filename(char *filename)
{
	int	len_file_map;

	len_file_map = (int) ft_strlen(filename);
	if (len_file_map <= 4)
	{
		printf(INVALID_LEN_FILE_MAP);
		return (1);
	}
	if (validate_extension_map(filename) != 0)
	{
		printf(INVALID_MAP_EXTENSION);
		return (1);
	}
	if (has_invalid_chars(filename) != 0)
	{
		printf(ERROR_INVALID_FILENAME_CHARS);
		return (1);
	}
	if (open(filename, O_RDONLY) < 0)
	{
		printf(ERROR_OPEN_FILE_MAP);
		return (1);
	}
	if (count_file_size(filename) <= 0)
	{
		printf(ERROR_EMPTY_FILE_MAP);
		return (1);
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
			c = map_data->original_map[x][y];
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
