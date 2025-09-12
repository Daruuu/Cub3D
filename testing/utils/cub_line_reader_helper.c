/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_line_reader_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/09 00:46:44 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_line_reader.h"

int	init_file_reading(char *path, char **buf)
{
	int	file;

	*buf = malloc(1);
	if (!*buf)
		return (-1);
	(*buf)[0] = '\0';
	file = open(path, O_RDONLY);
	if (file == -1)
	{
		free(*buf);
		*buf = NULL;
		return (-1);
	}
	return (file);
}

int	process_character(char c, char **buf, int *size, t_line **first)
{
	if (c == '\n')
	{
		if (!add_line(first, *buf, *size))
			return (0);
		*buf = malloc(1);
		if (!*buf)
			return (0);
		(*buf)[0] = '\0';
		*size = 0;
	}
	else
	{
		*buf = ft_strcat(*buf, c, (*size)++);
		if (!*buf)
			return (0);
	}
	return (1);
}

int	finalize_reading(char *buf, t_line **first, int size)
{
	if (size > 0)
	{
		if (add_line(first, buf, size))
			return (1);
		return (free_ret(buf, first));
	}
	free(buf);
	return (1);
}
