/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:24:48 by dasalaza          #+#    #+#             */
/*   Updated: 2023/09/15 21:24:21 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* localiza un caracter dentro de un puntero char'
 * return un puntero a la 1ra ocurrencia del caracter c en el string s
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
