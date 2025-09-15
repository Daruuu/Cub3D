/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:18:55 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/12 01:52:34 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:47:33 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/12 00:03:42 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_file.h"

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
