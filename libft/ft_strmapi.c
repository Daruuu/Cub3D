/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:49:34 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/13 22:51:16 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*s  The string on which to iterate.
(f) The function to apply to each character.*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	size_s;
	size_t	i;

	if (!s || !f)
		return (0);
	size_s = ft_strlen(s);
	ptr = malloc(sizeof(char) * (size_s + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size_s)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
