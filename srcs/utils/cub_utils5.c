/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  yaramire < yaramire@student.42barcelon    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:33:46 by yamir             #+#    #+#             */
/*   Updated: 2025/05/28 20:04:23 by  yaramire        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utils.h"

double	ease_in_out(double t)
{
	float	sqt;

	sqt = t * t;
	return (sqt / (2.0f * (sqt - t) + 1.0f));
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

int	stringlen(char *string)
{
	int	len;

	len = 0;
	while (string[len])
		len++;
	return (len);
}

void	truncate_str(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	len--;
	while (len >= 0 && s[len] == ' ')
		s[len--] = 0;
}

int	bad_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		if (++i >= n)
			break ;
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
