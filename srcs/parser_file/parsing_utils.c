/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:18:31 by dasalaza          #+#    #+#             */
/*   Updated: 2025/05/28 19:19:12 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_open_map(char *path)
{
	int	fd;

	if (!path)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
		// handle_exit(ERROR_OPEN_FILE);
	return (fd);
}

int	get_max_columns(char **map, int rows)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (i < rows && map[i])
	{
		len = (int) ft_strlen(map[i]);
		if (len > max)
			max = len;
		i ++;
	}
	return (max);
}

