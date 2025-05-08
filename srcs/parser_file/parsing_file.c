#include "../includes/cub3d.h"

static	char	*allocate_map1d(size_t size)
{
	char	*map1d;

	map1d = (char *) malloc(size + 1);
	if (!map1d)
		handle_exit(ERROR_MEMORY, 35);
	return (map1d);
}

static	int	count_file_size(char *path)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer;
	int		size;

	size = 0;
	fd = ft_open_map(path);
	bytes_read = read(fd, &buffer, 1);
	if (bytes_read == 0)
	{
		close(fd);
		return (1);
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &buffer, 1);
		size++;
	}
	close(fd);
	return (size);
}

static	char	*read_file_content(char *path, int size)
{
	int		fd;
	char	*map1d;
	ssize_t	bytes_read;

	map1d = allocate_map1d(size);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(map1d);
		handle_exit(ERROR_OPEN_FILE, 32);
	}
	bytes_read = read(fd, map1d, size);
	if (bytes_read < 0)
	{
		free(map1d);
		close(fd);
		handle_exit(ERROR_OPEN_FILE, 32);
	}
	map1d[size] = '\0';
	close(fd);
	return (map1d);
}

// PASO 2
int	read_map(char *path, t_parser *map_info)
{
	int		file_size;
	char	*map1d;

	file_size = count_file_size(path);
	printf("file size: [%i]\n", file_size);

	if (file_size <= 2)
		return (1);

	map1d = read_file_content(path, file_size);
	if (!map1d)
		return (1);
	map_info->map = ft_split(map1d, '\n');
	int	i = 0;
	while (map_info->map[i] != NULL)
	{
		printf("line: [%s]\n", map_info->map[i]);
		i++;
	}
	free(map1d);
	if (map_info->map == NULL)
		handle_exit(ERROR_MEMORY, 35);
	//
	if (set_map_dimensions(map_info) == 1 || check_map_dimensions(map_info) == 1)
		return (1);
	return (0);
}

// PASO 1
int	read_file(char *path, t_parser *map_info)
{
	int		file_size;
	char	*file_map1d;

	file_size = count_file_size(path);
	printf("FILE SIZE: [%i]\n", file_size);
	if (file_size <= 2)
		return (1);

	file_map1d = read_file_content(path, file_size);
	if (!file_map1d)
		return (1);

	map_info->file_map = ft_split(file_map1d, '\n');
	printf("************* BEFORE TRIM ****************\n");
	print_map_2d(map_info);
	printf("******************************************\n");

	free(file_map1d);

	if (map_info->file_map == NULL)
	{
		printf("MAP INFO NULL\n");
		return (1);
	}
	// handle_exit(ERROR_MEMORY, 35);
	return (0);
}

//	PASO 2
/**
 * TODO: finish this function
 * function to fill N, S, E, W, rows, columns, rgb_floor, rgb_ceil
 * use trim for each line
 */
/*
void	fill_parser_info(t_parser *parser)
{
	int		i;
	int		len_file_map;
	char	*trim_line;
	// char	**new_file_map;

	i = 0;

	len_file_map = ft_strlen(parser->file_map[1]);
	printf("----------len file map-----------: [%d]", len_file_map);

	printf("------------- AFTER TRIM --------------\n");
	if (parser->file_map != NULL)
	{
		trim_line = NULL;
		while (parser->file_map[i] != NULL)
		{
			trim_line = ft_strtrim(parser->file_map[i], " ");
			printf("line [%i]: [%s]\n", i, trim_line);
			i++;
		}
		free(trim_line);
	}
	else
		return ;
}
*/

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
	return ;
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
		len_file_map++;

	printf("---------- len file map -----------: [%d]\n", len_file_map);
	printf("------------- AFTER TRIM --------------\n");

	while (parser->file_map[i] != NULL)
	{
		trim_line = ft_strtrim(parser->file_map[i], " ");
		printf("line [%i]: [%s]\n", i, trim_line);
		len_tmp = ft_strlen(trim_line);
		if (len_tmp > 1)
		{
			type_of_horientation(trim_line, parser);
		}
		free(trim_line);
		i++;
	}
}

/*
char	*find_type_horientation(char *trim_line)
{
	char	*new_str;
	int		len_line;
	int		i;

	len_line = ft_strlen(trim_line);
	new_str = malloc(sizeof(char *) * len_line + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len_line)
	{
		new_str[i] = trim_line[i];
		i ++;
	}
	new_str[i] = '\0';
	return (new_str);
}
*/


/************************MAP EXTENSION FUNCTION **************************/

/*
void	main_parsing_exists(char *av)
{
	void (av);

}*/