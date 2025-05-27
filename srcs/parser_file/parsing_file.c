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
	ssize_t	bytes_read;
	char	buffer;
	int		size;

	if (!path)
		return (-1);
	fd = ft_open_map(path);
	if (fd == -1)
		return (-1);
	size = 0;
	while ((bytes_read = read(fd, &buffer, 1)) > 0)
		size++;
	if (bytes_read == -1)
		return (close(fd), -1);
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
 * @param path check if path have bytes inside .cub
 * @param parser first copy of (file .cub)
 * @return
 */

int	read_file(char *path, t_parser *parser)
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
	if (!parser->file_map)
	{
		free(file_map1d);
		printf("MAP INFO NULL\n");
		return (1);
	}
	free(file_map1d);
	return (0);
}

static void	type_of_horientation(char *trim_line, t_parser *map_info)
{
	if (ft_strncmp(trim_line, "NO", 2) == 0)
		map_info->north = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "SO", 2) == 0)
		map_info->south = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "WE", 2) == 0)
		map_info->west = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "EA", 2) == 0)
		map_info->east = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "F ", 2) == 0)
		map_info->floor = ft_strdup(trim_line);
	else if (ft_strncmp(trim_line, "C ", 2) == 0)
		map_info->ceiling = ft_strdup(trim_line);
}

void	fill_parser_info(t_parser *parser)
{
	int		i;
	int		len_file_map;
	char	*trim_line;
	int		len_tmp;

	i = 0;
	if (parser->file_map == NULL)
		return ;

	len_file_map = 0;
	while (parser->file_map[len_file_map] != NULL)
		len_file_map ++;
	while (parser->file_map[i] != NULL)
	{
		trim_line = ft_strtrim(parser->file_map[i], " ");
		len_tmp = (int) ft_strlen(trim_line);
		if (len_tmp > 1)
			type_of_horientation(trim_line, parser);
		free(trim_line);
		i++;
	}
}

/*
char	*safe_read_map_file(const char *path)
{
	int		fd;
	ssize_t	bytes_read;
	char	*buffer;
	int		size;

	if (!path)
		return (NULL);
	size = count_file_size(path);
	if (size <= 0)
	{
		// fprintf(stderr, "Error: archivo vacío o ilegible.\n");
		return (NULL);
	}
	buffer = malloc(size + 1);
	if (!buffer)
		handle_exit(ERROR_MEMORY);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		handle_exit(ERROR_OPEN_FILE);
	}
	bytes_read = read(fd, buffer, size);
	close(fd);
	if (bytes_read < 0 || bytes_read < size)
	{
		free(buffer);
		// fprintf(stderr, "Error: lectura incompleta.\n");
		return (NULL);
	}
	buffer[size] = '\0';
	return buffer;
}
*/