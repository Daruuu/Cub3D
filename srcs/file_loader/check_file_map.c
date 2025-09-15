/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:48:25 by anamedin          #+#    #+#             */
/*   Updated: 2025/09/11 23:44:40 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_file_map.h"

bool	check_iscub(char *file)
{
	int		len;

	len = stringlen(file);
	if (len < 4)
		return (false);
	return ((file[len - 1] == 'b' || file[len - 1] == 'B')
		&& (file[len - 2] == 'u' || file[len - 2] == 'U')
		&& (file[len - 3] == 'c' || file[len - 3] == 'C')
		&& file[len - 4] == '.');
}

void	*make_closedmap(int size)
{
	int		i;
	char	*new;

	new = (char *)malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
		new[i++] = 0;
	return (new);
}
