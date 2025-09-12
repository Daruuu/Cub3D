/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:00:00 by dasalaza          #+#    #+#             */
/*   Updated: 2025/09/11 22:00:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

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
