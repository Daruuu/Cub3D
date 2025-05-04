/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:31:24 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/11 17:46:15 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen_const(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;

	if (!s1 && !s2)
		return (0);
	size_s1 = ft_strlen_const(s1);
	size_s2 = ft_strlen_const(s2);
	ptr = malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (size_s1 + size_s2))
	{
		if (i < size_s1)
			ptr[i] = s1[i];
		else
			ptr[i] = s2[i - size_s1];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
