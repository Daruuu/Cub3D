/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/12 01:32:58 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_file.h"

char	*ft_strcat(char *str, char c, int size)
{
	int		i;
	char	*new;

	new = malloc(size + 2);
	i = 0;
	while (i < size)
	{
		new[i] = str[i];
		++i;
	}
	new[i++] = c;
	new[i] = 0;
	free(str);
	return (new);
}

int	add_line(t_line **line, char *data, int size)
{
	t_line	*new;
	t_line	*temp;

	new = malloc(sizeof(t_line));
	if (!new)
		return (0);
	new->next = NULL;
	new->line = data;
	new->size = size;
	temp = *line;
	if (!temp)
		*line = new;
	while (temp)
	{
		if (!temp->next)
		{
			temp->next = new;
			break ;
		}
		temp = temp->next;
	}
	return (1);
}

void	free_file(t_line **first)
{
	t_line	*file;
	t_line	*next;

	file = *first;
	while (file)
	{
		next = file->next;
		if (file->line)
			free(file->line);
		free(file);
		file = next;
	}
	*first = NULL;
}

int	free_ret(char *buf, t_line **first)
{
	if (buf)
		free(buf);
	if (first)
		free_file(first);
	return (0);
}

/*
** Loads a file and creates a chained list of lines
** This is a mess... But too lazy to create another
** file for the 5 functions norm...........
*/

int	load_file(char *path, t_line **first, int size)
{
	int		file;
	char	*buf;
	int		read_bytes;
	char	c;

	file = init_file_reading(path, &buf);
	if (file == -1)
		return (0);
	read_bytes = read(file, &c, 1);
	while (read_bytes > 0)
	{
		if (c == 0)
			return (free_ret(buf, first));
		if (!process_character(c, &buf, &size, first))
			return (free_ret(buf, first));
		read_bytes = read(file, &c, 1);
	}
	close(file);
	if (read_bytes == -1)
		return (free_ret(buf, first));
	return (finalize_reading(buf, first, size));
}
