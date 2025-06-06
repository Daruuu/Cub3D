/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:16:15 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/30 14:34:20 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	char	*allocate_map1d(size_t size)
{
	char	*map1d;

	map1d = NULL;
	if (size > 1)
		map1d = (char *) malloc(size + 1);
	if (!map1d)
		handle_exit(ERROR_MEMORY_ALLOCATION);
	return (map1d);
}

int	count_file_size(char *path)
{
	int		fd;
	char	buffer;
	int		size;

	if (!path)
		return (-1);
	fd = ft_open_map(path);
	if (fd == -1)
		return (-1);
	size = 0;
	while (read(fd, &buffer, 1) > 0)
		size++;
	close(fd);
	return (size);
}

char	*read_file_content(char *path, int size)
{
	int		fd;
	char	*map1d;
	ssize_t	bytes_read;

	if (size <= 0)
		return (NULL);
	map1d = allocate_map1d(size);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(map1d);
		handle_exit(ERROR_OPEN_FILE_MAP);
	}
	bytes_read = read(fd, map1d, size);
	if (bytes_read < 0)
	{
		free(map1d);
		close(fd);
		handle_exit(ERROR_OPEN_FILE_MAP);
	}
	map1d[size] = '\0';
	close(fd);
	return (map1d);
}

/**
 *
 * @param parser first copy of (file .cub)
 * @param path check if path have bytes inside .cub
 * @return
 */

int	read_file(t_parser *parser, char *path)
{
	char	*file_map1d;
	int		file_size;

	file_size = count_file_size(path);
	if (file_size <= 0)
		return (1);
	printf("FILE SIZE: [%i]\n", file_size);
	file_map1d = read_file_content(path, file_size);
	if (!file_map1d)
		return (free(file_map1d), 1);
	parser->file_map = ft_split(file_map1d, '\n');

	// print_map_2d(parser->file_map);

	if (!parser->file_map)
	{
		free(file_map1d);
		printf("MAP INFO NULL\n");
		return (1);
	}
	free(file_map1d);
	return (0);
}
